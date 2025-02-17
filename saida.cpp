#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Configuracao do PWM
int canalPWM = 0;

// Resposta Http
int httpResponseCode = 0;

int i;
int j;

void setup() {
Serial.begin(115200);
