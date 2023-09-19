#include <Blinker.h>
Blinker led(13);

void setup() {
  // мигнуть 5 раз, 700мс вкл, 400мс выкл
  led.blink(5, 700, 400);
}
void loop() {
  led.tick();
}