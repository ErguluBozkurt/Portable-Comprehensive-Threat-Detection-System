// Radar sensör yönetimi
int radarValue = analogRead(radarPin);  // Radar değerini oku
float radarDistance = map(radarValue, 0, 1023, 0, 500);  // Mesafeyi ölçmek için analog değeri mesafeye çevir

if (radarDistance < 10) {  // Eğer mesafe 10 cm'nin altındaysa tehdit algılandı
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("Radar: Tehdit Tespiti");
}
