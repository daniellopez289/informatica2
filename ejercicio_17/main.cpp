#include <iostream>
using namespace std;

int main(){
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    int mayor = 0;
    while (numero != 0){
        if (numero > mayor){
            mayor = numero;
        }
        cout << "ingrese un numero: ";
        cin >> numero;
    }
    cout << "El mayor de los numeros ingresados anteriormente es: " << mayor << endl;
    return 0;
}
