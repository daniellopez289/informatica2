#ifndef RED_H
#define RED_H

#include "enrutador.h"
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <vector>

class red{
private:
    map<string, router*> enrutadores;

public:
    red();
    map<string, router*>getEnrutadores();
    void agregarEnrutador(string _nombreR);
    void eliminarEnrutador(string _nombreR);
    void actualizarTablaEnrutamiento(string _nombreR1, string _nombreR2, int _costo);
    void leerArchivo(string _nArchivo);
    void guardarArchivo(string _nArchivo);
    int costo(string _origen, string _destino);
    vector<string>caminoCorto(string _origen, string _destino);
    void redAleatoria(int _enrutadores);
    void mostrarTablaEnrutadores();

};

#endif // RED_H
