#include <Arduino.h>

int opcao = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(2, INPUT);

  pinMode(3, INPUT);

  pinMode(4, INPUT);

  pinMode(5, INPUT);
}

void loop()
{
  if (digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH) {
    opcao = 0; // Nenhum botão
  } 
 if (digitalRead(2) == LOW && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH) {
    opcao = 1; // Seta para cima
  } 
 if (digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == LOW && digitalRead(5) == HIGH) {
    opcao = 2; // Seta para a direita
  } 
 if (digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == LOW) {
    opcao = 3; // Seta para baixo
  } 
 if (digitalRead(2) == HIGH && digitalRead(3) == LOW && digitalRead(4) == HIGH && digitalRead(5) == HIGH) {
    opcao = 4; // Seta para a esquerda
  } 
 if (digitalRead(2) == LOW && digitalRead(3) == HIGH && digitalRead(4) == LOW && digitalRead(5) == HIGH) {
    opcao = 5; // Cima e direita
  } 
 if (digitalRead(2) == LOW && digitalRead(3) == LOW && digitalRead(4) == HIGH && digitalRead(5) == HIGH) {
    opcao = 6; // Cima e esquerda
  } 
 if (digitalRead(2) == HIGH && digitalRead(3) == LOW && digitalRead(4) == HIGH && digitalRead(5) == LOW) {
    opcao = 7; // Baixo e esquerda
  } 
 if (digitalRead(2) == LOW && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == LOW) {
    opcao = 8; // Baixo e direita
  } 

  switch (opcao)
  {
  case 0:
    Serial.println("Fazer Nada");
    break;

  case 1:
    Serial.println("Seta para cima");
    break;

  case 2:
    Serial.println("Seta para a direita");
    break;

  case 3:
    Serial.println("Seta para baixo");
    break;

  case 4:
    Serial.println("Seta para a esquerda");
    break;

  case 5:
    Serial.println("Seta para cima e direita");
    break;

  case 6:
    Serial.println("Seta para cima e esquerda");
    break;

  case 7:
    Serial.println("Seta para baixo e esquerda");
    break;

  case 8:
    Serial.println("Seta para baixo e direita");
    break;

  default:
    Serial.println("default");
    break;
  }
}