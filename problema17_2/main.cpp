#include <iostream>
using namespace std;

int numerosAmigables(int num);

int main(){
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    int amigables = numerosAmigables(numero);
    if(amigables == 0){
        cout << "No hay numeros amigables con: " << numero << endl;
    }
    else{
        cout << "Suma: " << amigables << endl;
    }

    return 0;
}

int numerosAmigables(int num){
    int num1 = 0;
    int auxNum = 0;
    for(int i = 1; i < (num - 1); i++){
        if((num % i) == 0){
            num1 += i;
        }
    }
    for(int i = 1; i < (num1 -1); i++){
        if((num1 % i) == 0){
            auxNum += i;
        }
    }
    if(auxNum == num){
        int suma = num1 + num;
        return suma;
    }
    else{
        return 0;
    }
}
