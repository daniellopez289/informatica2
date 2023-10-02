#include <iostream>
using namespace std;
#include <string>

string numeroACadena(int* _num);

int main(){
    int numero;
    int* num = &numero;
    cout << "Ingrese un numero: " << endl;
    cin >> numero;

    string resultado = numeroACadena(num);
    cout << "El resultado es: " << "'" << resultado << "' " << endl;
    //int suma = numero + resultado;

    return 0;
}

string numeroACadena(int* _num){
    int _numero = *_num;
    string cadena = to_string(_numero);
    return cadena;
}
