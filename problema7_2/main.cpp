#include <iostream>
using namespace std;

string nuevaCadena(string _cad);

int main(){
    string cadena;
    //string* cad = &cadena;
    cout << "Ingrese la cadena de caracteres: ";
    cin >> cadena;
    cout << "Original: " << cadena << endl;
    string sinRepetidos = nuevaCadena(cadena);
    cout << "Sin repetidos: " << sinRepetidos << endl;

    return 0;
}

string nuevaCadena(string _cad){
    string resultado = "";
    for(int i = 0; i < _cad.length(); i++){
        bool repetido = false;
        for (int j = 0; j < resultado.length(); j++) {
            if (_cad[i] == resultado[j]) {
                repetido = true;
                break;
            }
        }
        if (!repetido) {
            resultado += _cad[i];
        }
    }
    return resultado;
}
