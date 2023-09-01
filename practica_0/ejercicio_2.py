# -*- coding: utf-8 -*-
"""
progrma que muestra la siguiente figura en pantalla:
    A           A
    AB         BA
    ABC       CBA
    ABCD     DCBA
    ABCDE   EDCBA
    ABCDEF FEDCBA
    ABCDEFGFEDCBA
    ABCDEF FEDCBA
    ABCDE   EDCBA
    ABCD     DCBA
    ABC       CBA
    AB         BA
    A           A
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

resultado2 = resultado[-16::-1]

print (resultado + resultado2)