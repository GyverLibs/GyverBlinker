#pragma once

#include <Arduino.h>

#include "VirtBlinker.h"

class Blinker : public VirtBlinker {
   public:
    // using VirtBlinker::blink;
    // using VirtBlinker::force;
    // using VirtBlinker::state;
    // using VirtBlinker::running;
    // using VirtBlinker::ready;
    // using VirtBlinker::getLeft;
    // using VirtBlinker::getLeft8;

    Blinker() {}

    // указать пин
    Blinker(uint8_t pin) {
        init(pin);
    }

    // указать пин
    void init(uint8_t pin) {
        _pin = pin;
        pinMode(_pin, OUTPUT);
    }

    // инвертировать выход
    void invert(bool inv) {
        _inv = inv;
    }

    // остановить мигание
    void stop() {
        VirtBlinker::stop();
        _write(0);
    }

    // тикер, вызывать в loop. Вернёт true при переключении состояния
    bool tick() {
        if (VirtBlinker::tick()) {
            _write(state());
            return 1;
        }
        return 0;
    }

   protected:
    void _write(bool v) {
        digitalWrite(_pin, v ^ _inv);
    }
    using VirtBlinker::stop;
    using VirtBlinker::tick;
    uint8_t _pin;

   private:
    bool _inv = 0;
};