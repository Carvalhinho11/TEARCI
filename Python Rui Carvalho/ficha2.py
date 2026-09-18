"""
soma = 0
num = 1
while num <= 100:
    soma = soma + num
    num = num + 1     

    print(soma)

limite = int(input("Até que número deseja somar? "))

soma = 0
num = 1


while num <= limite:
    soma = soma + num
    num = num + 1


print("A soma de 1 até", limite, "é:", soma)

numero = int(input("Digite um número: "))

if numero > 0:
    print("O número é positivo.")
elif numero < 0:
    print("O número é negativo.")
else:
    print("O número é zero.")

def fatorial(n):
    fatorial = 1
    while n > 0:
        fatorial *= n
        n -= 1
    return fatorial
num = int(input("Digite um numero: "))
print(f"O fatorial de {num} é {fatorial(num)}")
"""
