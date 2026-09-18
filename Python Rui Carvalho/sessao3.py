"""
pizzas_medias=int(input("o valor do diametro das pizzas medias são:"))
pizza_grande=int(input("o valor do diametro da pizza grande é:"))
area_das_pizzas_med=(pizzas_medias/2)**2*3.14
print("o area das pizzas média é" ,area_das_pizzas_med)
area_pizza_grande=(pizza_grande/2)**2*3.14
print("area da pizza grande é" ,area_pizza_grande)
if(2*area_das_pizzas_med>area_pizza_grande):
    print("pizzas medias sao maiores")
else:
    print("a pizza grande e maior")

"""
"""
ano= int(input("insira o ano: "))

x=24
y=5
a=ano %19
b=ano %4
c=ano %7
d=(19*a+x)%30
e=(2*b+4*c+6*d+y)%7
if(d+e)<10:
    dia=d+e+22
    mes="Março"
else:
    dia=(d+e-9)
    mes="Abril"
print(f"A Páscoa é no dia." ,dia,"do mes",mes)
"""
ano = int(input ("qual o ano?"))

if ((ano %4  == 0)and(ano %100 != 0))or(ano % 400==0):
    print("é um ano bissexto")
else:
    print("não é um ano bissexto")

    


