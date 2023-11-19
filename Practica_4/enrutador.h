#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

class router{
private:
    string nombreR;
    map<string, int> tabla;

public:
    router();
    router(string _nombreR);
    string getNombre();
    map<string, int> getTabla();
    void setNombre(string _nombreR);
    void setTabla(map<string, int>t);
    void actualizarTabla(string _destino, int _costo);
    void cambiarEnlace(string _destino, int _costo);
    void eliminarEnlace(string _destino);
    void mostrarTabla();

};

#endif // ENRUTADOR_H
