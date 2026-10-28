#include <cstdint>

#include <app/server/Server.h>
#include <driver/gpio.h>
#include <esp_err.h>
#include <esp_log.h>
#include <esp_matter.h>
#include <esp_system.h>
#include <esp_timer.h>
#include <led_strip.h>
#include <led_strip_rmt.h>
#include <nvs_flash.h>

#include "box_pins.h"
#include "box_show.h"

namespace {

using namespace chip::app::Clusters;
using namespace esp_matter;

constexpr char kTag[] = "box_of_death";
constexpr int kDebounceTicks = 3; // Consecutive matching samples, box_show::kTickMs apart.

// Switch cluster positions for a two-position momentary switch.
constexpr uint8_t kPositionReleased = 0;
constexpr uint8_t kPositionPressed = 1;

uint16_t g_button_endpoint = 0;

// The Plus board puts a WS2812B *and* a plain blue LED on GPIO8. With nothing
// driving the pin the WS2812B latches whatever noise it picks up, which is the
// blue-then-bright-white behaviour. Clock one all-zero frame into it, then hand
// the pin back as a pulled-up input, which also leaves the plain LED (active
// low here) dark.
void quiet_onboard_led()
{
    led_strip_config_t strip_config{};
    strip_config.strip_gpio_num = box::kOnboardLedGpio;
    strip_config.max_leds = 2; // Covers 3-byte and 4-byte pixel formats alike.
    strip_config.led_model = LED_MODEL_SK6812;
    strip_config.color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRBW;

    led_strip_rmt_config_t rmt_config{};
    rmt_config.clk_src = RMT_CLK_SRC_DEFAULT;
    rmt_config.resolution_hz = 10 * 1000 * 1000;
    rmt_config.mem_block_symbols = 64;
    rmt_config.flags.with_dma = false;

    led_strip_handle_t onboard = nullptr;
    if (led_strip_new_rmt_device(&strip_config, &rmt_config, &onboard) != ESP_OK) return;
    led_strip_clear(onboard);
    led_strip_del(onboard);

    gpio_config_t idle{};
    idle.pin_bit_mask = 1ULL << box::kOnboardLedGpio;
    idle.mode = GPIO_MODE_INPUT;
    idle.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&idle);
}

void set_switch_position(uint8_t position)
{
    auto value = esp_matter_uint8(position);
    ESP_ERROR_CHECK(attribute::update(g_button_endpoint, Switch::Id,
        Switch::Attributes::CurrentPosition::Id, &value));
}

// Runs on the Matter thread, so cluster events can be sent directly.
void button_tick(chip::System::Layer *layer, void *)
{
    static bool candidate = false, pressed = false;
    static int stable_ticks = 0;
    const bool sample = gpio_get_level(box::kButtonGpio) == 0;
    if (sample != candidate) {
        candidate = sample;
        stable_ticks = 0;
        // Raw, pre-debounce view of the pin for checking the wiring.
        ESP_LOGI(kTag, "GPIO%d raw level: %s", static_cast<int>(box::kButtonGpio),
                 sample ? "LOW (contact closed to GND)" : "HIGH (open)");
    }
    else if (stable_ticks < kDebounceTicks) { ++stable_ticks; }
    if (stable_ticks == kDebounceTicks && candidate != pressed) {
        pressed = candidate;
        if (pressed) {
            set_switch_position(kPositionPressed);
            cluster::switch_cluster::event::send_initial_press(g_button_endpoint, kPositionPressed);
            ESP_LOGI(kTag, "Button pressed");
            box_show::on_press();
        } else {
            set_switch_position(kPositionReleased);
            cluster::switch_cluster::event::send_short_release(g_button_endpoint, kPositionPressed);
            ESP_LOGI(kTag, "Button released");
            box_show::on_release();
        }
    }
    box_show::tick(esp_timer_get_time() / 1000);
    layer->StartTimer(chip::System::Clock::Milliseconds32(box_show::kTickMs), button_tick, nullptr);
}

esp_err_t attribute_update_cb(attribute::callback_type_t, uint16_t, uint32_t, uint32_t,
                              esp_matter_attr_val_t *, void *)
{
    return ESP_OK;
}

