#include <iostream>
using namespace std;

int main(){
    int numeroA, numeroB;
    string operador;
    cout << "Ingrese un numero: ";
    cin >> numeroA;
    cout << "Que operacion desea hacer: "<<endl<<"suma = +"<<endl<<"resta = -"<<endl<< "multiplicacion = *"<<endl <<"division = /"<< endl;
    cin >> operador;
    cout << "Ingrese otro numero: ";
    cin >> numeroB;
    if(operador == "+"){
        int suma = numeroA + numeroB;
        cout << "La suma es: " << numeroA << operador << numeroB << " = " << suma;
    }
    if(operador == "-"){
        int resta = numeroA - numeroB;
        cout << "La resta es: " << numeroA << operador << numeroB << " = " << resta;
    }
    if (operador == "*"){
        int producto = numeroA * numeroB;
        cout << "El producto es: " << numeroA << operador << numeroB << " = " << producto;
    }
    if (operador == "/"){
        int cociente = numeroA / numeroB;
        cout << "El cociente es: " << numeroA << operador << numeroB << " = " << cociente;
    }
    return 0;
}
