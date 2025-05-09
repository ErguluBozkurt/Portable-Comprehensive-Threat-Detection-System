#include "TCTT.h"

// Global Nesneler
Adafruit_MLX90640 mlx;
TinyGPSPlus gps;
Servo myservo;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
HardwareSerial SerialGPS(1); // ESP32'de HardwareSerial

void setup() {
  Serial.begin(115200);
  while (!Serial); // Serial monitor bağlantısı için bekle
  
  setupWiFi();
  setupSensors();
  
  updateDisplay("Sistem Baslatiliyor", 0);
  delay(2000);
  updateDisplay("Hazir", 0);
}

void loop() {
  readPIR();
  readRadar();
  readAudio();
  readThermal();
  updateGPS();
  
  delay(100);
}