esp_err_t identification_cb(identification::callback_type_t type, uint16_t endpoint_id,
                            uint8_t, uint8_t, void *)
{
    ESP_LOGI(kTag, "Identify event: endpoint=%u type=%u", endpoint_id, type);
    return ESP_OK;
}

void app_event_cb(const chip::DeviceLayer::ChipDeviceEvent *event, intptr_t)
{
    switch (event->Type) {
    case chip::DeviceLayer::DeviceEventType::kCommissioningComplete:
        ESP_LOGI(kTag, "Matter commissioning complete");
        break;
    case chip::DeviceLayer::DeviceEventType::kBLEDeinitialized:
        ESP_LOGI(kTag, "BLE released; free heap: %lu bytes",
                 static_cast<unsigned long>(esp_get_free_heap_size()));
        break;
    case chip::DeviceLayer::DeviceEventType::kWiFiConnectivityChange:
        if (event->WiFiConnectivityChange.Result == chip::DeviceLayer::kConnectivity_Established) {
            ESP_LOGI(kTag, "Wi-Fi connected");
        } else if (event->WiFiConnectivityChange.Result == chip::DeviceLayer::kConnectivity_Lost) {
            ESP_LOGW(kTag, "Wi-Fi lost");
        }
        break;
    default:
        break;
    }
}

} // namespace

extern "C" void app_main()
{
    // First, so the MOSFET inputs stop floating as early as possible.
    box_show::init();

    esp_err_t nvs_error = nvs_flash_init();
    // Never silently erase commissioned fabric credentials on an NVS error.
    ESP_ERROR_CHECK(nvs_error);

    ESP_LOGI(kTag, "Box of Death 0.1.0 starting on ESP32-C3; free heap: %lu bytes",
             static_cast<unsigned long>(esp_get_free_heap_size()));
    quiet_onboard_led();

    node::config_t node_config{};
    node_t *node = node::create(&node_config, attribute_update_cb, identification_cb);
    ESP_ERROR_CHECK(node == nullptr ? ESP_FAIL : ESP_OK);

    // One momentary generic switch: InitialPress on the way down, ShortRelease
    // on the way up. What a press *does* to Death is decided on the fabric.
    endpoint::generic_switch::config_t button_config{};
    button_config.switch_cluster.number_of_positions = 2;
    button_config.switch_cluster.current_position = kPositionReleased;
    button_config.switch_cluster.feature_flags =
        cluster::switch_cluster::feature::momentary_switch::get_id() |
        cluster::switch_cluster::feature::momentary_switch_release::get_id();
    endpoint_t *button = endpoint::generic_switch::create(
        node, &button_config, ENDPOINT_FLAG_NONE, nullptr);
    ESP_ERROR_CHECK(button == nullptr ? ESP_FAIL : ESP_OK);
    g_button_endpoint = endpoint::get_id(button);
    ESP_LOGI(kTag, "Button endpoint %u created", g_button_endpoint);

    ESP_ERROR_CHECK(esp_matter::start(app_event_cb));

    gpio_config_t button_gpio{};
    button_gpio.pin_bit_mask = 1ULL << box::kButtonGpio;
    button_gpio.mode = GPIO_MODE_INPUT;
    button_gpio.pull_up_en = GPIO_PULLUP_ENABLE;
    ESP_ERROR_CHECK(gpio_config(&button_gpio));
    chip::DeviceLayer::SystemLayer().ScheduleLambda([]() {
        chip::DeviceLayer::SystemLayer().StartTimer(
            chip::System::Clock::Milliseconds32(box_show::kTickMs), button_tick, nullptr);
    });
    ESP_LOGI(kTag, "Button on GPIO%d reads %s at boot", static_cast<int>(box::kButtonGpio),
             gpio_get_level(box::kButtonGpio) == 0 ? "LOW (pressed or shorted to GND)" : "HIGH (open)");
    ESP_LOGI(kTag, "Matter started; fabrics=%u; free heap=%lu bytes",
             chip::Server::GetInstance().GetFabricTable().FabricCount(),
             static_cast<unsigned long>(esp_get_free_heap_size()));
}
