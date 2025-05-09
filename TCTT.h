#ifndef TCTT_H
#define TCTT_H

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_MLX90640.h>
#include <Servo.h>
#include <Adafruit_SSD1306.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

// Wi-Fi Bilgileri
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Sensör Pinleri
const int pirPin = 13;
const int radarPin = 34;    // ESP32'de analog giriş
const int micPin = 35;      // ESP32'de analog giriş
const int motorPin = 27;
const int servoPin = 15;
const int rxPin = 16;
const int txPin = 17;

// Eşik Değerleri
const int RADAR_THRESHOLD = 1500;  // Analog değer
const int AUDIO_THRESHOLD = 500;
const float THERMAL_THRESHOLD = 25.0;

// Global Nesneler
extern Adafruit_MLX90640 mlx;
extern TinyGPSPlus gps;
extern Servo myservo;
extern Adafruit_SSD1306 display;
extern HardwareSerial SerialGPS;

// Fonksiyon Prototipleri
void setupWiFi();
void setupSensors();
void readPIR();
void readRadar();
void readAudio();
void readThermal();
void updateGPS();
void updateDisplay(const String& message, int line);
void triggerAlarm();

#endif
