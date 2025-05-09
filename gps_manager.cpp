#include "TCTT.h"

void updateGPS() {
  static unsigned long lastUpdate = 0;
  
  if (millis() - lastUpdate > 5000) {  // 5 saniyede bir güncelle
    lastUpdate = millis();
    
    while (SerialGPS.available() > 0) {
      if (gps.encode(SerialGPS.read())) {
        if (gps.location.isValid()) {
          String lat = String(gps.location.lat(), 6);
          String lng = String(gps.location.lng(), 6);
          String message = "GPS: " + lat + "," + lng;
          updateDisplay(message, 5);
        }
      }
    }
    
    if (millis() > 5000 && gps.charsProcessed() < 10) {
      updateDisplay("GPS Baglanamadi", 5);
    }
  }
}
