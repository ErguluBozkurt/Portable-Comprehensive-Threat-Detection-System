// Termal kamera verilerini işleme
float frame[32*24];
mlx.getFrame(frame);  // Termal kamera verisini al

// Termal veriyi analiz et
float threshold = 25.0;  // Sıcaklık eşiği, örneğin 25°C

for (int i = 0; i < 32*24; i++) {
  if (frame[i] > threshold) {
    display.clearDisplay();
    display.setCursor(0, 30);
    display.println("Termal: Sıcaklık Anomalisi!");
    break;  // Termal anomali algılandığında döngüyü durdur
  }
}
