#include <Arduino.h>

int botao = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(4,INPUT);
  pinMode(2, OUTPUT);

}

void loop() 
{
  botao = digitalRead(4);

  if(botao)
  {
    digitalWrite (2, HIGH);
    Serial.println("Botao nao pressionado");
  }
  else
  {
    digitalWrite (2, LOW);
    Serial.println("Botao pressionado");     
  }
  delay(500);
}