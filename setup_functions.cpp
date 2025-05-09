#include "TCTT.h"

void setupWiFi() {
  WiFi.begin(ssid, password); // wifi bilgileri girilmeli
  
  updateDisplay("Wi-Fi Baglaniyor...", 0);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    updateDisplay("Wi-Fi Baglandi", 0);
    updateDisplay(WiFi.localIP().toString(), 1);
  } else {
    updateDisplay("Wi-Fi Baglanamadi", 0);
  }
  delay(2000);
}

void setupSensors() {
  // Pin Modları
  pinMode(pirPin, INPUT);
  pinMode(radarPin, INPUT);
  pinMode(micPin, INPUT);
  pinMode(motorPin, OUTPUT);
  
  // Servo Motor
  myservo.attach(servoPin);
  myservo.write(0);
  
  // OLED Ekran
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED baslatilamadi!");
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  // Termal Kamera
  if (!mlx.begin(MLX90640_I2CADDR_DEFAULT, &Wire)) {
    Serial.println("Termal kamera baslatilamadi!");
    updateDisplay("Termal Kamera Hata", 2);
  } else {
    mlx.setMode(MLX90640_INTERLEAVED);
    mlx.setResolution(MLX90640_ADC_18BIT);
  }
  
  // GPS
  SerialGPS.begin(9600, SERIAL_8N1, rxPin, txPin);
}
