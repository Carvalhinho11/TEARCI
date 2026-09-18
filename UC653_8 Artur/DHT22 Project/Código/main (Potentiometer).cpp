

#include "DHT.h"
#include <LiquidCrystal.h>

// --- LCD paralelo (Wokwi standard) ---
#define LCD_RS 12
#define LCD_E  11
#define LCD_D4 10
#define LCD_D5 9
#define LCD_D6 8
#define LCD_D7 7
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// --- DHT ---
#define DHTPIN   6
#define DHTTYPE  DHT11
DHT dht(DHTPIN, DHTTYPE);

// --- Saída ---
#define RELAY_PIN 3

// --- Interface de menu ---
#define POT_PIN    A0
#define BTN_PIN    2   // Botão em INPUT_PULLUP (ENTER)

// --- Setpoints ---
float T0 = 24.0;
float T1 = 26.0;

// --- Estado saída ---
bool aquecimento = false;

// --- Debounce botão ---
bool btnLastRaw = HIGH;
bool btnStable  = HIGH;
unsigned long tDebounce = 0;
const unsigned long DEBOUNCE_MS = 35;

// ---------------------------------------------------------
// Converte leitura do potenciómetro (0..1023) para 5..70 ºC
// (passos de 1 ºC)
// ---------------------------------------------------------
int potParaCelsius() {
  int raw = analogRead(POT_PIN);      // 0..1023
  int val = map(raw, 0, 1023, 5, 70); // 5..70
  if (val < 5)  val = 5;
  if (val > 70) val = 70;
  return val;
}

// ---------------------------------------------------------
// Detecta "clique" (transição HIGH->LOW) com debounce
// Retorna true apenas 1 vez por clique
// ---------------------------------------------------------
bool botaoClique() {
  bool raw = digitalRead(BTN_PIN);

  if (raw != btnLastRaw) {
    btnLastRaw = raw;
    tDebounce = millis();
  }

  if (millis() - tDebounce > DEBOUNCE_MS) {
    if (raw != btnStable) {
      btnStable = raw;
      if (btnStable == LOW) return true; // clique (premido)
    }
  }
  return false;
}

// ---------------------------------------------------------
// Menu no arranque: define T0 e depois T1
// ---------------------------------------------------------
void menuSetpoints() {
  // --- Definir T0 ---
  while (true) {
    int sel = potParaCelsius();

    lcd.setCursor(0, 0);
    lcd.print("Definir T0 (C) ");
    lcd.setCursor(0, 1);
    lcd.print("T0=");
    lcd.print(sel);
    lcd.print(" ENTER=OK   "); // limpa resto

    if (botaoClique()) {
      T0 = (float)sel;
      break;
    }
    delay(60);
  }

  // --- Definir T1 (obrigatoriamente > T0) ---
  while (true) {
    int sel = potParaCelsius();

    int minT1 = (int)T0 + 1;   // minimo T0+1
    if (sel < minT1) sel = minT1;
    if (sel > 70) sel = 70;

    lcd.setCursor(0, 0);
    lcd.print("Definir T1 (C) ");
    lcd.setCursor(0, 1);
    lcd.print("T1=");
    lcd.print(sel);
    lcd.print(" ENTER=OK   ");

    if (botaoClique()) {
      T1 = (float)sel;
      break;
    }
    delay(60);
  }

  // --- Mostrar resumo ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Setpoints OK");
  lcd.setCursor(0, 1);
  lcd.print("T0=");
  lcd.print(T0, 0);
  lcd.print(" T1=");
  lcd.print(T1, 0);

  Serial.print(F("Setpoints definidos: T0="));
  Serial.print(T0, 0);
  Serial.print(F(" C, T1="));
  Serial.print(T1, 0);
  Serial.println(F(" C"));

  delay(1400);
  lcd.clear();
}

void setup() {
  Serial.begin(115200);
  Serial.println(F("Termostato Digital - DHT22"));
  Serial.println(F("Autor: Artur G."));

  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  pinMode(BTN_PIN, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Termostato DHT22");
  lcd.setCursor(0, 1);
  lcd.print("A configurar...");
  delay(900);

  // --- Menu logo após o arranque ---
  menuSetpoints();
}

void loop() {
  float temperatura = dht.readTemperature();  // ºC
  float humidade    = dht.readHumidity();     // %

  if (isnan(temperatura) || isnan(humidade)) {
    Serial.println(F("Erro de leitura no DHT22"));
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor  ");
    lcd.setCursor(0, 1);
    lcd.print("Verifique cabos ");
    delay(2000);
    return;
  }

  // --- Controlo com histerese ---
  if (temperatura > T1 && aquecimento) {
    aquecimento = false;
    digitalWrite(RELAY_PIN, LOW);
  }
  else if (temperatura < T0 && !aquecimento) {
    aquecimento = true;
    digitalWrite(RELAY_PIN, HIGH);
  }

  // --- Serial ---
  Serial.print(F("Temp: "));
  Serial.print(temperatura, 1);
  Serial.print(F(" C  Hum: "));
  Serial.print(humidade, 1);
  Serial.print(F("%  T0="));
  Serial.print(T0, 0);
  Serial.print(F(" T1="));
  Serial.print(T1, 0);
  Serial.print(F("  Saida: "));
  Serial.println(aquecimento ? F("ON") : F("OFF"));

  // --- LCD 16x2 ---
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.print("H:");
  lcd.print(humidade, 0);
  lcd.print("% ");

  lcd.setCursor(0, 1);
  lcd.print("T0:");
  lcd.print(T0, 0);
  lcd.print(" T1:");
  lcd.print(T1, 0);
  lcd.print(" ");
  lcd.print(aquecimento ? "ON " : "OFF");

  delay(1000);
}