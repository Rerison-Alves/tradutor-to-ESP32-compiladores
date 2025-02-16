#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Configuração do PWM
int canalPWM = 0;

// Resposta Http
int httpResponseCode = 0;

int i;
int j;

void setup() {
Serial.begin(115200);
}

void loop() {
    j = 2;
    while(true) {
    Serial.println(j);
        j = (j + 2);
    }
    i = 1;
    while ((i <= 10)) {
        Serial.println(i);
        i = (i + 1);
    }
    if ((i <= 10)) {
        Serial.println(i);
    } else {
        Serial.println(j);
    }
    delay(2000);
}
