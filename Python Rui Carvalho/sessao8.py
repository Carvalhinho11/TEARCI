"""
for i in range(6):
    print(i)

for i in range(2, 10):
    print(i)

for i in range(2, 20, 3):
    print(i)

for i in range(20, 2, -3):
    print(i)
    
soma = 0

for i in range(1, 101):
    soma = soma + i

print(soma)

def soma (lim_i, lim_s):
    soma=0
    for i in range (lim_i, lim_s+1):
        soma=soma+i
    return (soma)
print (soma(1,9))

str="Python"
print(len(str))

str="Python"
print(str[0])

str="Python"
print(str[-3])

str="Python"
print(str.count("y"))

str="Python"
print(str.index("n"))

str="Python"
print(str+"!")

str="Python"
str[:2]
print(str[:2])

str="Python"
str[::2]
print(str[::2])

str="Python"
str[:2]
print(str[::-1])

str="python"
print("on" in str)

str="python"
for i in str:
    print(i)
"""
def conta(s):
    contador = 0
    for i in s:
        contador = contador + 1
    return contador
print(conta("Tomas"))
    
