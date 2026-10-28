#include "box_show.h"

#include <cstddef>

#include <esp_err.h>
#include <esp_log.h>

#include "box_pins.h"

namespace box_show {

namespace {

constexpr char kTag[] = "box_show";
constexpr int64_t kChaseStepMs = 500;
constexpr int64_t kPressBlankMs = 2000; // Switch test: button lamp goes dark this long after a press.

bool g_press_pending = false;

void set_output(gpio_num_t pin, bool on)
{
    gpio_set_level(pin, on ? 1 : 0);
}

} // namespace

void init()
{
    uint64_t mask = 1ULL << box::kButtonLedGpio;
    for (auto pin : box::kLightStringGpios) mask |= 1ULL << pin;

    // Latch low before enabling the drivers so nothing blips on.
    for (auto pin : box::kLightStringGpios) set_output(pin, false);
    set_output(box::kButtonLedGpio, false);

    gpio_config_t outputs{};
    outputs.pin_bit_mask = mask;
    outputs.mode = GPIO_MODE_INPUT_OUTPUT; // Input stays enabled so the pin level can be read back.
    ESP_ERROR_CHECK(gpio_config(&outputs));
    ESP_LOGI(kTag, "Light strings on GPIO5/6/7 and button LED on GPIO4, all off");
}

// ---------------------------------------------------------------------------
// Show code goes below.
// ---------------------------------------------------------------------------

void on_press()
{
    g_press_pending = true;
}

void on_release()
{
}

// Idle marquee: one string lit at a time, stepping the lit string every
// kChaseStepMs, with the button lamp on except for kPressBlankMs after each press.
void tick(int64_t now_ms)
{
    static int64_t lamp_dark_until = 0;
    if (g_press_pending) {
        g_press_pending = false;
        lamp_dark_until = now_ms + kPressBlankMs;
    }
    static int lamp_state = -1;
    const bool lamp_on = now_ms >= lamp_dark_until;
    set_output(box::kButtonLedGpio, lamp_on);
    if (static_cast<int>(lamp_on) != lamp_state) {
        lamp_state = lamp_on;
        ESP_LOGI(kTag, "Button LED GPIO%d driven %s; pin reads %d", static_cast<int>(box::kButtonLedGpio),
                 lamp_on ? "HIGH (on)" : "LOW (off)", gpio_get_level(box::kButtonLedGpio));
    }

    constexpr size_t kStringCount = sizeof(box::kLightStringGpios) / sizeof(box::kLightStringGpios[0]);
    static int lit = -1;

    const int step = static_cast<int>((now_ms / kChaseStepMs) % kStringCount);
    if (step == lit) return;
    lit = step;
    for (size_t index = 0; index < kStringCount; ++index) {
        set_output(box::kLightStringGpios[index], static_cast<int>(index) == lit);
    }
}

} // namespace box_show
