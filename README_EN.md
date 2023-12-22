This is an automatic translation, may be incorrect in some places. See sources and examples!

# Gyverblinker
Timer with a counter for blinking an LED and other tasks
- in simple words: the library allows you to flash asynchronously with an LED several times
- Asynchronous work
- Installation of the number of operations
- installation of active and passive time
- Two tools: Virtblinker without binding to Pina and Blinker indicating the PIN

## compatibility
All arduino

## Content
- [installation] (# Install)
- [use] (#usage)
- [Example] (# Example)
- [versions] (#varsions)
- [bugs and feedback] (#fedback)

<a id="install"> </a>
## Installation
- The library can be found by the name ** gyverblinker ** and installed through the library manager in:
    - Arduino ide
    - Arduino ide v2
    - Platformio
- [download the library] (https://github.com/gyverlibs/gyverblinker/archive/refs/heads/main.zip). Zip archive for manual installation:
    - unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
    - unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
    - unpack and put in *documents/arduino/libraries/ *
    - (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!

<a id="usage"> </a>

## Usage
### Virtblinker
`` `CPP
// Designer
BLINker ();
Blinker (Uint8_T PIN);

// Start flashing (quantity, period of vn, period off)
VOID BLINK (int amount, uint16_t high, uint16_t low = 0);

VOID form ();// provoke a call reign
VOID Stop ();// Stop flashing.Will not provoke a call
Bool state ();// Exit status
Bool Ready ();// will return True once when the blinking ends
Bool Running ();// returns True while the system flashes
uint16_t getleft ();// get the rest until the next switch to ms
uint8_t getleft8 ();// get the rest until the next switch in the range 0-255
Bool Tick ();// ticker, call in LOOP.True will return once when switching the condition
`` `

## bud
`` `CPP
VOID Init (Uint8_T PIN);// Indicate the pin
VOID Invert (Bool Inv);// Invert the output
// + inherits all functions from Virtblinker
`` `

<a id="EXAMPLE"> </a>

## Example
## Real
`` `CPP
#include <blinker.h>
Blinker LED (13);

VOID setup () {
  // to blink 5 times, 700ms VKL, 400MS off
  led.blink (5, 700, 400);
}
VOID loop () {
  led.tick ();
}
`` `

## virtual
`` `CPP
#include <blinker.h>
Virtblinker Blink;

VOID setup () {
  Serial.Begin (115200);
  // to blink 5 times, 700ms VKL, 400MS off
  Blink.blink (5, 700, 400);
}
VOID LOop () {
  if (blink.tick ()) serial.println (blink.state ());
}
`` `

<a id="versions"> </a>
## versions
- V1.0

<a id="feedback"> </a>
## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!

When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- whether the built -in examples work correctly, in which the functions and designs are used, leading to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code