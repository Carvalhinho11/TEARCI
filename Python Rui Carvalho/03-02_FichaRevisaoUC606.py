"""
"1"
DM=int(input("Distancia em milhas:"))
KM=DM*1.61
print("Resultado em Km", KM)

"2"
GM=int(input("Insira quantos golos foram marcados:"))
GS=int(input("Insira quantos golos foram sofridos:"))
if GM>GS:
    print("vitoria")
elif GS>GM:
    print("derrota")
else:
    print("empate")

"3"
N=int(input("Insere um numero:"))
NM=int(input("Insere um numero maior:"))
soma=0
while N<=NM:
    print(N, soma)
    soma=soma + N
    N=N+1

"4"
NI=int(input("Insere um numero:"))
NM=int(input("Insere um numero maior:"))
soma=0
for i in range(NM+1):
    print(NI, soma)
    soma=soma+NI
    NI=NI+1

"5"
def imc (p,a):
    return(p/a**2)

"6"
def par (x):
    if x %2==0:
        return("true")
    else:
        return("false")

"7"
def maior (x,y):
    if x>y:
        return(x)
    else:
        return(y)
"""
"8"
def val_telef 
    
