
"""alt_m=1.75
print(alt_m)

ecra_inc=int(input("insira o tamanho do ecra em polegadas:"))
ecra_cm=ecra_inc*2.54
print("medida do ecra em centimetros é: ",ecra_cm)

preco=float(input("qual e o preco do bilhete:"))
bilhetes=int(input("numeros de bilhetes pagos:"))
valor=preco*bilhetes
print("valor total a pagar é: ", valor)

comp_retangulo=8
larg_retangulo=5
perimetro=(comp_retangulo+larg_retangulo)*2
print("o perimetro do retangulo é" ,perimetro)
area=comp_retangulo*larg_retangulo
print("a area do retangulo é" ,area)

lado_quadrado=7
perimetro=lado_quadrado*4
print("o perimetro do quadrado é" ,perimetro)
area=lado_quadrado*lado_quadrado
print("a area do quadrado e" ,area)

custo_sem_iva=int(input("insira o custo sem iva: "))
taxa_iva=0.23
2valor_do_iva=custo_sem_iva*taxa_iva
print("o valor do iva é" ,valor_do_iva)
custo_total=valor_do_iva+custo_sem_iva
print("o valor total é" ,custo_total)

deposito_01_01_2027=int(input("insira o valor do deposito: "))
taxa_de_juro=float(input("insira o valor da taxa de juro: "))
valor_juro=deposito_01_01_2027*taxa_de_juro
print("o valor de juro é" ,valor_juro)
valor_no_banco=valor_juro+deposito_01_01_2027
print("o valor no banco é" ,valor_no_banco)
"""
sal_bruto=int(input("o valor do salario bruto:"))
taxa_desc_soc=float(input("o valor da taxa de desconto social é:"))
taxa_desc_irs=float(input("o valor da taxa de irs é:"))
valor_desc_soc=sal_bruto*taxa_desc_soc
print("o valor do desconto social é" ,valor_desc_soc)
valor_desc_irs=sal_bruto*taxa_desc_irs
print("o valor do desconto do irs é", valor_desc_irs)
sal_liquido=sal_bruto-valor_desc_soc-valor_desc_irs
print("o valor do salario liquido é" ,sal_liquido)

