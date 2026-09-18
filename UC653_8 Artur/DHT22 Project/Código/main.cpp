#include <Arduino.h>
 #include <DHT.h>
 #include <LiquidCrystal.h>

// CONFIGURAÇÃO DO LCD E DO DHT 
LiquidCrystal lcd(12, 11, 10, 9, 8, 7); 
#define DHTPIN 6 //Pino digital do sinal do DHT11
#define DHTTYPE DHT11 //Tipo de sensor
DHT dht(DHTPIN,DHTTYPE);

//SAIDA DIGITAL CONTROLADA POR TEMPERATURA 
#define LED_PIN 3 // Saída D3 

//VARIAVEIS DE SETPOINT E HISTERESE 
float T0 = 24.0; //Temperatura mínima (liga quando estiver abaixo)
float T1 = 26.0; //Temperatura máxima (desligar quando ultrapassa)

//VARIAVEL PARA ESTADO DE SAÍDA
bool aquecimento = false;


void setup() {
   Serial.begin(9600);
  Serial.println(F("Termostato Digital - DHT11"));
  Serial.println(F("Autora: XDD"));

  
  dht.begin();
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,LOW);

lcd.begin(16, 2);
  
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(F("Termostato DHT11"));
  lcd.setCursor(0,1);
  lcd.print(F("Autor: XDD"));
  delay(1500);
  lcd.clear();
    }

  void loop() {
  float temperatura = dht.readTemperature(); //ºC
  float humidade = dht.readHumidity();

  if(isnan(temperatura)|| isnan(humidade)){
    Serial.println(F("Erro de leitura no DHT11"));
    lcd.setCursor(0,0);
    lcd.print(F("Erro no Sensor"));
    lcd.setCursor(0,1);
    lcd.print(F("Verifique cabos"));
    delay(2500);
    return;

}

  //Controlo com histerese
  if (temperatura > T1 && aquecimento){
    aquecimento = false;
    digitalWrite(LED_PIN,LOW);
  }
  else if (temperatura < T0 && !aquecimento){
    aquecimento = true;
    digitalWrite(LED_PIN,HIGH);
  }
  // dentro da banda [T0, T1], mantém estado anterior 

  //saída séria
  Serial.print(F("Temp:"));
  Serial.print(temperatura,1);
  Serial.print(F("C Hum:"));
  Serial.print(humidade,1);
  Serial.print(F("% Saida:"));
  Serial.print(aquecimento ? F("ON"): F("OFF"));

  //LCD 16x2
  lcd.setCursor(0,0);
  lcd.print(F("T:"));
  lcd.print(temperatura,1);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(9,0);
  lcd.print(F("H:"));
  lcd.print(humidade,0);
  lcd.print("%");

  lcd.setCursor(0,1);
  lcd.print(F("Saida D3:"));
  lcd.print(aquecimento ? F("ON"): F("OFF"));

  delay(1000); //intervalo entre leituras

}