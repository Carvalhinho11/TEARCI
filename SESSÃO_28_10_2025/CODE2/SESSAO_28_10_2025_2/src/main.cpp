#include <Arduino.h>

typedef enum enum_botoes
{
  CIMA = 0,
  DIREITA,
  BAIXO,
  ESQUERDA,
  TOTAL
};

enum_botoes eb;

typedef enum opcao
{
  PARADO = 0,
  SETA_PARA_CIMA,
  SETA_PARA_DIREITA,
  SETA_PARA_BAIXO,
  SETA_PARA_ESQUERDA,
  SETA_DIAGONAL_CIMA_DIREITA,
  SETA_DIAGONAL_CIMA_ESQUERDA,
  SETA_DIAGONAL_BAIXO_DIREITA,
  SETA_DIAGONAL_BAIXO_ESQUERDA
}
void setup(0)

{
botoes.estado = digitalRead(botoes[1].periferico);
botoes.estado = digitalRead(botoes[2].periferico);
botoes.estado = digitalRead(botoes[3].periferico);
botoes.estado = digitalRead(botoes[4].periferico);

  
  if (digitalRead(b1.estado) == HIGH)
  {
    botaopress = 1;
  }
  if (digitalRead(b2.estado) == HIGH)
  {
    botaopress = 2;
  }

if (digitalRead(b3.estado) == HIGH)
  {
    botaopress = 3;
  }
  if (digitalRead(b4.estado) == HIGH)
  {
    botaopress = 4;
  }
  if (digitalRead(b1.estado) == HIGH && digitalRead(b2.estado) == HIGH)
  {
    botaopress = 5;
  }
  if (digitalRead(b1.estado) == HIGH && digitalRead(b4.estado) == HIGH)
  {
    botaopress = 6;
  }
  if (digitalRead(b3.estado) == HIGH && digitalRead(b2.estado) == HIGH)
  {
    botaopress = 7;
  }
  if (digitalRead(b3.estado) == HIGH && digitalRead(b4.estado) == HIGH)
  {
    botaopress = 8;
  }
    if (digitalRead(b3.estado) == HIGH && digitalRead(b4.estado) == HIGH && digitalRead(b1.estado) == HIGH && digitalRead(b2.estado) == HIGH)
  {
    botaopress = 9;
  }
    if (digitalRead(b3.estado) == LOW && digitalRead(b4.estado) == LOW && digitalRead(b1.estado) == LOW && digitalRead(b2.estado) == LOW)
  {
    botaopress = 10;
  }
  

  switch (botaopress)
  {
  case 1:
    Serial.println("CIMA");
    break;
  case 2:
  
     Serial.println("DIREITA");
     break;
     case 3:
    Serial.println("BAIXO");
    break;
  case 4:
  
     Serial.println("ESQUERDA");
     break;
     case 5:
    Serial.println("DIAGONAL SUPERIOR DIREITA");
    break;
  case 6:
  
     Serial.println("DIAGONAL SUPERIOR ESQUERDA");
     break;
     case 7:
    Serial.println("DIAGONAL INFERIOR DIREITA");
    break;
  case 8:
  
     Serial.println("DIAGONAL INFERIOR ESQUERDA");
     break;
     case 9:
    Serial.println("TUDO LIGADO");
    break;
  case 10:
  
     Serial.println("TUDO DESLIGADO");
     break;
  default:
  
    Serial.println("erro");
    break;
  }

}