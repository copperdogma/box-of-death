#pragma once

#include <driver/gpio.h>

// TENSTAR ESP32-C3 SuperMini Plus pin map for the Box of Death.
// GPIO2/8/9 are strapping pins (8 also carries the onboard LEDs, 9 is BOOT) and
// GPIO20/21 are UART0, which chatters at reset; none of them drive anything here.
// GPIO0/1/3 are free and ADC-capable.
namespace box {

// Main button's dry contact: COM and NO between this pin and GND, internal pull-up.
constexpr gpio_num_t kButtonGpio = GPIO_NUM_10;

// MOSFET module signal inputs, active high.
constexpr gpio_num_t kLightStringGpios[] = {GPIO_NUM_5, GPIO_NUM_6, GPIO_NUM_7};
constexpr gpio_num_t kButtonLedGpio = GPIO_NUM_4;

constexpr gpio_num_t kOnboardLedGpio = GPIO_NUM_8; // Board status LEDs; not otherwise used.

} // namespace box
