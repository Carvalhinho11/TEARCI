#1
def imc (x,y):
    return(x/y**2)
#2
def par (z):
    
    if z%2 == 1:
        return("impar")
    else:
        return("par")
#3
def somaw (a):
    soma=0
    while a>0:
        soma=soma+a
        a=a-1
    return(soma)
#4
def somaf (b):
    soma=0
    for i in range(b+1):
        soma=soma+i
        i=i+1
    return(soma)
#5
def ncar(c):
    
    contagem=0
    for i in range(len(c)):
        contagem=contagem+1
    return(contagem)
#6
def numero(e):
    x=0
    for i in e:
        if i >= "0" and i <= "9":
            
            x=x+1
    return(x)
#7
def soma_elem(d):
    soma=0
    contagem=0
    while contagem<len(d):
        soma=soma+d[contagem]
        contagem=contagem+1
    return(soma)
#8
def pt(f):

    if ".pt" in f:
        x="True"
    else:
        x="False"
    return(x)
def pt2(f):

    if ".pt" == f[-3:]:
        x="True"
    else:
        x="False"
    return(x)
