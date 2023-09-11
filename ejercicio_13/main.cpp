#include <iostream>
using namespace std;

int main(){
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    if (numero == 0){
        cout << " todos los numeros son divisores del " << numero;
        }
    else{
        int divisor = 1;
        while (divisor <= numero){
            if ((numero % divisor) == 0){
                cout << divisor << " es divsor de " << numero << endl;
            }
            divisor += 1;
        }
    }
        return 0;
}
