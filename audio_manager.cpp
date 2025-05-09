#include "TCTT.h"

void readAudio() {
  static unsigned long lastTrigger = 0;
  int micValue = analogRead(micPin);
  
  if (micValue > AUDIO_THRESHOLD && millis() - lastTrigger > 3000) {
    lastTrigger = millis();
    String message = "Ses Algilandi: " + String(micValue);
    updateDisplay(message, 4);
    triggerAlarm();
  }
}
