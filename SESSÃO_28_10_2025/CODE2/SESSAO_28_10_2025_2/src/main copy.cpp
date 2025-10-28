// #include <Arduino.h>

// int botaopress = 0;
// typedef struct botao
// {
//   int estado;
//   int periferico;
// };
// botao b1;
// botao b2;
// botao b3;
// botao b4;

// void setup() {
//   b1.periferico = 2;
//   b2.periferico = 3;
//   b3.periferico = 4;
//   b4.periferico = 5;
//   b1.estado = LOW;
//   b2.estado = LOW;
//   b3.estado = LOW;
//   b4.estado = LOW;

// pinMode(b1.periferico, INPUT);
// pinMode(b2.periferico, INPUT);
// pinMode(b3.periferico, INPUT);
// pinMode(b4.periferico, INPUT);
// Serial.begin(9600);
// }

// void loop() {
// b1.estado = digitalRead(b1.periferico);
// b2.estado = digitalRead(b2.periferico);
// b3.estado = digitalRead(b3.periferico);
// b4.estado = digitalRead(b4.periferico);

  
//   if (digitalRead(b1.estado) == HIGH)
//   {
//     botaopress = 1;
//   }
//   if (digitalRead(b2.estado) == HIGH)
//   {
//     botaopress = 2;
//   }

// if (digitalRead(b3.estado) == HIGH)
//   {
//     botaopress = 3;
//   }
//   if (digitalRead(b4.estado) == HIGH)
//   {
//     botaopress = 4;
//   }
//   if (digitalRead(b1.estado) == HIGH && digitalRead(b2.estado) == HIGH)
//   {
//     botaopress = 5;
//   }
//   if (digitalRead(b1.estado) == HIGH && digitalRead(b4.estado) == HIGH)
//   {
//     botaopress = 6;
//   }
//   if (digitalRead(b3.estado) == HIGH && digitalRead(b2.estado) == HIGH)
//   {
//     botaopress = 7;
//   }
//   if (digitalRead(b3.estado) == HIGH && digitalRead(b4.estado) == HIGH)
//   {
//     botaopress = 8;
//   }
//     if (digitalRead(b3.estado) == HIGH && digitalRead(b4.estado) == HIGH && digitalRead(b1.estado) == HIGH && digitalRead(b2.estado) == HIGH)
//   {
//     botaopress = 9;
//   }
//     if (digitalRead(b3.estado) == LOW && digitalRead(b4.estado) == LOW && digitalRead(b1.estado) == LOW && digitalRead(b2.estado) == LOW)
//   {
//     botaopress = 10;
//   }
  

//   switch (botaopress)
//   {
//   case 1:
//     Serial.println("CIMA");
//     break;
//   case 2:
  
//      Serial.println("DIREITA");
//      break;
//      case 3:
//     Serial.println("BAIXO");
//     break;
//   case 4:
  
//      Serial.println("ESQUERDA");
//      break;
//      case 5:
//     Serial.println("DIAGONAL SUPERIOR DIREITA");
//     break;
//   case 6:
  
//      Serial.println("DIAGONAL SUPERIOR ESQUERDA");
//      break;
//      case 7:
//     Serial.println("DIAGONAL INFERIOR DIREITA");
//     break;
//   case 8:
  
//      Serial.println("DIAGONAL INFERIOR ESQUERDA");
//      break;
//      case 9:
//     Serial.println("TUDO LIGADO");
//     break;
//   case 10:
  
//      Serial.println("TUDO DESLIGADO");
//      break;
//   default:
  
//     Serial.println("erro");
//     break;
//   }

// }

