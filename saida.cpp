#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Configuração do PWM
int canalPWM = 0;

String nome;
int idade;

void setup() {
nome = "João";
idade = 20;
