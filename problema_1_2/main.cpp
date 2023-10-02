#include <iostream>
using namespace std;

int billetes(int);
int monedas(int);

int main(){
    int valor;
    cout << "Ingrese la cantidad de dinero: ";
    cin >> valor;
    int resto = billetes(valor);
    int resto1 = monedas(resto);
    cout << "Faltante: " << resto1 << endl;
}

int billetes(int valor){
    int billetes[6] = {50000,20000,10000,5000,2000,1000};
    for(int i=0; i<6;i++){
        int j=0;
        while (valor > billetes[i]){
            j++;
            valor -= billetes[i];
        }
        cout << billetes[i] << ": " << j << endl;
    }
    return valor;
}

int monedas(int valor){
    int monedas[4] = {500,200,100,50};
    for (int i=0; i<4; i++){
        int j=0;
        if (valor > monedas[i]){
            j++;
            valor -= monedas[i];
        }
        cout << monedas[i] << ": " << j << endl;
    }
    return valor;
}
