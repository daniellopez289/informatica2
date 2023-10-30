#include <iostream>
#include <fstream> //tiene los metodos para crear archivos
#include <sstream> // metodos para los string numericos
#include <bitset> // para convertir a binario o viceversa
#include <string>
#include <map>

using namespace std;

struct Usuario{
    string cedula;
    string clave;
    string saldo;
};
map<string, Usuario> usuarios;

string codificarBinarioMetodo1(string _binario, int _semilla);
string codificarBinarioMetodo2(string _binario, int _semilla);
string decodificarBinarioMetodo1(string _codificado, int _semilla);
string decodificarBinarioMetodo2(string _codificado, int _semilla);
string convertirABinario(string _linea);
char binarioANumero(string _linea);
int pruebaCodificar();
bool verificarAdmin();
void llenarMapaUsuarios();
Usuario verificarUsuario();
void registrarUsuario();
void guardarUsuarios();

int main(){
    int opcionInicial = 0;
    cout << "Seleccione su cargo:\n1. Administrador\n2. Usuario\n";
    cin >> opcionInicial;

    switch (opcionInicial) {
    case 1:
        cout << "Modo administrador" << endl;
        if(verificarAdmin() == true){
            cout << "Registrar usuario" << endl;
            registrarUsuario();
            guardarUsuarios();
        }
        break;
    case 2:
        cout << "Modo usuario" << endl;
        llenarMapaUsuarios();
        Usuario usuario = verificarUsuario();
        int opcionUsuario;
        cout << "Seleccione la opcion que desea.\n1. consultar saldo\n2. retirar dinero\n";
        cin >> opcionUsuario;
        /*switch (opcionUsuario) {
        case 1: // Consultar saldo*/
        if(opcionUsuario == 1){
            cout << "Consulta de saldo" << endl;
            int metodo, semilla;
            cout << "Ingrese el metodo con el que codifico la informacion: ";
            cin >> metodo;
            cout << "Ingrese la semilla: ";
            cin >> semilla;
            string saldo;
            if(metodo == 1){
                saldo = decodificarBinarioMetodo1(usuario.saldo, semilla);
            }
            else{
                saldo = decodificarBinarioMetodo2(usuario.saldo, semilla);
            }
            int aux = 7;
            string cadena8;
            char saldo1;
            for(int i = 0; i < sizeof(saldo); i ++){
                if(i == aux){
                    char aux1 = binarioANumero(cadena8);
                    saldo1 += aux1;
                    aux += 8;
                }
                else{
                    cadena8 += saldo[i];
                }
            }
            int saldoOperativo = static_cast<int>(saldo1);
            saldoOperativo = saldoOperativo - 1000;
            cout << "La transaccion tiene un cobro de 1000 COP\n Su saldo: " << saldoOperativo << endl;
            cadena8 = to_string(saldoOperativo);
            cadena8 = convertirABinario(cadena8);
            if(metodo == 1){
                usuario.saldo = codificarBinarioMetodo1(cadena8, semilla);
            }
            else{
                usuario.saldo = codificarBinarioMetodo2(cadena8, semilla);
            }
            usuarios[usuario.cedula] = usuario;
            guardarUsuarios();
        }
        //break;

        else{
            cout << "Retirar dinero" << endl;
            int metodo, semilla;
            cout << "Ingrese el metodo con el que codifico la informacion: ";
            cin >> metodo;
            cout << "Ingrese la semilla: ";
            cin >> semilla;
            string saldo;
            if(metodo == 1){
                saldo = decodificarBinarioMetodo1(usuario.saldo, semilla);
            }
            else{
                saldo = decodificarBinarioMetodo2(usuario.saldo, semilla);
            }
            int aux = 7;
            string cadena8;
            char saldo1;
            for(int i = 0; i < sizeof(saldo); i ++){
                if(i == aux){
                    char aux1 = binarioANumero(cadena8);
                    saldo1 += aux1;
                    aux += 8;
                }
                else{
                    cadena8 += saldo[i];
                }
            }
            int saldoOperativo = static_cast<int>(saldo1);
            saldoOperativo = saldoOperativo - 1000;
            cout << "La transaccion tiene un cobro de 1000 COP\n Su saldo: " << saldoOperativo << endl;
            int retirar;
            cout << "Ingrese la cantidad que desea retirar: ";
            cin >> retirar;
            if(retirar < saldoOperativo){
                saldoOperativo = saldoOperativo - retirar;
                cout << "Transaccion exitoso\n Su saldo: " << saldoOperativo << endl;
            }
            else{
                cout << "Saldo insuficiente.\nverifique su saldo primeramente." << endl;
                saldoOperativo += 1000;
            }
            cadena8 = to_string(saldoOperativo);
            cadena8 = convertirABinario(cadena8);
            if(metodo == 1){
                usuario.saldo = codificarBinarioMetodo1(cadena8, semilla);
            }
            else{
                usuario.saldo = codificarBinarioMetodo2(cadena8, semilla);
            }
            usuarios[usuario.cedula] = usuario;
            guardarUsuarios();
        }

        break;
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

int pruebaCodificar(){ //para registrar el usuario admin
    ofstream archivo;
    string nombre;
    int semilla;
    int metodo;
    string clave;
    cout << "Ingrese la clave: ";
    cin >> clave;
    cout << "Ingrese la semilla: ";
    cin >> semilla;
    cout << "Ingrese el metodo de codificacion (1 o 2): ";
    cin >> metodo;
    string binario = convertirABinario(clave);
    string codificado;

    if(metodo == 1){
        codificado = codificarBinarioMetodo1(binario, semilla);
    }
    else{
        codificado = codificarBinarioMetodo2(binario, semilla);
    }

    cout << "Ingrese el nombre del archivo donde desea guardar los datos: ";
    cin >> nombre;
    string nombreArchivo = nombre + ".txt";
    archivo.open(nombreArchivo);
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }
    else{
        archivo << codificado << endl;
        cout << "Se registraron los datos correctamente" << endl;
    }
    archivo.close();
    return 0;
}

bool verificarAdmin(){
    ifstream archivo;
    string clave;
    archivo.open("sudo.txt");
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }
    else{
        getline(archivo, clave);
        archivo.close();
    }

    int aux = 0;
    while(aux < 3){
        string claveIngresada;
        string codificar = codificarBinarioMetodo1(claveIngresada, 4);

        if(clave == codificar){
            aux = aux + 4;
            cout << "Administrador encontrado" << endl;
            return true;
        }
        else{
            aux ++;
            cout << "Clave incorrecta, intente una nueva" << endl;
        }
    }
    cout << "Usuario no encontrado" << endl;
    return false;
}

