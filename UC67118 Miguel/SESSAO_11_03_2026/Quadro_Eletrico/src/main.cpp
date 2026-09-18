#include <Arduino.h>

const uint8_t PIN_START = 3;
const uint8_t PIN_EMERGENCY = 6;
const uint8_t PIN_STOP  = 4;
const uint8_t PIN_RELE  = 5;

int sinal = 0;

bool pressedEdge(uint8_t pin) {
  static bool lastState[20];
  static unsigned long lastChange[20];

  bool reading = digitalRead(pin);

  if (reading != lastState[pin]) {
    lastState[pin] = reading;
    lastChange[pin] = millis();
  }

  // debounce
  if (millis() - lastChange[pin] > 30) {
    // com INPUT_PULLUP: pressionado = LOW
    if (reading == LOW) {
      // trava até soltar (evita repetir segurando)
      while (digitalRead(pin) == LOW) delay(1);
      return true;
    }
  }
  return false;
}

void setup() {
  pinMode(PIN_START, INPUT_PULLUP);
  pinMode(PIN_EMERGENCY, INPUT_PULLUP);
  pinMode(PIN_STOP,  INPUT_PULLUP);

  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, LOW);
}

void loop() {
  if (pressedEdge(PIN_START)) 
  sinal = 1;
  if (pressedEdge(PIN_STOP))  sinal = 0;
  if (pressedEdge(PIN_EMERGENCY))  sinal = 0;

  // Se seu módulo for "ativo em LOW", inverta aqui:
  digitalWrite(PIN_RELE, sinal ? HIGH : LOW);
}