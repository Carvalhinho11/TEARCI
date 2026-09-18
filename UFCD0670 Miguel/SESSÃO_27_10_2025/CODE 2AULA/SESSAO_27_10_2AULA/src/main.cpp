#include <Arduino.h>
int opcao = 0;

void setup()
{
  Serial.begin(9600);

  //configurar periferico botao 1 
  pinMode(2, INPUT);

  //configurar periferico botao 2
  pinMode(3, INPUT);
}

void loop()
{
  // TESTAR SE O BOTAO 1 ESTA A SER PRESSIONADO
  if(digitalRead(2) == LOW)
  {
    opcao = 0;
  }

  //TESTAR SE O BOTO 2 ESTA A FUNCIONAR
  if(digitalRead(3) == LOW)
  {
    opcao = 1;
  }

  //TESTAR SE OS DOIS BOTOES ESTAO A SER PRESSIONADOS
  if(digitalRead(2) == LOW && digitalRead(3) == LOW)
  {
    opcao = 2;
  }

  switch (opcao)
  {
  case 0:
    Serial.println("Case 2");
    break;

  case 1:
    Serial.println("Case 1");
    break;

  default:
    Serial.println("Default");
    break;
  }
}