#include <Arduino.h>
#ifdef USE_GDBSTUB
#include <gdbstub.h>
#endif

void setup();
void loop();

static unsigned long period = 200;
static uint8_t pin = 12;

void setup() {
#ifdef USE_GDBSTUB
  gdbstub_init();
#else
  Serial.begin(115200);
  Serial.println("setup");
#endif
  for (uint8_t p = 12; p <= 15; p++)
  {
    pinMode(p, OUTPUT);
  }
}

void loop() {
#ifdef USE_GDBSTUB
  // nothing to do in this case
#else
  Serial.println("loop");
#endif
  digitalWrite(pin, HIGH);
  delay(period);
  pin = pin > 15 ? 12 : pin + 1;
  digitalWrite(pin, LOW);
  delay(period);
}


