#include <iostream>
using namespace std;

int main (){
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    int suma = 0;
    while (numero != 0){
        suma += numero;
        cout << "Ingrese un numero: ";
        cin >> numero;

    }
    cout << "La suma de tosos los numeros ingresados enteriormente es: " << suma;
    return 0;
}
