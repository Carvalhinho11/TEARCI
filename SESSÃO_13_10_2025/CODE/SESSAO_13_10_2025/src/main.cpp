#include <Arduino.h>

int s=0;

void setup() 
{
  
  Serial.begin(9600);
  pinMode(4, INPUT);
}

void loop()
{ 
s = digitalRead(4);
Serial.print("s- ");
Serial.println(s);
  if (s)
  { 
    Serial.println("Botão pressionado");
  }

Serial.println("Tomás");
  delay(1000);
}


    
  

  
