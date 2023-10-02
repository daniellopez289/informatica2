#include <iostream>
#include <string>

using namespace std;

int sumaNumerica(const string& _cad, int num);

int main() {
    string cadena;
    int divisionCadena;

    cout << "Ingrese la cadena numerica: ";
    cin >> cadena;
    cout << "Ingrese la cantidad total de caracteres por subcadena: ";
    cin >> divisionCadena;

    int resultado = sumaNumerica(cadena, divisionCadena);
    cout << "Original: " << cadena << endl;
    cout << "Suma: " << resultado << endl;

    return 0;
}

int sumaNumerica(const string& _cad, int num) {
    string cadena = _cad;
    while (cadena.length() % num != 0) {
        cadena = "0" + cadena;
    }
    int resultado = 0;
    for (int i = 0; i < cadena.length(); i += num) {
        int numero = 0;
        for (int j = 0; j < num; j++) {
            numero = numero * 10 + (cadena[i + j] - '0');
        }
        resultado += numero;
    }
    return resultado;
}
