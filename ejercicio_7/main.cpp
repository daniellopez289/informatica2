#include <iostream>
using namespace std;

int main(){
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    int numeroA = numero;
    int suma = 0;
    while (numeroA > 0){
        suma += numeroA;
        numeroA -= 1;
    }
    cout << "La suma de todos los numeros de 0 hasta " << numero << " es " << suma;
    return 0;
}
