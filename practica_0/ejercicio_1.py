"""
programa que muestra la siguiente imagen en pantalla:
    A           A
    AB         BA
    ABC       CBA
    ABCD     DCBA
    ABCDE   EDCBA
    ABCDEF FEDCBA
    ABCDEFGFEDCBA
"""
letras = ["A","B","C","D","E","F","G"]
espacio = " "
resultado = ""
aux = 0
long = 7
nuevasletras = ""
cantespacios = 11

while aux < long:
    letra = letras[aux]
    espacios = espacio * cantespacios
    nuevasletras += letra
    resultado += nuevasletras + espacios + nuevasletras[5::-1] + "\n"
    aux +=  1
    cantespacios -= 2



print (resultado)
