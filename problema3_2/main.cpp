#include <iostream>
using namespace std;
#include <string>

bool comparacionCadenas(string _cadena1, string _cadena2);

int main(){
    string cadena1, cadena2;
    cout << "Ingrese una cadena de caracteres: " << endl;
    cin >> cadena1;
    cout << "Ingrese otra cadena de caracteres: " << endl;
    cin >> cadena2;

    if(comparacionCadenas(cadena1, cadena2) == true){
        cout << "Las cadenas son iguales." << endl;
    }
    else{
        cout << "Las cadenas son diferentes." << endl;
    }
    return 0;
}

bool comparacionCadenas(string _cadena1, string _cadena2){
    int x = sizeof(_cadena1);
    int y = sizeof(_cadena2);
    if(x == y){
        if(_cadena1 == _cadena2){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
