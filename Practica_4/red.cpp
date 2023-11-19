#include "red.h"

red::red(){
    enrutadores.clear();
}

map<string, router*> red::getEnrutadores(){
    return enrutadores;
}

void red::agregarEnrutador(string _nombreR){
    enrutadores[_nombreR] = new router(_nombreR);
}

void red::eliminarEnrutador(string _nombreR){
    enrutadores.erase(_nombreR);
}

void red::actualizarTablaEnrutamiento(string _nombreR1, string _nombreR2, int _costo){
    enrutadores[_nombreR1]->actualizarTabla(_nombreR2, _costo);
    enrutadores[_nombreR2]->actualizarTabla(_nombreR1, _costo);
}

void red::leerArchivo(string _nArchivo){
    ifstream archivo(_nArchivo);
    string linea;
    vector<string> nomsEnrutadores;

    if (archivo.is_open()){
        if (getline(archivo, linea)){
            stringstream ss(linea);
            string nombre;
            while (getline(ss, nombre, ';')) {
                nomsEnrutadores.push_back(nombre);
                agregarEnrutador(nombre);
            }
        }
        // Leer las líneas restantes para obtener los costos de los enlaces
        int i = 0;
        while (getline(archivo, linea)){
            stringstream ss(linea);
            string costostr;
            // Ignorar el nombre del enrutador al principio de la línea
            getline(ss, costostr, ';');
            int j = 0;
            while (getline(ss, costostr, ';')){
                if (i != j) { // Si el enrutador destino no es el mismo que el actual
                    istringstream costoStream(costostr);
                    int costo;
                    costoStream >> costo;
                    actualizarTablaEnrutamiento(nomsEnrutadores[i], nomsEnrutadores[j], costo); // Actualiza la tabla de enrutamiento
                }
                j++;
            }
            i++;
        }
        archivo.close();
    }
    else{
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

void red::guardarArchivo(string _nArchivo){
    ofstream archivo(_nArchivo);
    if (archivo.is_open()){
        // Escribir los nombres de los enrutadores en la primera línea
        for (auto it = enrutadores.begin(); it != enrutadores.end(); ++it){
            archivo  << it->second->getNombre() << ";"; // Escribe el nombre del enrutador seguido de ';'
        }
        archivo << "\n";
        // Escribir los costos de los enlaces en las líneas restantes
        for (auto it1 = enrutadores.begin(); it1 != enrutadores.end(); ++it1) { // Recorre el mapa de enrutadores
            archivo << it1->second->getNombre(); // Escribe el nombre del enrutador
            for (auto it2 = enrutadores.begin(); it2 != enrutadores.end(); ++it2) { // Recorre el mapa de enrutadores
                archivo << ";";
                if (it1 == it2) {
                    archivo << "0";
                }
                else if (it1->second->getTabla().count(it2->first)) {
                    archivo << it1->second->getTabla()[it2->first]; // Escribe el costo del enlace
                }
                else {
                    archivo << "inf";
                }
            }
            archivo << "\n";
        }
        archivo.close();
    }
    else {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

int red::costo(string _origen, string _destino){
    vector<string> camino = caminoCorto(_origen, _destino); // Obtiene el camino más corto
    int costoTotal = 0;
    for (int i = 0; i < camino.size() - 1; i++) {
        costoTotal += enrutadores[camino[i]]->getTabla()[camino[i+1]]; // Suma el costo del enlace al costo total
    }
    return costoTotal;
}

vector<string> red::caminoCorto(string _origen, string _destino){
    map<string, int> distancias; // Declara un mapa para las distancias
    map<string, string> predecesores; // Declara un mapa para los predecesores
    vector<string> nodosNoVisitados; // Declara un vector para los nodos no visitados
    // Inicializar las distancias y predecesores
    for (auto it = enrutadores.begin(); it != enrutadores.end(); ++it) {
        string nombreR = it->second->getNombre();  // Obtiene el nombre del enrutador
        distancias[nombreR] = numeric_limits<int>::max();  // Inicializa la distancia a infinito
        predecesores[nombreR] = "";  // Inicializa el predecesor a vacío
        nodosNoVisitados.push_back(nombreR);  // Añade el enrutador a los nodos no visitados
    }

    distancias[_origen] = 0;

    while (!nodosNoVisitados.empty()) { // Mientras haya nodos no visitados
        // Encontrar el nodo no visitado con la distancia más corta
        string nodoActual = "";
        int distanciaMinima = numeric_limits<int>::max();
        for (auto it = nodosNoVisitados.begin(); it != nodosNoVisitados.end(); ++it) {
            string nodo = *it;  // Obtiene el valor del nodo actual
            if (distancias[nodo] < distanciaMinima) {
                distanciaMinima = distancias[nodo];// Actualiza la distancia mínima
                nodoActual = nodo; // Actualiza el nodo actual
            }
        }

        // Eliminar el nodo actual de los nodos no visitados
        nodosNoVisitados.erase(remove(nodosNoVisitados.begin(), nodosNoVisitados.end(), nodoActual), nodosNoVisitados.end());
        // Actualizar las distancias de los vecinos del nodo actual
        map<string, int> vecinos = enrutadores[nodoActual]->getTabla(); // Obtiene los vecinos del nodo actual
        for (auto& vecino : vecinos) { // Recorre los vecinos
            int distanciaAlternativa = distancias[nodoActual] + vecino.second; // Calcula la distancia alternativa
            if (distanciaAlternativa < distancias[vecino.first]) { // Si la distancia alternativa es menor que la distancia actual
                distancias[vecino.first] = distanciaAlternativa; // Actualiza la distancia
                predecesores[vecino.first] = nodoActual; // Actualiza el predecesor
            }
        }
    }
    // Reconstruir el camino desde el destino al origen
    vector<string> camino; // Declara un vector para el camino
    for (string nodo = _destino; nodo != ""; nodo = predecesores[nodo]) { // Recorre los predecesores desde el destino hasta el origen
        camino.insert(camino.begin(), nodo); // Inserta el nodo al principio del camino
    }

    return camino; // Devuelve el camino
}

void red::redAleatoria(int _enrutadores){
    srand(time(0)); // Inicializa la semilla del generador de números aleatorios
    for (int i = 0; i < _enrutadores; i++) { // Para cada enrutador
        string id(1, 'A' + i); // Genera un nombre de enrutador
        agregarEnrutador(id); // Agrega el enrutador
        for (int j = 0; j < i; j++) { // Para cada enrutador anterior
            string idVecino(1, 'A' + j); // Genera un nombre de enrutador
            int costo = rand() % 10 + 1; // Genera un costo aleatorio entre 1 y 10
            actualizarTablaEnrutamiento(id, idVecino, costo); // Actualiza la tabla de enrutamiento del enrutador
            actualizarTablaEnrutamiento(idVecino, id, costo); // Actualiza la tabla de enrutamiento del enrutador vecino
        }
    }
}

void red::mostrarTablaEnrutadores(){
    for (auto it = enrutadores.begin(); it != enrutadores.end(); ++it) {
        auto& par = *it;  // Obtiene la referencia al par clave-valor actual
        par.second->mostrarTabla(); // Muestra la tabla de enrutamiento del enrutador
    }

}
