#pragma once

#include <Arduino.h>

class VirtBlinker {
   public:
    // начать мигание (количество, период вкл, период выкл)
    void blink(int amount, uint16_t high, uint16_t low = 0) {
        _state = 0;
        _high = high;
        _low = low;
        _count = amount;
        _tmr = (uint16_t)((uint16_t)millis() - _low);
    }

    // спровоцировать вызов ready
    void force() {
        _count = -1;
    }

    // остановить мигание. Не спровоцирует вызов ready
    void stop() {
        _count = -2;
        _state = 0;
    }

    // статус выхода
    bool state() {
        return _state;
    }

    // однократно вернёт true, когда мигание закончится
    bool ready() {
        return (_count == -1) ? (_count = -2, true) : false;
    }

    // возвращает true, пока система мигает
    bool running() {
        return _count > -2;
    }

    // получить остаток до следующего переключения в мс
    uint16_t getLeft() {
        return (_count >= 0) ? ((_state ? _high : _low) - (uint16_t)((uint16_t)millis() - _tmr)) : 0;
    }

    // получить остаток до следующего переключения в диапазоне 0-255
    uint8_t getLeft8() {
        return 255ul * getLeft() / (_state ? _high : _low);
    }

    // тикер, вызывать в loop. Однократно вернёт true при переключении состояния
    bool tick() {
        if (_count >= 0 && (uint16_t)((uint16_t)millis() - _tmr) >= (_state ? _high : _low)) {
            _tmr = millis();
            if (_count > 0) _state = !_state;
            if (!_state) _count--;
            if (_count >= 0) return 1;
        }
        return 0;
    }

   protected:
    bool _state = 0;
    int8_t _count = -2;

   private:
    uint16_t _tmr, _high, _low;
};