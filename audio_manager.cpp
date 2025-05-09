// Akustik sensör verisi
int micValue = analogRead(micPin);  // Mikrofonun analog değerini oku

// Ses seviyesi yüksekse, tehdit olabilir
if (micValue > 500) {
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("Akustik: Tehdit Tespiti");
}
