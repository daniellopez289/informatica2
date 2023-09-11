#include <iostream>
using namespace std;

int main(){
    char letra;
    string alfabetoMinusculo;
    string alfabetoMayusculas;
    cout << "Ingrese una letra: ";
    cin >> letra;
    alfabetoMinusculo = "abcdefghijklmnopqrstuvwxyz";
    alfabetoMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i=0; i<alfabetoMinusculo.size();i++){
        if (alfabetoMinusculo[i] == letra){
            cout << "Letra convertivda: " << alfabetoMayusculas[i] << endl;
        }
    }
    for (int x=0; x<alfabetoMayusculas.size(); x++){
        if (alfabetoMayusculas[x] == letra){
            cout << "Letra convertida: " << alfabetoMinusculo[x] << endl;
                }
            }
    return 0;
}
