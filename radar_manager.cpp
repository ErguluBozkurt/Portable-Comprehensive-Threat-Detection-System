#include "TCTT.h"

void readRadar() {
  static unsigned long lastTrigger = 0;
  int radarValue = analogRead(radarPin);
  
  if (radarValue > RADAR_THRESHOLD && millis() - lastTrigger > 3000) {
    lastTrigger = millis();
    String message = "Radar: " + String(radarValue);
    updateDisplay(message, 2);
    triggerAlarm();
  }
}
