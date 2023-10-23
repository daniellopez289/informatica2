#include <iostream>
#include <fstream> //tiene los metodos para crear archivos
#include <sstream> // metodos para los string numericos
#include <bitset> // para convertir los caracteres al equivalente binario
using namespace std;

string codificarBinarioMetodo1(string _binario, int _semilla);
string codificarBinarioMetodo2(string _binario, int _semilla);
string decodificarBinarioMetodo1(string _codificado, int _semilla);
string decodificarBinarioMetodo2(string _codificado, int _semilla);
string convertirABinario(string _linea);
char binarioANumero(string _linea);
void registrarUsuario(string _documento, string _clave, string _saldo);
void registrarAdministrador(string _documento, string _clave);
bool validarAdministrador(string _documento, string _clave);
bool validarUsuario(string _documento, string _clave);

int main(){
    int semilla, metodo;
    string nombreArchivo, line;
    cout << "ingrese el nombre del archivo: ";
    cin >> nombreArchivo;
    line = convertirABinario(nombreArchivo);
    cout << "binario: " << line << '\n' << endl;
    cout << "Ingrese el metodo de codificafio: ";
    cin >> metodo;
    cout << "Ingrese la semilla: ";
    cin >> semilla;
    string codificado;
    if(metodo == 1){
        codificado = codificarBinarioMetodo1(line, semilla);
        cout << "codificado: " << codificado << '\n' << endl;
    }
    else{
        codificado = codificarBinarioMetodo2(line, semilla);
        cout << "codificado: " << codificado << "\n" << endl;
    }
    cout << "\n" << "para decodificar el binario: " << endl;
    cout << "ingrese la semilla: ";
    cin >> semilla;
    cout << "ingrese el metodo: ";
    cin >> metodo;
    if(metodo == 1){
        string decodificado = decodificarBinarioMetodo1(codificado, semilla);
        cout << "decosificado: " << decodificado << endl;
    }
    else{
        string decodificado = decodificarBinarioMetodo2(codificado, semilla);
        cout << "decosificado: " << decodificado << endl;
    }




    return 0;
}

string codificarBinarioMetodo1(string _binario, int _semilla){
    string codificado = "";
    int cantCeros = 0;
    int cantUnos = 0;
    int i = 0;

    for (int j = 0; j < _semilla; j++) {  // Primer bloque
        if (_binario[i] == '0') {
            codificado += '1';  // Para los ceros
            cantCeros += 1;
        } else {
            codificado += '0';  // Para los unos
            cantUnos += 1;
        }
        i++;
    }

    while (i < _binario.size()) {
        if (cantCeros == cantUnos) {  // Primera condición
            cantCeros = 0;
            cantUnos = 0;
            for (int j = 0; j < _semilla; j++) {
                if (_binario[i] == '0') {
                    codificado += '1';
                    cantCeros += 1;
                } else {
                    codificado += '0';
                    cantUnos += 1;
                }
                i++;
            }
        } else if (cantCeros > cantUnos) {  // Segunda condición
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < _semilla; j++) {
                if (aux == 1) {
                    if (_binario[i] == '0') {
                        codificado += '1';
                        cantCeros += 1;
                    } else {
                        codificado += '0';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (_binario[i] == '0') {
                        codificado += '0';
                        cantCeros += 1;
                        aux = 1;
                    } else {
                        codificado += '1';
                        cantUnos += 1;
                        aux = 1;
                    }
                }
                i++;
            }
        } else if (cantCeros < cantUnos) {  // Tercera condición
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < _semilla; j++) {
                if (aux == 2) {
                    if (_binario[i] == '0') {
                        codificado += '1';
                        cantCeros += 1;
                    } else {
                        codificado += '0';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (_binario[i] == '0') {
                        codificado += '0';
                        cantCeros += 1;
                        aux = 2;
                    } else {
                        codificado += '1';
                        cantUnos += 1;
                        aux = 2;
                    }
                }
                i++;
            }
        }
    }
    return codificado;
}

string codificarBinarioMetodo2(string _binario, int _semilla){
    string codificado = "";
    int i = 0;
    int semilla1 = _semilla;

    while(i < sizeof(_binario)){
        string temp = "";
        temp = _binario[(semilla1 -1)];
        codificado += temp;
        for(int j = i; j < (semilla1 -1); j++){
            codificado += _binario[j];
        }
        i = semilla1;
        semilla1 += _semilla;
    }
    return codificado;
}

string decodificarBinarioMetodo1(string _codificado, int _semilla){
    string original = "";
    int cantCeros = 0;
    int cantUnos = 0;
    int i = 0;

    for (int j = 0; j < _semilla; j++) {  // Primer bloque
        if (_codificado[j] == '0') {
            original += '1';  // Para los ceros
            cantCeros += 1;
        } else {
            original += '0';  // Para los unos
            cantUnos += 1;
        }
        i++;
    }

    while (i < _codificado.size()) {
        if (cantCeros == cantUnos) {  // Primera condición
            cantCeros = 0;
            cantUnos = 0;
            for (int j = 0; j < _semilla; j++) {
                if (_codificado[i] == '0') {
                    original += '1';
                    cantCeros += 1;
                } else {
                    original += '0';
                    cantUnos += 1;
                }
                i++;
            }
        } else if (cantCeros > cantUnos) {  // Segunda condición
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < _semilla; j++) {
                if (aux == 1) {
                    if (_codificado[i] == '0') {
                        original += '1';
                        cantCeros += 1;
                    } else {
                        original += '0';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (_codificado[i] == '0') {
                        original += '0';
                        cantCeros += 1;
                        aux = 1;
                    } else {
                        original += '1';
                        cantUnos += 1;
                        aux = 1;
                    }
                }
                i++;
            }
        } else if (cantCeros < cantUnos) {  // Tercera condición
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < _semilla; j++) {
                if (aux == 2) {
                    if (_codificado[i] == '0') {
                        original += '1';
                        cantCeros += 1;
                    } else {
                        original += '0';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (_codificado[i] == '0') {
                        original += '0';
                        cantCeros += 1;
                        aux = 2;
                    } else {
                        original += '1';
                        cantUnos += 1;
                        aux = 2;
                    }
                }
                i++;
            }
        }
    }
    return original;
}

