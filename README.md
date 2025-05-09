# Taşınabilir Kapsamlı Tehdit Tespit Sistemi (TCTT)

## 📌 Proje Tanımı

TCTT, çevredeki fiziksel tehditleri algılayabilen taşınabilir bir güvenlik sistemidir. Çeşitli sensörlerle donatılmış olan sistem, askeri operasyonlar, güvenlik uygulamaları ve acil durum müdahaleleri için tasarlanmıştır.

## 🌟 Özellikler

- **Çoklu Sensör Entegrasyonu**: Hareket, ses, termal ve radar algılama
- **Gerçek Zamanlı Konum Takibi**: GPS modülü ile hassas konum bilgisi
- **Kablosuz İletişim**: Wi-Fi üzerinden veri aktarımı
- **Görsel Arayüz**: OLED ekranda durum bilgisi görüntüleme
- **Fiziksel Uyarı**: LED ile alarm

## 🛠 Donanım Bileşenleri

| Bileşen | Model | Miktar |
|---------|-------|--------|
| Ana Kontrolcü | ESP32-WROOM-32 | 1 |
| PIR Sensör | HC-SR501 | 1 |
| Radar Sensör | RCWL-0516 | 1 |
| Termal Kamera | MLX90640 | 1 |
| GPS Modülü | NEO-6M | 1 |
| OLED Ekran | SSD1306 128x64 | 1 |
| Servo Motor | SG90 | 1 |
 
## 📂 Yazılım Mimarisi 
```
TCTT/
├── include/
│ └── TCTT.h
├── src/
│ ├── main.cpp
│ ├── setup_functions.cpp
│ ├── pir_manager.cpp
│ ├── radar_manager.cpp
│ ├── audio_manager.cpp
│ ├── thermal_manager.cpp
│ ├── gps_manager.cpp
│ └── display_manager.cpp
├── platformio.ini
└── README.md

``` 
![mimari](https://github.com/user-attachments/assets/578af844-9e3d-407d-9332-73b01508d95c)


## 🔧 Kurulum

### Gereksinimler
- PlatformIO IDE (VSCode eklentisi)
- ESP32 USB Sürücüleri
- Arduino Framework

### Adım Adım Kurulum

1. Depoyu klonlayın:
   ```bash
   git clone https://github.com/ErguluBozkurt/Portable-Comprehensive-Threat-Detection-System.git
