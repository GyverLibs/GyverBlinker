#pragma once
#include <FastLED.h>
#include "VirtBlinker.h"

class wsBlinker : public VirtBlinker {
  public:
    wsBlinker(CRGB* led, CRGB color = 0) : _led(led), _color(color) {}

    void setColor(CRGB color) {
      _color = color;
    }

    bool tick() {
      if (VirtBlinker::tick()) {
        *_led = VirtBlinker::state() ? _color : 0;
        FastLED.show();
        return 1;
      }
      return 0;
    }

  private:
    CRGB* _led;
    CRGB _color = 0;
};