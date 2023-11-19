#include "enrutador.h"
#include <iostream>
using namespace std;

router::router(){}

router::router(string _nombreR){
    nombreR = _nombreR;
}

string router::getNombre(){
    return nombreR;
}

map<string, int> router::getTabla(){
    return tabla;
}

void router::setNombre(string _nombreR){
    nombreR = _nombreR;
}

void router::setTabla(map<string, int> t){
    tabla = t;
}

void router::actualizarTabla(string _destino, int _costo){
    tabla[_destino] = _costo;
}

void router::cambiarEnlace(string _destino, int _costo){
    tabla[_destino] = _costo;
}

void router::eliminarEnlace(string _destino){
    tabla.erase(_destino);
}

void router::mostrarTabla(){
    cout << "Tabla de enrutamiento de: " << nombreR << "\n";
    cout << "Detino\tCosto\n";
    for(auto it = tabla.begin(); it != tabla.end(); it++){
        cout << it->first << "\t" << it -> second << "\n";
    }
    cout << endl;
}
