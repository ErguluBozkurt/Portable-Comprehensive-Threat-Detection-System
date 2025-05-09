#include "TCTT.h"

void updateDisplay(const String& message, int line) {
  display.setCursor(0, line * 10);
  display.println(message);
  display.display();
}

void triggerAlarm() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(motorPin, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    delay(100);
  }
}
