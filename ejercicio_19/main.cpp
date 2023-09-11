#include <iostream>
using namespace std;

int main(){
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    if (numero % 2 == 0){
        cout << numero << " no es numero primo" << endl;
    }
    else{
        cout << numero << " es un numero primo" << endl;
    }
    return 0;
}
