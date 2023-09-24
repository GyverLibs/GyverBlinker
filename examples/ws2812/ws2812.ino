// пример создания своего класса на базе VirtBlinker
// например для мигания адресными ледами

#include <FastLED.h>
#include "wsBlinker.h"

#define LED_PIN     5
#define NUM_LEDS    10
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

wsBlinker led0(&leds[0], CRGB::Red);
wsBlinker led1(&leds[1], CRGB::Blue);

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(255);
  led0.blink(3, 500, 1000);
  led1.blink(10, 300, 300);
}

void loop() {
  led0.tick();
  led1.tick();
}