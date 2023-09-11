#include <iostream>
using namespace std;

int main(){
    string numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    int cantidad;

    for(int i=0; i<=numero.size();i++){
        cantidad = i;
    }
    cout << "La cantidad de digitos de: " << numero << " es: " << cantidad << endl;
    return 0;
}
