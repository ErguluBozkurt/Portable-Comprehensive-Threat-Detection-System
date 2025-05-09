#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_MLX90640.h>
#include <Servo.h>
#include <PIR_Sensor.h>
#include <Radar_Sensor.h>
#include <Microphone.h>
#include <Adafruit_SSD1306.h>  // OLED ekran için kütüphane
#include <TinyGPS++.h>         // GPS için kütüphane

// Wi-Fi Bağlantı Bilgileri
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Sensör Pin Tanımlamaları
const int pirPin = 13;       // PIR sensörü pin
const int radarPin = 12;     // Radar sensörü pin
const int micPin = 14;       // Akustik sensör pin
const int motorPin = 27;     // Vibrasyon motoru veya LED ışık pin

// Diğer bileşenler
Adafruit_MLX90640 mlx;      // Termal kamera nesnesi
TinyGPSPlus gps;            // GPS nesnesi
Servo myservo;              // Servo motor nesnesi
Adafruit_SSD1306 display(128, 64, &Wire, -1);  // OLED ekran nesnesi

// GPS Modül Pinleri
const int rxPin = 16;
const int txPin = 17;

// Wi-Fi Bağlantısı
void setupWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Bağlantı bekleniyor...");
  }
  Serial.println("Wi-Fi Bağlantısı Başarılı!");
}

// Sensörlerin Başlatılması
void setupSensors() {
  pinMode(pirPin, INPUT);
  pinMode(radarPin, INPUT);
  pinMode(micPin, INPUT);
  pinMode(motorPin, OUTPUT);
  
  // Termal kamera başlatma
  if (!mlx.begin()) {
    Serial.println("Termal kamera başlatılamadı!");
    while (1);
  }

  // OLED ekran başlatma
  if (!display.begin(SSD1306_I2C_ADDRESS, -1)) {
    Serial.println("OLED ekran başlatılamadı!");
    while (1);
  }
  display.display();
  delay(2000);  // Ekranda başlatma logosu

  // Servo motoru başlat
  myservo.attach(15);
  
  // GPS modülünü başlat
  Serial1.begin(9600, SERIAL_8N1, rxPin, txPin);
}

void setup() {
  Serial.begin(115200);
  setupWiFi();
  setupSensors();
}

void loop() {
  // PIR sensöründen hareket verisini al
  int pirValue = digitalRead(pirPin);
  if (pirValue == HIGH) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Hareket Algılandi!");
    myservo.write(90);  // Servo motoru 90 derece döndür
    delay(500);
  }
  
  // Radar sensöründen veri al
  int radarValue = analogRead(radarPin);
  if (radarValue > 1000) {
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("Radar Tespiti!");
  }

  // Akustik sensörden ses algılama
  int micValue = analogRead(micPin);
  if (micValue > 500) {
    display.clearDisplay();
    display.setCursor(0, 20);
    display.println("Silah veya Patlama Algılandi!");
  }

  // Termal kameradan veri al
  float frame[32*24];
  mlx.getFrame(frame);

  // GPS Verisi
  while (Serial1.available() > 0) {
    gps.encode(Serial1.read());
    if (gps.location.isUpdated()) {
      display.clearDisplay();
      display.setCursor(0, 30);
      display.print("Konum: ");
      display.print(gps.location.lat(), 6);
      display.print(",");
      display.print(gps.location.lng(), 6);
    }
  }

  // Tehdit tespit edildiğinde motoru çalıştır
  if (pirValue == HIGH || radarValue > 1000 || micValue > 500) {
    digitalWrite(motorPin, HIGH);  // Motoru çalıştır
    delay(500);
    digitalWrite(motorPin, LOW);   // Motoru kapat
  }

  delay(1000);  // 1 saniye bekle
}
