// #include <Arduino.h>
//  unsigned long t = 0;
//  unsigned long tempo_anterior = 5;
//  int led;
// void setup()
//  {
//    Serial.begin(9600);
//   pinMode(led, OUTPUT);
//  }

//  void loop()
//  {
//   //já passou 5segundos
//    t=millis();
  
//    if (t - tempo_anterior >2000)
//    {
  
//    digitalWrite(LED_BUILTIN,HIGH);

//   Serial.print("t 5s");
//   Serial.println(t);
//     Serial.print("tempo-anterior 5s ");
//    Serial.println(tempo_anterior);
//    tempo_anterior = millis();
//    }
//   }