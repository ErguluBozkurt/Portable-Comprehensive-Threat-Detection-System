#include "TCTT.h"

void readThermal() {
  static unsigned long lastReading = 0;
  
  if (millis() - lastReading > 2000) {  // 2 saniyede bir oku
    lastReading = millis();
    
    float frame[32*24];
    if (mlx.getFrame(frame) == 0) {  // Başarılı okuma
      for (int i = 0; i < 32*24; i++) {
        if (frame[i] > THERMAL_THRESHOLD) {
          String message = "Termal: " + String(frame[i], 1) + "C";
          updateDisplay(message, 1);
          triggerAlarm();
          break;
        }
      }
    }
  }
}
