#include <iostream>
using namespace std;
#include <cmath>

int main(){
    float numeroA, numeroB;
    cout << "Ingrese el numero A: ";
    cin >> numeroA;
    cout << "Ingrese el numero B: ";
    cin >> numeroB;
    cout << round(numeroA/numeroB) << " es el resultado redondeado";
    return 0;
}
