"""
L=float(input("Insira a medida do lado:"))
P=L*4
print("O perimetro P:",P)
A=L*L
print("A área é A:",A)

altura_m=int(input("Qual é a altura em centimetros:"))
print(altura_m*100)

def maioridade(n):
    if n>=18:
        return("maior")
    else:
        return("menor")

idade=int(input("Insira a idade da pessoa:"))
print("A pessoa é",maioridade(idade))

numero = int(input("Digite um número inteiro: "))
if numero % 2 == 0:
    print(f"O número {numero} é par.")
else:
    print(f"O número {numero} é ímpar.")
"""
