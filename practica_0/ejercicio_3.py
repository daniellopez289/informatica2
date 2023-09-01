"""
programa que recibe un numero entero, lo separa por cifras,
cada cifra se eleva a si misma y se suman
"""
numero = int(input("ingrese un número: "))
numeros = []
def separar(x):
    if x < 0:
        x = x * (-1)
    while x > 0 or x:
        numeros.append(x % 10)
        x = x // 10
        
separar(numero)
dimension = len(numeros)
aux = 0 
suma = 0
while aux < dimension:
    numero2 = numeros[aux]
    numero2 = numero2 ** numero2
    suma += numero2
    aux +=1
    
print(suma)