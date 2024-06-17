#pragma once
#include <Arduino.h>

#define BLINK_FOREVER 0xff

class VirtBlinker {
   public:
    // начать мигание (количество, период вкл, период выкл)
    void blink(uint8_t amount, uint16_t high, uint16_t low = 0) {
        _state = 0;
        _high = high;
        _low = low;
        _count = amount;
        _tmr = (uint16_t)((uint16_t)millis() - _low);  // force
    }

    // мигать бесконечно
    void blinkForever(uint16_t high, uint16_t low = 0) {
        blink(BLINK_FOREVER, high, low);
    }

    // спровоцировать вызов ready
    void force() {
        _ready = true;
    }

    // остановить мигание. Не спровоцирует вызов ready
    void stop() {
        _count = 0;
        _ready = _state = 0;
    }

    // статус выхода
    bool state() {
        return _state;
    }

    // однократно вернёт true, когда мигание закончится
    bool ready() {
        return _ready ? (_ready = 0, true) : false;
    }

    // возвращает true, пока система мигает
    bool running() {
        return _count;
    }

    // получить количество оставшихся миганий
    uint8_t getCountLeft() {
        return _count;
    }

    // получить остаток до следующего переключения в мс
    uint16_t getLeft() {
        return _count ? (_getPrd() - _getTime()) : 0;
    }

    // получить остаток до следующего переключения в диапазоне 0-255
    uint8_t getLeft8() {
        return _getPrd() ? (255ul * getLeft() / _getPrd()) : 0;
    }

    // тикер, вызывать в loop. Однократно вернёт true при переключении состояния
    bool tick() {
        if (_count && _getTime() >= _getPrd()) {
            _tmr += _getPrd();
            _state = !_state;
            if (!_state && _count != BLINK_FOREVER) _count--;
            if (!_count) _ready = true;
            return 1;
        }
        return 0;
    }

   private:
    uint16_t _tmr = 0, _high = 1, _low = 1;

    inline uint16_t _getPrd() {
        return _state ? _high : _low;
    }
    inline uint16_t _getTime() {
        return (uint16_t)((uint16_t)millis() - _tmr);
    }

   protected:
    bool _state = 0;
    bool _ready = 0;
    uint8_t _count = 0;
};