string decodificarBinarioMetodo2(string _codificado, int _semilla){
    string original = "";
    int i = 0;
    int semilla1 = _semilla;

    while(i < sizeof(_codificado)){
        string temp = "";
        temp = _codificado[i];
        for(int j = (i+1); j < (semilla1); j++){
            original += _codificado[j];
        }
        original += temp;
        i = semilla1;
        semilla1 += _semilla;
    }
    return original;
}

string convertirABinario(string _linea){
    string binario;
    for(int i = 0; i < _linea.length(); i++){
        bitset<8> bin(_linea[i]);
        binario += bin.to_string();
    }
    return binario;
}

char binarioANumero(string _linea){
    if((_linea.length() % 8) != 0){
        cout << "Error la cadena debe ser multiplo de 8" << endl;
    }
    bitset<8> numero(_linea);
    return static_cast<char>(numero.to_ulong());
}

void registrarUsuario(string _documento, string _clave, string _saldo){
    string _nombreArchivo;
    int metodo, semilla;
    cout << "Ingrese el nombre del archivo: ";
    cin >> _nombreArchivo;
    string nombre = _nombreArchivo + ".txt";
    cout << "Ingrese el metodo de codificación: ";
    cin >> metodo;
    cout << "Ingrese la semilla de codificación: ";
    cin >> semilla;
    string line = convertirABinario(_documento);
    string line1 = convertirABinario(_clave);
    string line2 = convertirABinario(_saldo);
    string datos = line + line1 + line2;
    string codificado;
    if(metodo == 1){
        codificado = codificarBinarioMetodo1(datos, semilla);
    }
    else{
        codificado = codificarBinarioMetodo2(datos, semilla);
    }
    ofstream archivo;
    archivo.open(nombre, ios_base::app);
    archivo << codificado << endl;
    archivo.close();

}

void registrarAdministrador(string _documento, string _clave){
    string _nombreArchivo;
    int metodo, semilla;
    cout << "Ingrese el nombre del archivo: ";
    cin >> _nombreArchivo;
    string nombre = _nombreArchivo + ".txt";
    cout << "Ingrese el metodo de codificacion: ";
    cin >> metodo;
    cout << "ingrese la semilla de codificacion: ";
    cin >> semilla;
    string line = convertirABinario(_documento);
    string line1 = convertirABinario(_clave);
    string datos = line + line1;
    string codificado;
    if(metodo == 1){
        codificado = codificarBinarioMetodo1(datos, semilla);
    }
    else{
        codificado = codificarBinarioMetodo2(datos, semilla);
    }
    ofstream archivo;
    archivo.open(nombre, ios_base::app);
    archivo << codificado << endl;
    archivo.close();
}
bool validarAdministrador(string _documento, string _clave){
    string _nombreArchivo;
    int metodo, semilla;
    cout << "Ingrese el nombre del archivo: ";
    cin >> _nombreArchivo;
    string nombre = _nombreArchivo + ".txt";
    cout << "Ingrese el metodo de codificacion: ";
    cin >> metodo;
    cout << "ingrese la semilla de codificacion: ";
    cin >> semilla;
    string line = convertirABinario(_documento);
    string line1 = convertirABinario(_clave);
    string datos = line + line1;
    string codificado;
    if(metodo == 1){
        codificado = codificarBinarioMetodo1(datos, semilla);
    }
    else{
        codificado = codificarBinarioMetodo2(datos, semilla);
    }
    string linea;
    bool encontrado = false;
    ifstream archivo;
    archivo.open(nombre);
    while(getline(archivo, linea)){
        if(codificado == linea){
            encontrado = true;
            return encontrado;
        }
    }
    archivo.close();
}

bool validarUsuario(string _documento, string _clave){
    string _nombreArchivo;
    int metodo, semilla;
    cout << "Ingrese el nombre del archivo: ";
    cin >> _nombreArchivo;
    string nombre = _nombreArchivo + ".txt";
    cout << "Ingrese el metodo de codificacion: ";
    cin >> metodo;
    cout << "ingrese la semilla de codificacion: ";
    cin >> semilla;
    string line = convertirABinario(_documento);
    string line1 = convertirABinario(_clave);
    string datos = line + line1;
    string codificado;
    if(metodo == 1){
        codificado = codificarBinarioMetodo1(datos, semilla);
    }
    else{
        codificado = codificarBinarioMetodo2(datos, semilla);
    }
    string linea;
    bool encontrado = false;
    ifstream archivo;
    archivo.open(nombre);
    int i = codificado.length();
    while(getline(archivo, linea)){
        linea = linea[0, i];
        if(codificado == linea){
            encontrado = true;
            return encontrado;
        }
    }
    archivo.close();
}

