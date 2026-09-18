/*
  Testa_Perifericos - Arduino Uno

  Testa:
  - DHT22 em D6
  - Saida digital em D3 (travessa 1R)
  - Potenciometro em A0
  - Botao em D2 (INPUT_PULLUP)
  - LCD paralelo HD44780 (16x2) - ligacao  na documentação Wokwi
*/

#include <DHT.h>
#include <LiquidCrystal.h>

// ---------------- Pinos ----------------
#define PIN_DHT     6
#define PIN_SAIDA  3
#define PIN_BOTAO  2
#define PIN_ADC    A0

// LCD (Wokwi standard)
#define LCD_RS 12
#define LCD_E  11
#define LCD_D4 10
#define LCD_D5 9
#define LCD_D6 8
#define LCD_D7 7

// ---------------- Objectos ----------------
#define DHTTYPE DHT22
DHT dht(PIN_DHT, DHTTYPE);

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// ---------------- Variáveis ----------------
unsigned long tDHT   = 0;
unsigned long tADC   = 0;
unsigned long tLCD   = 0;
unsigned long tOUT   = 0;

bool estadoSaida = false;

// Botão
bool botaoAnterior = HIGH;

// Últimos valores
float temperatura = NAN;
float humidade    = NAN;
int   adcValor    = 0;

// ---------------- Setup ----------------
void setup() {
  Serial.begin(9600);

  pinMode(PIN_SAIDA, OUTPUT);
  pinMode(PIN_BOTAO, INPUT_PULLUP);

  digitalWrite(PIN_SAIDA, LOW);

  dht.begin();

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Testa");
  lcd.setCursor(0, 1);
  lcd.print("Perifericos");

  Serial.println("=== Testa_Perifericos - Arduino Uno ===");
  delay(1500);
  lcd.clear();
}
void testaSaida() {
  if (millis() - tOUT >= 500) {
    tOUT = millis();
    estadoSaida = !estadoSaida;
    digitalWrite(PIN_SAIDA, estadoSaida);
  }
}

void testaDHT() {
  if (millis() - tDHT >= 2000) {
    tDHT = millis();

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (!isnan(h) && !isnan(t)) {
      humidade = h;
      temperatura = t;

      Serial.print("DHT22  T=");
      Serial.print(t, 1);
      Serial.print(" C  H=");
      Serial.print(h, 1);
      Serial.println(" %");
    } else {
      Serial.println("Erro leitura DHT22");
    }
  }
}

void testaADC() {
  if (millis() - tADC >= 300) {
    tADC = millis();
    adcValor = analogRead(PIN_ADC);

    Serial.print("A0=");
    Serial.println(adcValor);
  }
}

void testaBotao() {
  bool estadoBotao = digitalRead(PIN_BOTAO);

  if (estadoBotao != botaoAnterior) {
    botaoAnterior = estadoBotao;

    if (estadoBotao == LOW) {
      Serial.println("Botao premido");
      digitalWrite(PIN_SAIDA, HIGH);
      delay(150);
      digitalWrite(PIN_SAIDA, LOW);
    }
  }
}

void actualizaLCD() {
  if (millis() - tLCD >= 700) {
    tLCD = millis();

    lcd.setCursor(0, 0);
    lcd.print("T:");
    if (!isnan(temperatura)) {
      lcd.print(temperatura, 1);
      lcd.print("C ");
      lcd.print("H:");
      lcd.print(humidade, 0);
      lcd.print("% ");
    } else {
      lcd.print("DHT ---     ");
    }

    lcd.setCursor(0, 1);
    lcd.print("A0:");
    lcd.print(adcValor);
    lcd.print(" B:");
    lcd.print(digitalRead(PIN_BOTAO) == LOW ? "ON " : "OFF");
    lcd.print(" D3:");
    lcd.print(estadoSaida ? "1" : "0");
  }
}
// ---------------- Loop ----------------
void loop() {
  testaSaida();
  testaDHT();
  testaADC();
  testaBotao();
  actualizaLCD();
}