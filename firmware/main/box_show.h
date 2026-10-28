#pragma once

#include <cstdint>

// The box's own behaviour: marquee light strings and the button lamp.
// app_main.cpp owns Matter and the debounced button and calls in here, so the
// show can change without touching the Matter side.
//
// on_press(), on_release() and tick() run on the Matter thread. Keep them
// short and non-blocking; anything timed belongs in tick().
namespace box_show {

// Claims the four MOSFET signal pins and drives them low. Called first thing at
// boot so the lights spend as little time as possible on floating inputs.
void init();

// The debounced button went down / came back up. Matter has already been told.
void on_press();
void on_release();

// Called every kTickMs with milliseconds since boot.
constexpr uint32_t kTickMs = 10;
void tick(int64_t now_ms);

} // namespace box_show
