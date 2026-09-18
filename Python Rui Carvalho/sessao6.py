"""
def fatorial(n):
    if n == 1:
        return 1
    else:
        return n * fatorial(n-1)
x = fatorial(4)
print(x)

def soma_n_r(lim_inf, lim_sup):
    if lim_inf == lim_sup:
        return lim_inf
    else:
        return lim_sup + soma_n_r(lim_inf, lim_sup - 1)
    
lim_inf = int(input("Limite inferior: "))
lim_sup = int(input("Limite superior: "))

resultado = soma_n_r(lim_inf, lim_sup)
print("O valor da soma é:",resultado)

def multiplicacao_n_r(lim_inf,lim_sup):
    if lim_inf==lim_sup:
        return lim_inf

    else:
        return lim_inf*multiplicacao_n_r(lim_inf, lim_sup-1)
lim_inf= int(input("Limite inferior:"))
lim_sup= int(input("Limite superior:"))
resultado = multiplicacao_n_r(lim_inf, lim_sup)
print("O valor da multiplicação é:", resultado)
"""
def exponenciacao_n_r(base,expoente):
    if expoente==0:
        return 1
    else:
        return base*exponenciacao_n_r(base,expoente-1)

base = int(input("Base: "))
expoente = int(input("Expoente: "))
resultado = exponenciacao_n_r(base, expoente)
print("O valor da exponenciação é:", resultado)
