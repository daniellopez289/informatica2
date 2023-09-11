#include <iostream>
using namespace std;

int main(){
    int numeroA, numeroB, producto;
    int residuo, mcd, mcm;
    cout << "Ingrese un numero: ";
    cin >> numeroA;
    cout << "ingrese otro numero: ";
    cin >> numeroB;
    residuo = 1;
    producto = numeroA * numeroB;
    while (residuo != 0){
        residuo = numeroA % numeroB;
        if (residuo != 0){
            numeroA = numeroB;
            numeroB = residuo;
        }
        else{
            mcd = numeroB;
        }
    }
    mcm = producto / mcd;

    cout << "El MCM de " << numeroA << " y " << numeroB << " es: " << mcm;
    return 0;
}
