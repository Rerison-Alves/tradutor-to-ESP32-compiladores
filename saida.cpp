#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Configuração do PWM
int canalPWM = 0;

int ledPin, brilho;
String ssid, senha;

void setup() {
ledPin = 2;
ssid = "MinhaRedeWiFi";
senha = "MinhaSenhaWiFi";
pinMode(ledPin, OUTPUT);
ledcSetup(0, 5000, 8);
ledcAttachPin(ledPin, 0);
WiFi.begin(ssid.c_str(), senha.c_str());
while(WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.println("Conectando ao WiFi...");
}
Serial.println("Conectado ao WiFi!");
}

void loop() {
brilho = 128;
ledcWrite(0, brilho);
delay(1000);
brilho = 0;
ledcWrite(0, brilho);
delay(1000);
}
