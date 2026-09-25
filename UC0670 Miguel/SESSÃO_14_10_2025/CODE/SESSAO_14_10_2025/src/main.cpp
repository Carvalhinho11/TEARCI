#include <Arduino.h>

int s =0;

void setup() 
{ 
  //
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(2, OUTPUT);

}

void loop()
{ 
  s =digitalRead(4);

  if (s)
  {
    Serial.println("dentro do if");
    digitalWrite(2, LOW);
  }
  else
  { 
    Serial.println("dentro do else");
    digitalWrite(2, HIGH);
  }
  Serial.println("morto");
  delay(1000);

}
  


