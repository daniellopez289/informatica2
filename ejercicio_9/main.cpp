#include <iostream>
using namespace std;

int main(){
    float numero;
    cout << "Ingresee un numero: ";
    cin >> numero;
    float pi = 3.1416;
    float perimetro = (2*(numero*pi));
    float area = (pi*(numero*numero));
    cout << "el perimetro del circulo es: " << perimetro << " y el area del circulo es: " << area;
    return 0;

}
