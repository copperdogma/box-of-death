# Box of Death firmware

ESP-IDF 5.5.4 / ESP-Matter 1.5 prototype for the TENSTAR ESP32-C3 SuperMini Plus
(red board, 4 MB flash). The project layout, partition table, development
credentials and build flow follow the SkyBox firmware in `lightbox-sky`.

The box is a Matter **generic switch**: it reports that the main button was
pressed and released. What a press does to Death is decided on the Matter
fabric, not here. Skeleton control, sound and motion stay in their own projects.

## Matter endpoint

| Endpoint | Device type | Behaviour |
| --- | --- | --- |
| 1 | Generic switch, momentary, two positions | `InitialPress` on the way down, `ShortRelease` on the way up; `CurrentPosition` follows the button |

Long-press and multi-press are not enabled.

## GPIO map

| Function | GPIO | Notes |
| --- | --- | --- |
| Main button switch | GPIO10 | `COM` and `NO` between the pin and GND; internal pull-up, pressed reads low |
| Light string 1 MOSFET signal | GPIO5 | Active high |
| Light string 2 MOSFET signal | GPIO6 | Active high |
| Light string 3 MOSFET signal | GPIO7 | Active high |
| Button LED MOSFET signal | GPIO4 | Active high |
| Onboard LEDs | GPIO8 | Quieted at boot; not otherwise used |

Free: GPIO0, GPIO1, GPIO3 (ADC-capable). Avoid GPIO2/8/9 (strapping pins; GPIO9
is also BOOT) and GPIO20/21 (UART0, chatters at reset).

Every MOSFET module's signal ground and the load supply's ground must share the
ESP32's GND. Do not join the positive rails. The four outputs float between
reset and `box_show::init()`; if a light blinks at power-up, add a 10k pull-down
on that signal line.

The pin map lives in [`main/box_pins.h`](main/box_pins.h).

## Where the show code goes

[`main/box_show.cpp`](main/box_show.cpp) is the place for the lights and button
lamp. `app_main.cpp` owns Matter and the debounced button and calls:

- `box_show::init()` at boot, which drives all four outputs low
- `box_show::on_press()` and `box_show::on_release()` after Matter has been told
- `box_show::tick(now_ms)` every 10 ms

Current behaviour: `tick()` chases the three light strings with one lit at a time,
advancing every 500 ms, and holds the button LED on. The original chase was
restored October 27, 2026 after the builder disliked the two-at-a-time trial.
As a switch test, a press turns the button LED
off for 2 seconds. `on_release()` is empty. The hooks run on the Matter thread and must not block.

## Build and flash

```sh
cd firmware
source /Users/cam/esp/esp-idf-v5.5.4/export.sh
idf.py build
idf.py -p /dev/cu.usbmodem101 app-flash
idf.py -p /dev/cu.usbmodem101 monitor
```

A fresh checkout with no `sdkconfig` needs `idf.py set-target esp32c3` once
before the first build. A blank board needs a full `idf.py flash` once for the
bootloader and partition table; use `app-flash` afterwards so the pairing data
in NVS survives. This partition layout has no OTA application slot.

The console is on USB-Serial-JTAG, so `monitor` works over the flashing cable.

## Commissioning

Development credentials only (Espressif test vendor `0xFFF1`, product `0x8000`).
Setup code `34970112332`; QR payload `MT:Y.K9042C00KA0648G00`. These are the same
test values SkyBox uses, so pair one uncommissioned device at a time. An
uncommissioned boot opens a 15-minute pairing window; restart the board if it
expires.

## Status (2026-10-10)

Built (1,504,416 bytes; 62% of the app partition free) and flashed to the
ESP32-C3 with MAC `8c:d0:b2:a8:b5:78`. Serial confirmed endpoint 1 created,
zero fabrics, and BLE commissioning advertising.

Later the same day, on the bench: the builder commissioned it, serial showed
debounced presses and releases, and the builder reported the three strings
chasing, the button LED responding, and an Apple Home automation driving another
accessory from a press. One MOSFET module on the button-LED channel was faulty
(steady 2 V at its output, and it hung the ESP32 when its signal pin was
connected); replacing it fixed both. Not yet done: any test in the box on
battery power.

That board previously ran an early SkyBox prototype build with two Matter
fabrics. Its NVS was erased so the box starts unpaired. A full 4 MB image of the
earlier contents is kept outside Git in `.local/board-backup/`; it holds Wi-Fi
and fabric credentials. Any accessory the old build left in a Home app is stale
and can be removed there.

## Chase update (2026-10-24)

Changed the chase from one lit string to two lit strings, keeping the 500 ms
step interval and button-lamp behavior. Built successfully and app-flashed to
the same ESP32-C3 (`8c:d0:b2:a8:b5:78`); esptool verified the written image hash.
Only the application partition was written, preserving NVS pairing data.
On October 27, the builder reported that two at a time did not look great and
selected a return to the original one-at-a-time chase.

## Chase restored (2026-10-27)

Restored one lit string at a time with the original 500 ms step interval.
Build succeeded; app-flashed to ESP32-C3 `8c:d0:b2:a8:b5:78`, with the written
image hash verified by esptool. NVS pairing data was preserved. Button-lamp
behavior is unchanged. The builder confirmed the restored chase looks much better.
