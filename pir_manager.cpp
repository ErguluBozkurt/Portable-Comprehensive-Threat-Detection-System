// PIR sensöründen hareket algılama
int pirValue = digitalRead(pirPin);  // PIR sensöründen gelen dijital değer

if (pirValue == HIGH) {  // Hareket algılandıysa
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Hareket Algilandi!");
  myservo.write(90);  // Servo motoru 90 derece döndür
  delay(500);  // Hareket algılandıktan sonra kısa bir süre bekle
}
