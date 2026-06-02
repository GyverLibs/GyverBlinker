This is an automatic translation and may be incorrect in some places. See the source README and examples for authoritative information.

[![latest](https://img.shields.io/github/v/release/GyverLibs/GyverBlinker.svg?color=brightgreen)](https://github.com/GyverLibs/GyverBlinker/releases/latest/download/GyverBlinker.zip)
[![PIO](https://badges.registry.platformio.org/packages/gyverlibs/library/GyverBlinker.svg)](https://registry.platformio.org/libraries/gyverlibs/GyverBlinker)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD%24%E2%82%AC%20%D0%9F%D0%BE%D0%B4%D0%B4%D0%B5%D1%80%D0%B6%D0%B0%D1%82%D1%8C-%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/GyverBlinker?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# GyverBlinker
Timer with counter for flashing LED and other tasks
- In simple words: the library allows you to blink asynchronously LED several times
- Asynchronous operation
- Setting the number of positives
- Establishing active and passive time
- Two tools: VirtBlinker without pin binding and Blinker with pin indication

### Compatibility
All Arduino.

## Contents
- [Installation](#install)
- [Use of use](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found under the name **GyverBlinker** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download the library](https://github.com/GyverLibs/GyverBlinker/archive/refs/heads/main.zip).zip archive for manual installation:
    - Unpack and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unpack and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/ *
    - (Arduino IDE) Automatic installation from .zip: *Sketch/Connect library/Add .ZIP library...* and specify downloaded archive
- Read more detailed instructions for installing libraries[here](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: new versions fix errors and bugs, as well as optimize and add new features.
- Through the library manager IDE: find the library as when installing and click "Update"
- Manually: **Delete the folder with the old version** and then put the new one in its place. “Replacement” can not be done: sometimes new versions delete files that will remain when replaced and can lead to errors!

<a id="usage"></a>

## Use of use
### VirtBlinker
```cpp
// designer
Blinker();
Blinker(uint8_t pin);

// start blinking (number, period on, period off)
void blink(int8_t amount, uint16_t high, uint16_t low = 0);

// flashing
void blinkForever(uint16_t high, uint16_t low = 0);

void force();           // Provoke the call ready (last pancake)
void stop();            // stop blinking. It will not provoke a challenge ready.
bool state();           // exit
bool ready();           // It will return true once the blinking is over.
bool running();         // returns true while the system blinks
uint16_t getLeft();     // Receive the remainder before the next switch to MS
uint8_t getLeft8();     // get the remainder until the next switch in the range 0-255
uint8_t getCountLeft(); // get the number of remaining flashes

bool tick();            // ticker, call the loop. Once return true when switching state
```

### Blinker
```cpp
void init(uint8_t pin); // pin
void invert(bool inv);  // invert
// Inherit all functions from VirtBlinker
```

<a id="example"></a>

## Example
### Real.
```cpp
#include <Blinker.h>
Blinker led(13);

void setup() {
  // blink 5 times, 700ms on, 400ms off
  led.blink(5, 700, 400);
}
void loop() {
  led.tick();
}
```

### Virtual
```cpp
#include <Blinker.h>
VirtBlinker blink;

void setup() {
  Serial.begin(115200);
  // blink 5 times, 700ms on, 400ms off
  blink.blink(5, 700, 400);
}
void loop() {
  if (blink.tick()) Serial.println(blink.state());
}
```

<a id="versions"></a>
## Versions
- v1.0
- v1.1.0 - added blinkForever

<a id="feedback"></a>
## Bugs and feedback
If you find bugs, create **Issue**, or better write to the mail immediately.[alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
The library is open for revision and your **Pull Requests*!

When reporting bugs or incorrect work of the library, it is necessary to specify:
- Library version
- What is used by the IC
- SDK version (for ESP)
- Arduino IDE version
- Are embedded examples that use features and designs that cause bugs in your code working correctly?
- What code was downloaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed. Not a canvas of a thousand lines, but a minimum code.
