#include <Arduino.h>

const uint8_t PWM_PIN = 3;
const uint8_t RELAY_PIN = 2;

const uint16_t RAMP_TIME_MS = 3000; // 0% -> 100% em 3s
const uint16_t OFF_TIME_MS  = 500;  // fica 0% por 0.5s

enum Phase { RAMP_UP, OFF };
Phase phase = RAMP_UP;
unsigned long phaseStartMs = 0;

// Relay sem delay:
bool relayState = false;
unsigned long relayLastToggleMs = 0;
const uint16_t RELAY_ON_MS  = 3000;
const uint16_t RELAY_OFF_MS = 3000;

void updatePwmRamp() {
  unsigned long now = millis();
  unsigned long elapsed = now - phaseStartMs;

  if (phase == RAMP_UP) {
    if (elapsed >= RAMP_TIME_MS) {
      analogWrite(PWM_PIN, 0);
      phase = OFF;
      phaseStartMs = now;
    } else {
      uint8_t duty = (uint32_t)elapsed * 255u / RAMP_TIME_MS;
      analogWrite(PWM_PIN, duty);
    }
  } else { // OFF
    if (elapsed >= OFF_TIME_MS) {
      phase = RAMP_UP;
      phaseStartMs = now;
    } else {
      analogWrite(PWM_PIN, 0);
    }
  }
}

void updateRelay() {
  unsigned long now = millis();
  unsigned long interval = relayState ? RELAY_ON_MS : RELAY_OFF_MS;

  if (now - relayLastToggleMs >= interval) {
    relayState = !relayState;
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);
    relayLastToggleMs = now;
  }
}

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  analogWrite(PWM_PIN, 0);
  phaseStartMs = millis();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  relayLastToggleMs = millis();
}

void loop() {
  updatePwmRamp();  // tem que rodar o tempo todo!
  updateRelay();    // relay também, sem travar
}
