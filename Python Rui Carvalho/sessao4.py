"""
numero = int(input("Digite um número: "))

if numero > 0:
    print("O número é positivo.")
elif numero < 0:
    print("O número é negativo.")
else:
    print("O número é zero.")

soma = 0
num = 1
while num <= 100:
    soma = soma + num
    num = num + 1     

    print(soma)


#ciclo while


limite = int(input("Até que número deseja somar? "))

# Inicialização
soma = 0
num = 1

# Ciclo while
while num <= limite:
    soma = soma + num
    num = num + 1

# Output
print("A soma de 1 até", limite, "é:", soma)


# Ciclo while
N1 = int(input("Insira o primeiro número: "))
N2 = int(input("Insira o segundo número: "))

# Inicialização
soma = 0
num = N1

# Ciclo while
while num <= N2:
    soma += num
    num += 1

# Output
print("A soma de", N1, "até", N2, "é:", soma)

def maioridade(n):
    if n>=18:
        return("maior")
    else:
        return("menor")

idade=int(input("Insira a idade da pessoa:"))
print("A pessoa é",maioridade(idade))

ano = int(input("Digite um ano: "))

if (ano % 4 == 0 and ano % 100 != 0) or (ano % 400 == 0):
    print("O ano", ano, "é bissexto.")
else:
    print("O ano", ano, "nao é bissexto.")

def fatorial(n):
    fatorial = 1
    while n > 0:
        fatorial *= n
        n -= 1
    return fatorial
num = int(input("Digite um numero: "))
print(f"O fatorial de {num} é {fatorial(num)}")

def multiplicacao(b,p):
    produto = 0
    num = 0
    
    while num < p:
        produto = produto +b
        num = num + 1
        print(produto)
        
    return(produto)

numero = int(input("Digite um número: "))
vezes = int(input("Digite quantas vezes: "))

print("O valor é", multiplicacao(numero, vezes))
"""



