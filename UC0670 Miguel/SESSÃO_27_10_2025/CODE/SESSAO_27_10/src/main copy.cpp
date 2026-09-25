#include <Arduino.h>
 unsigned long t = 0;
 unsigned long comecar_contagem = 0;
 unsigned long tempo_anterior = 5;
 int led;
void setup()
 {
   Serial.begin(9600);
  pinMode(led, OUTPUT);
 }

 void loop()
 {
  if (digitalRead(led=LOW))
  {
    comecar_contagem = 1;
    tempo_anterior = millis();
  }
  if (t - tempo_anterior >5000)
  {
    tempo_anterior = millis();
  }
  
   t=millis();
  
   if (t - tempo_anterior >2000)
   {
  
   digitalWrite(LED_BUILTIN,HIGH);
   digitalWrite(3, HIGH);

   Serial.print("t - 5s");
   Serial.println(t);
   Serial.print("tempo_anterior 5s ");
   Serial.println(tempo_anterior);
   tempo_anterior = millis();
   }
  }