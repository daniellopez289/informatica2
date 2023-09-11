#include <iostream>
using namespace std;

int main(){
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    int multiplo = 1;
    int resultado = 0;
    while (multiplo != 11){
        resultado += numero*multiplo;
        cout << numero << " x "  << multiplo << " = " <<  resultado << endl;
        resultado = 0;
        multiplo += 1;
    }
    return 0;
}
