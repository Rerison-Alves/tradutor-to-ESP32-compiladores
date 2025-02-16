#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Configuração do PWM
int canalPWM = 0;

// Resposta Http
int httpResponseCode = 0;

int led_pin;
String wifi_ssid, wifi_pass;

void setup() {
pinMode(led_pin, OUTPUT);
Serial.begin(115200);
WiFi.begin(wifi_ssid.c_str(), wifi_pass.c_str());
while(WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.println("Conectando ao WiFi...");
}
Serial.println("Conectado ao WiFi!");
}

void loop() {
digitalWrite(led_pin, HIGH);
HTTPClient http;
http.begin("http://example.com/api");
http.addHeader("Content-Type", "application/x-www-form-urlencoded");
httpResponseCode = http.POST("led=on");
http.end();
delay(1000);
digitalWrite(led_pin, LOW);
HTTPClient http;
http.begin("http://example.com/api");
http.addHeader("Content-Type", "application/x-www-form-urlencoded");
httpResponseCode = http.POST("led=off");
http.end();
delay(1000);
}