void llenarMapaUsuarios(){
    ifstream archivo;
    string line;
    archivo.open("usuarios.txt");
    while(getline(archivo,line)){
        stringstream flujo (line);
        string datos;
        while(getline(flujo, datos, ';')){
            Usuario usuario;
            stringstream datoSeparado (datos);
            datoSeparado >> usuario.cedula;
            datoSeparado >> usuario.clave;
            datoSeparado >> usuario.saldo;
            usuarios[usuario.cedula] = usuario;
        }
    }
    archivo.close();
}

Usuario verificarUsuario(){
    string cedula, clave;
    cout << "Ingrese la cédula: ";
    cin >> cedula;
    cout << "Ingrese la clave: ";
    cin >> clave;
    string nuevaClave = convertirABinario(clave);
    int metodo, semilla;
    cout << "Ingrese el metodo con el que se codifico la informacion: ";
    cin >> metodo;
    cout << "Ingrese la semilla con la que se codifico la informacion: ";
    cin >> semilla;

    if(metodo == 1){
        clave = codificarBinarioMetodo1(nuevaClave, semilla);
    }
    else{
        clave = codificarBinarioMetodo2(nuevaClave, semilla);
    }
    if (usuarios.count(cedula) > 0 && usuarios[cedula].clave == clave){
        cout << "Usuario existente. " << endl;
        return usuarios[cedula];
    }
    else {
        cout << "Usuario no encontrado.\n";
        exit(0);
    }
}

void registrarUsuario(){
    Usuario usuario;
    bool cedula = false;
    string cedula1, clave, saldo;
    int metodo, semilla;
    cout << "Ingrese el metodo de codificacion deseado (1 o2): ";
    cin >> metodo;
    cout << "Ingrese la semilla de codificación: ";
    cin >> semilla;

    while(!cedula){
        cout << "Ingrese su cedula: ";
        cin >> cedula1;
        cedula1 = convertirABinario(cedula1);
        if(metodo == 1){
            usuario.cedula = codificarBinarioMetodo1(cedula1, semilla);
        }
        else{
            usuario.cedula =codificarBinarioMetodo2(cedula1, semilla);
        }
        if(usuarios.count(usuario.cedula) > 0){
            cout << "Usuario existente" << endl;
        }
        else{
            cedula = true;
        }
    }

    cout << "Ingrese la clave: ";
    cin >> clave;
    cout << "Ingrese el saldo: ";
    cin >> saldo;
    clave = convertirABinario(clave);
    saldo = convertirABinario(saldo);

    if(metodo == 1){
        usuario.clave = codificarBinarioMetodo1(clave,semilla);
        usuario.saldo = codificarBinarioMetodo1(saldo, semilla);
    }
    else{
        usuario.clave = codificarBinarioMetodo2(clave,semilla);
        usuario.saldo = codificarBinarioMetodo2(saldo, semilla);
    }
    usuarios[usuario.cedula] = usuario;
}

void guardarUsuarios(){
    ofstream archivo;
    archivo.open("usuarios.txt");
    for(auto& usuario : usuarios){
        archivo << usuario.second.cedula << " " << usuario.second.clave << " " << usuario.second.saldo << ";";
    }
    archivo.close();
}
