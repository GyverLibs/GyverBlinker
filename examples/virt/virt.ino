#include <Blinker.h>
VirtBlinker blink;

void setup() {
  Serial.begin(115200);
  // мигнуть 5 раз, 700мс вкл, 400мс выкл
  blink.blink(5, 700, 400);
}
void loop() {
  if (blink.tick()) Serial.println(blink.state());
}