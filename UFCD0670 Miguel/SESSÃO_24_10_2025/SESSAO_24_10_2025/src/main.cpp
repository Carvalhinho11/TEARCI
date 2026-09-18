#include <Arduino.h>
unsigned long t = 0;
unsigned long t2 = 0;
unsigned long tempo_anterior = 0;
unsigned long tempo_anterior2 = 0;
unsigned long temp2 = 0;
int botaopress =0;
int tempbotao =0;
int botao=0;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600);
}

void loop() {
  t = millis();
if (t - tempo_anterior > 2000)
if(botao)
{
  botaopress = 1; // ativa o press
  tempbotao = millis(); // começa a contar
digitalWrite(LED_BUILTIN, HIGH);
Serial.print("t -");
Serial.println(t);
Serial.print("tempo_anterior - ");
Serial.println(tempo_anterior);
tempo_anterior = millis();
}

// se press 1
if(botaopress)
t = millis();
if (t2 - tempo_anterior2 > 1000)
{
  t = millis ();// começa a contatr outro tempo 

  if(t-tempbotao>2000)
//chega no tempo e liga

digitalWrite(LED_BUILTIN, HIGH);
temp2 = millis();
if(tempbotao-temp2>2000)
{
 digitalWrite(LED_BUILTIN, LOW);
}
}
}







