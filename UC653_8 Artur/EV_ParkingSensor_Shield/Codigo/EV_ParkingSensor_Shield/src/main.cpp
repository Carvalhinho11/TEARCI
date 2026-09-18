#include <LiquidCrystal.h>
// ------------------ PINOS ------------------
#define TRIG_PIN 6
#define ECHO_PIN 5
#define BUZZ_PIN 3
// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
// Barra LEDs (8)
const uint8_t ledPins[8] = {A0, A1, A2, A3, A4, A5, 2, 4};
// 0-3 verdes, 4-5 amarelos, 6-7 vermelhos
// ------------------ PARAMETROS ------------------
const int DIST_MIN_CM = 10; // vermelho crítico
const int DIST_MAX_CM = 120; // acima disto consideramos "longe"
// controlo de "beeps"
unsigned long tBeep = 0;
bool beepState = false;
// ------------------ FUNCOES ------------------
long lerDistanciaCm() {
 // Pulso TRIG
 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(5);
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN, LOW);
 // Timeout 30 ms (~5 m)
 unsigned long dur = pulseIn(ECHO_PIN, HIGH, 30000UL);
 if (dur == 0) return -1; // sem eco
 // cm = us / 58 (aprox.)
 long cm = (long)(dur / 58UL);
 return cm;
}
void setBarLevel(uint8_t level) {
 // level 0..8 (quantos LEDs acesos)
 for (uint8_t i = 0; i < 8; i++) { digitalWrite(ledPins[i], (i < level) ? HIGH : LOW);
 }
}
uint8_t distanciaParaNivel(long cm) {
 // voímetro: quanto mais perto, mais LEDs
 if (cm < 0) return 0;
 if (cm > 80) return 2; // muito longe: 2 verdes
 if (cm > 60) return 3;
 if (cm > 45) return 4; // verdes “cheios”
 if (cm > 30) return 5; // começa amarelo
 if (cm > 20) return 6; // amarelo mais forte
 if (cm > 10) return 7; // entra vermelho
 return 8; // <10 cm: vermelho máximo
}
void buzzerControl(long cm) {
 if (cm < 0) { // sem eco
 noTone(BUZZ_PIN);
 beepState = false;
 return;
 }
 long d = cm;
 if (d < 1) d = 1;
 if (d > DIST_MAX_CM) d = DIST_MAX_CM;
 // frequência (grave -> agudo) ao aproximar
 int freq = map((int)d, DIST_MAX_CM, DIST_MIN_CM, 250, 2200);
 if (freq < 200) freq = 200;
 if (freq > 2500) freq = 2500;
 // ritmo do beep (ms) ao aproximar
 int period = map((int)d, DIST_MAX_CM, DIST_MIN_CM, 600, 80);
 if (period < 60) period = 60;
 // zona crítica: <10 cm -> tom contínuo
 if (cm <= DIST_MIN_CM) {
 tone(BUZZ_PIN, 2400);
 beepState = true;
 return;
 }
 // beeping
 unsigned long now = millis();
 if (now - tBeep >= (unsigned long)period) {
 tBeep = now;
 beepState = !beepState;
 if (beepState) tone(BUZZ_PIN, freq);
 else noTone(BUZZ_PIN);
 }
}
void mostrarLCD(long cm, uint8_t nivel) {
 lcd.setCursor(0, 0);
 lcd.print("Dist: ");
 if (cm < 0) {
 lcd.print("---- cm ");
 } else {
 if (cm < 100) lcd.print(" ");
 if (cm < 10) lcd.print(" ");
 lcd.print(cm);
 lcd.print(" cm ");
 }
 lcd.setCursor(0, 1);
 if (cm < 0) {
 lcd.print("NO ECHO / CHECK ");
 } else if (cm <= 10) {
 lcd.print("DANGER <10cm ");
 } else if (cm <= 20) {
 lcd.print("VERY CLOSE ");
 } else if (cm <= 60) {
 lcd.print("APPROACHING ");
 } else {
 lcd.print("CLEAR / SAFE ");
 }
}
void mostrarSerial(long cm, uint8_t nivel) {
 Serial.print("Distance(cm): ");
 Serial.print(cm);
 Serial.print(" | LED level: ");
 Serial.print(nivel);
 Serial.print(" | Status: ");
 if (cm < 0) Serial.println("NO ECHO");
 else if (cm <= 10) Serial.println("DANGER");
 else if (cm <= 20) Serial.println("VERY CLOSE");
 else if (cm <= 60) Serial.println("APPROACHING");
 else Serial.println("SAFE");

}
// ------------------ SETUP / LOOP ------------------
void setup() {
 Serial.begin(9600);
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 pinMode(BUZZ_PIN, OUTPUT);
 for (uint8_t i = 0; i < 8; i++) {
 pinMode(ledPins[i], OUTPUT);
 digitalWrite(ledPins[i], LOW);
 }
 lcd.begin(16, 2);
 lcd.clear();
 lcd.print("EV Parking Sensor");
 lcd.setCursor(0, 1);
 lcd.print("Ultrasonic + LEDs");
 delay(1200);
 lcd.clear();
}
void loop() {
 long cm = lerDistanciaCm();
 uint8_t nivel = distanciaParaNivel(cm);
 setBarLevel(nivel);
 buzzerControl(cm);
 mostrarLCD(cm, nivel);
 mostrarSerial(cm, nivel);
 delay(120);
}