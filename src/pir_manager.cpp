#include "TCTT.h"

void readPIR() {
  static unsigned long lastTrigger = 0;
  int pirValue = digitalRead(pirPin);
  
  if (pirValue == HIGH && millis() - lastTrigger > 5000) {
    lastTrigger = millis();
    updateDisplay("Hareket Algilandi!", 3);
    myservo.write(90);
    triggerAlarm();
    
    // 2 saniye sonra servo eski konumuna dönsün
    delay(2000);
    myservo.write(0);
  }
}
