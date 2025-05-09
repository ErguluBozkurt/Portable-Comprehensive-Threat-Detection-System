#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Ekran Başlatılamadı"));
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Savunma Sistemi Aktif");
  
  // Sensörlerden alınan verileri ekranda göster
  display.setCursor(0, 20);
  display.print("Radar Mesafesi: ");
  display.print(radarDistance);
  display.println(" cm");

  display.setCursor(0, 30);
  display.print("Akustik: ");
  display.println(micValue > 500 ? "Tehdit" : "Normal");

  display.display();
  delay(1000);
}
