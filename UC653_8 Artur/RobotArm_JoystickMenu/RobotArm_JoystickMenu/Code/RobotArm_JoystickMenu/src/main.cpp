#include <LiquidCrystal.h>
#include <Servo.h>
// ---------------- LCD 16x2 (paralelo) ----------------
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
// ---------------- Joystick ----------------
#define JOY_X A0 // HORZ
#define JOY_Y A1 // VERT
#define JOY_SEL 2 // clique (INPUT_PULLUP)
// ---------------- Servos (2 eixos) ----------------
Servo servoV; // Axis 1 (Vertical)
Servo servoH; // Axis 2 (Horizontal)
#define SERVO_V_PIN 6
#define SERVO_H_PIN 5
// ---------------- Parâmetros ----------------
int angV = 90;
int angH = 90;
const int ANG_MIN = 0;
const int ANG_MAX = 180;
const int ADC_CENTER = 512;
const int DEADZONE = 120;
const unsigned long REPEAT_MS_MIN = 50;
const unsigned long REPEAT_MS_MAX = 220;
const unsigned long LONGPRESS_MS = 800;
const unsigned long SEL_DB_MS = 40;
// ---------------- Menu / Estados ----------------
enum Mode {
 MODE_MENU = 0,
 MODE_AXIS1_VERT,
 MODE_AXIS2_HORZ
};
Mode mode = MODE_MENU;
int menuIndex = 0;
unsigned long tRepeat = 0;
// LCD anti-flicker
int lastLine0Hash = -1;
int lastLine1Hash = -1;
// Botão SEL
bool selLastRaw = HIGH;
bool selStable = HIGH;
unsigned long tDebounce = 0;
unsigned long tPressStart = 0;
bool longPressFired = false;
int hashLine(const char* s) {
 int h = 0;
 while (*s) h = (h * 31) + *s++;
 return h;
}
void lcdWrite2(const char* l0, const char* l1) {
 int h0 = hashLine(l0);
 int h1 = hashLine(l1);
 if (h0 == lastLine0Hash && h1 == lastLine1Hash) return;
 lastLine0Hash = h0;
 lastLine1Hash = h1;
 lcd.setCursor(0, 0);
 lcd.print(" ");
 lcd.setCursor(0, 0);
 lcd.print(l0);
 lcd.setCursor(0, 1);
 lcd.print(" ");
 lcd.setCursor(0, 1);
 lcd.print(l1);
}
int joyAxisStep(int pin, int &magAbs) {
 int v = analogRead(pin);
 int delta = v - ADC_CENTER;
 if (delta > DEADZONE) { magAbs = delta; return +1; }
 if (delta < -DEADZONE){ magAbs = -delta; return -1; }
 magAbs = 0;
 return 0;
}
unsigned long intervalByMag(int magAbs) {
 if (magAbs < 0) magAbs = 0;
 if (magAbs > 511) magAbs = 511;
 return (unsigned long)map(magAbs, 0, 511, REPEAT_MS_MAX, REPEAT_MS_MIN);
}
bool allowRepeat(unsigned long intervalMs) {
 unsigned long now = millis();
 if (now - tRepeat >= intervalMs) {
 tRepeat = now;
 return true;
 }
 return false;
}
// SEL: 1=short click, 2=long press, 0=none
int selEvent() {
 bool raw = digitalRead(JOY_SEL);
 if (raw != selLastRaw) {
 selLastRaw = raw;
 tDebounce = millis();
 }
 if (millis() - tDebounce > SEL_DB_MS) {
 if (raw != selStable) {
 selStable = raw;
 if (selStable == LOW) {
 tPressStart = millis();
 longPressFired = false;
 } else {
 if (!longPressFired) return 1;
 }
 }
 }
 if (selStable == LOW && !longPressFired) {
 if (millis() - tPressStart >= LONGPRESS_MS) {
 longPressFired = true;
 return 2;
 }
 }
 return 0;
}
void drawMenu() {
 const char* items[3] = {"1) Axis1 VERT",
 "2) Axis2 HORZ",
 "3) Exit"
 };
 char line0[17];
 char line1[17];
 snprintf(line0, sizeof(line0), "Menu: %d/3", menuIndex + 1);
 snprintf(line1, sizeof(line1), "%s", items[menuIndex]);
 lcdWrite2(line0, line1);
}
void drawAxis1() {
 char l0[17], l1[17];
 snprintf(l0, sizeof(l0), "Axis1 VERT");
 snprintf(l1, sizeof(l1), "Ang:%3d Hold=EXIT", angV);
 lcdWrite2(l0, l1);
}
void drawAxis2() {
 char l0[17], l1[17];
 snprintf(l0, sizeof(l0), "Axis2 HORZ");
 snprintf(l1, sizeof(l1), "Ang:%3d Hold=EXIT", angH);
 lcdWrite2(l0, l1);
}
void setup() {
 pinMode(JOY_SEL, INPUT_PULLUP);
 servoV.attach(SERVO_V_PIN);
 servoH.attach(SERVO_H_PIN);
 servoV.write(angV);
 servoH.write(angH);
 lcd.begin(16, 2);
 lcdWrite2("Joystick + Servo", "Robot Arm Ready");
 delay(1200);
 mode = MODE_MENU;
 menuIndex = 0;
 drawMenu();
}
void loop() {
 int ev = selEvent();
 if (mode == MODE_MENU) {
 int mag = 0;
 int yStep = joyAxisStep(JOY_Y, mag);
 unsigned long rep = intervalByMag(mag);
 // yStep>0 (cima) -> menuIndex--
 // yStep<0 (baixo) -> menuIndex++
 if (yStep != 0 && allowRepeat(rep)) {
 if (yStep > 0) {
 if (menuIndex > 0) menuIndex--;
 } else {
 if (menuIndex < 2) menuIndex++;
 }
 drawMenu();
 }
 if (ev == 1) {
 if (menuIndex == 0) { mode = MODE_AXIS1_VERT; drawAxis1(); }
 else if (menuIndex == 1) { mode = MODE_AXIS2_HORZ; drawAxis2(); }
 else { menuIndex = 0; drawMenu(); }
 }
 }
 if (mode == MODE_AXIS1_VERT) {
 if (ev == 2) { mode = MODE_MENU; drawMenu(); delay(150); return; }
 int mag = 0;
 int yStep = joyAxisStep(JOY_Y, mag);
 unsigned long rep = intervalByMag(mag);
 if (yStep != 0 && allowRepeat(rep)) {
 if (yStep > 0) angV++;
 else angV--;
 if (angV < ANG_MIN) angV = ANG_MIN;
 if (angV > ANG_MAX) angV = ANG_MAX;
 servoV.write(angV);
 drawAxis1();
 }
 }
 if (mode == MODE_AXIS2_HORZ) {
 if (ev == 2) { mode = MODE_MENU; drawMenu(); delay(150); return; }
 int mag = 0;
 int xStep = joyAxisStep(JOY_X, mag);
 unsigned long rep = intervalByMag(mag);
 if (xStep != 0 && allowRepeat(rep)) {
 // Convenção: um lado aumenta, outro diminui
 if (xStep > 0) angH++;
 else angH--;
 if (angH < ANG_MIN) angH = ANG_MIN;
 if (angH > ANG_MAX) angH = ANG_MAX;
 servoH.write(angH);
 drawAxis2();
 }
 }
 delay(10);
}