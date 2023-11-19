#include <iostream>
#include <fstream> //tiene los metodos para crear archivos
#include <sstream> // metodos para los string numericos
#include <bitset> // para convertir a binario o viceversa
#include <string>
#include <map>
#include <vector>
#include <limits>

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
int pruebaCodificar();
bool verificarAdmin();
void llenarMapaUsuarios();
Usuario verificarUsuario();
void registrarUsuario();
void guardarUsuarios();
int binarioANumero1(string linea_binaria);

int main(){
    int opcionInicial = 0;
    while (true) {
        cout << "Seleccione su cargo:\n1. Administrador\n2. Usuario\n";
        cin >> opcionInicial;

        if (cin.fail() || opcionInicial < 1 || opcionInicial > 2) {
            cin.clear();  // Limpiar el indicador de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
            cout << "Entrada incorrecta, elige nuevamente\n";
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    }

    switch (opcionInicial) {
    case 1:
        cout << "Modo administrador" << endl;
        //pruebaCodificar();
        if(verificarAdmin()){
            cout << "Registrar usuario" << endl;
            registrarUsuario();
            guardarUsuarios();
            cout << "Usuario registrado con exito." << endl;
        }
        break;
    case 2:
        cout << "Modo usuario" << endl;
        llenarMapaUsuarios();
        Usuario usuario = verificarUsuario();
        int opcionUsuario = 0;
        while (true) {
            cout << "Seleccione una opcion:\n1. Verificar saldo\n2. Retirar dinero\n";
            cin >> opcionUsuario;

            if (cin.fail() || opcionUsuario < 1 || opcionUsuario > 2) {
                cin.clear();  // Limpiar el indicador de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                cout << "Entrada incorrecta, elige nuevamente\n";
            } else {
                break;  // Salir del bucle si la entrada es válida
            }
        }
        if (opcionUsuario == 1) {
            cout << "Consulta de saldo" << endl;
            int metodo = 0, semilla;
            while(metodo < 1 || metodo > 2){
                cout << "Ingrese el metodo con el que codifico la informacion (1 o 2): ";
                cin >> metodo;
                if (cin.fail() || metodo < 1 || metodo > 2) {
                    cin.clear();  // Limpiar el indicador de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                    cout << "Entrada incorrecta, elige nuevamente\n";
                } else {
                    break;  // Salir del bucle si la entrada es válida
                }
            }

            while (true) {
                cout << "Ingrese la semilla: ";
                cin >> semilla;

                if (cin.fail()) {
                    cin.clear();  // Limpiar el indicador de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                    cout << "Entrada incorrecta, elige nuevamente\n";
                } else {
                    break;  // Salir del bucle si la entrada es válida
                }
            }
            string saldo;
            if (metodo == 1) {
                saldo = decodificarBinarioMetodo1(usuario.saldo, semilla);
            }
            else {
                saldo = decodificarBinarioMetodo2(usuario.saldo, semilla);
            }

            int saldoOperativo = binarioANumero1(saldo);
            cout << saldoOperativo << endl;
            saldoOperativo = saldoOperativo - 1000;

            cout << "La transaccion tiene un cobro de 1000 COP\n Su saldo: " << saldoOperativo << endl;
                    string cadena8;
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
            int metodo = 0, semilla;
            while(metodo < 1 || metodo > 2){
                cout << "Ingrese el metodo con el que codifico la informacion (1 o 2): ";
                cin >> metodo;
                if (cin.fail() || metodo < 1 || metodo > 2) {
                    cin.clear();  // Limpiar el indicador de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                    cout << "Entrada incorrecta, elige nuevamente\n";
                } else {
                    break;  // Salir del bucle si la entrada es válida
                }
            }

            while (true) {
                cout << "Ingrese la semilla: ";
                cin >> semilla;

                if (cin.fail()) {
                    cin.clear();  // Limpiar el indicador de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                    cout << "Entrada incorrecta, elige nuevamente\n";
                } else {
                    break;  // Salir del bucle si la entrada es válida
                }
            }
            string saldo;
            if (metodo == 1) {
                saldo = decodificarBinarioMetodo1(usuario.saldo, semilla);
            }
            else {
                saldo = decodificarBinarioMetodo2(usuario.saldo, semilla);
            }

            int saldoOperativo = binarioANumero1(saldo);
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
            string cadena8;
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

string codificarBinarioMetodo1(string _binario, int _semilla){ //divide la cadena en subcadenas con igual cantidad de caracteres que la semilla, añade esta informacion a un vector y codifica la informacion segun las condiciones
    string codificado = "";
    int cantCeros = 0;
    int cantUnos = 0;
    int bloqueActual = 0;
    vector<string> dividido;
    int aux = 0;

    int i = 0;
    while (i < _binario.size()) {
        if (aux < _semilla) {
            dividido.push_back(_binario.substr(i, _semilla));
            aux = 0;
            i += _semilla;
        }
    }

    while (bloqueActual < dividido.size()) {
        string local = dividido.at(bloqueActual);

        if (cantCeros == cantUnos) {
            cantCeros = 0;
            cantUnos = 0;
            for (int j = 0; j < local.size(); j++) {
                if (local[j] == '0') {
                    codificado += '1';
                    cantCeros += 1;
                } else {
                    codificado += '0';
                    cantUnos += 1;
                }
            }
        }
        else if (cantCeros > cantUnos) {
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < local.size(); j++) {
                if (aux == 1) {
                    if (local[j] == '0') {
                        codificado += '1';
                        cantCeros += 1;
                    } else {
                        codificado += '0';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (local[j] == '0') {
                        codificado += '0';
                        cantCeros += 1;
                        aux = 1;
                    } else {
                        codificado += '1';
                        cantUnos += 1;
                        aux = 1;
                    }
                }
            }
        }
        else if (cantCeros < cantUnos) {
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < local.size(); j++) {
                if (aux == 2) {
                    if (local[j] == '0') {
                        codificado += '1';
                        cantCeros += 1;
                    } else {
                        codificado += '0';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (local[j] == '0') {
                        codificado += '0';
                        cantCeros += 1;
                        aux ++;
                    } else {
                        codificado += '1';
                        cantUnos += 1;
                        aux ++;
                    }
                }
            }
        }
        bloqueActual++;
    }

    return codificado;
}

string codificarBinarioMetodo2(string _binario, int _semilla){//divide la cadena en subcadenas con igual cantidad de caracteres que la semilla, añade esta informacion a un vector y codifica la informacion segun las condiciones
    string codificado = "";
    int i = 0;
    int aux = 0;
    vector<string> dividido;
    while (i < _binario.size()) {
        if (aux < _semilla) {
            dividido.push_back(_binario.substr(i, _semilla));
            aux = 0;
            i += _semilla;
        }
    }
    int bloqueActual = 0;

    while(bloqueActual < dividido.size()){
        string local = dividido[bloqueActual];
        string temp = "";
        temp = local[local.size()-1];
        codificado += temp;
        for(int j = 0; j < (local.size()-1); j++){
            codificado += local[j];
        }
        bloqueActual++;
    }
    return codificado;
}

string decodificarBinarioMetodo1(string _codificado, int _semilla){//divide la cadena en subcadenas con igual cantidad de caracteres que la semilla, añade esta informacion a un vector y decodifica la informacion segun las condiciones
    string original = "";
    int cantCeros = 0;
    int cantUnos = 0;
    vector<string> dividido;
    int aux = 0;

    int i = 0;
    while (i < _codificado.size()) {
        if (aux < _semilla) {
            dividido.push_back(_codificado.substr(i, _semilla));
            aux = 0;
            i += _semilla;
        }
    }
    int bloqueActual = 0;
    while (bloqueActual < dividido.size()) {
        string local = dividido.at(bloqueActual);
        if (cantCeros == cantUnos) {  // Primera condición
            cantCeros = 0;
            cantUnos = 0;
            for (int j = 0; j < local.size(); j++) {
                if (local[j] == '1') { // Cambio de 0 a 1 y viceversa
                    original += '0';
                    cantCeros += 1;
                } else {
                    original += '1';
                    cantUnos += 1;
                }
            }
        } else if (cantCeros > cantUnos) {  // Segunda condición
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < local.size(); j++) {
                if (aux == 1) {
                    if (local[j] == '1') {
                        original += '0';
                        cantCeros += 1;
                    } else {
                        original += '1';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (local[j] == '1') {
                        original += '1';
                        cantUnos += 1;
                        aux = 1;
                    } else {
                        original += '0';
                        cantCeros += 1;
                        aux = 1;
                    }
                }
            }
        } else if (cantCeros < cantUnos) {  // Tercera condición
            cantCeros = 0;
            cantUnos = 0;
            int aux = 0;
            for (int j = 0; j < local.size(); j++) {
                if (aux == 2) {
                    if (local[j] == '1') {
                        original += '0';
                        cantCeros += 1;
                    } else {
                        original += '1';
                        cantUnos += 1;
                    }
                    aux = 0;
                } else {
                    if (local[j] == '1') {
                        original += '1';
                        cantUnos += 1;
                        aux ++;
                    } else {
                        original += '0';
                        cantCeros += 1;
                        aux ++;
                    }
                }
            }
        }
        bloqueActual++;
    }
    return original;
}

string decodificarBinarioMetodo2(string _codificado, int _semilla){//divide la cadena en subcadenas con igual cantidad de caracteres que la semilla, añade esta informacion a un vector y decodifica la informacion segun las condiciones
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

string convertirABinario(string _linea){ //convierte un string a un binario y lo retorna
    string binario;
    for(int i = 0; i < _linea.length(); i++){
        bitset<8> bin(_linea[i]);
        binario += bin.to_string();
    }
    return binario;
}

int binarioANumero1(string linea_binaria) {
    if (linea_binaria.empty()) {
        return 0;  // Tratar cadenas vacías como vacías o puedes manejar el error de otra manera.
    }

    string resultado;

    for (size_t i = 0; i < linea_binaria.length(); i += 8) {
        string subcadena = linea_binaria.substr(i, 8);
        bitset<8> numero(subcadena);
        resultado += static_cast<char>(numero.to_ulong());
    }
    int resultado1 = stoi(resultado);
    return resultado1;
}

int pruebaCodificar(){ //para registrar el usuario admin
    ofstream archivo;
    string nombre;
    int semilla;
    int metodo = 0;
    string clave;
    cout << "Ingrese la clave: ";
    cin >> clave;
    cout << "Ingrese el metodo de codificacion (1 o 2): ";
    while(metodo < 1 || metodo > 2){
        cout << "Ingrese el metodo con el que codifico la informacion (1 o 2): ";
        cin >> metodo;
        if (cin.fail() || metodo < 1 || metodo > 2) {
            cin.clear();  // Limpiar el indicador de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
            cout << "Entrada incorrecta, elige nuevamente\n";
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    }

    while (true) {
        cout << "Ingrese la semilla: ";
        cin >> semilla;

        if (cin.fail()) {
            cin.clear();  // Limpiar el indicador de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
            cout << "Entrada incorrecta, elige nuevamente\n";
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    }

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

bool verificarAdmin(){//abre el archivo sudo, toma los datos y los compara con los ingresado
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
        cout << "Ingrese la clave: ";
        cin >> claveIngresada;
        claveIngresada = convertirABinario(claveIngresada);
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

void llenarMapaUsuarios(){ //lee el archivo usuarios.txt, lee linea por linea y despues esta linea la separa sugun la condicion y los añade a una estructura, para despues añador la estructura a un mapa
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

Usuario verificarUsuario(){ //busca en el mapa de usuarios para verificar si el usuario existe
    string cedula, clave;
    cout << "Ingrese la cedula: ";
            cin >> cedula;
    cout << "Ingrese la clave: ";
    cin >> clave;
    int metodo = 0, semilla;
    while(metodo < 1 || metodo > 2){
        cout << "Ingrese el metodo con el que codifico la informacion (1 o 2): ";
        cin >> metodo;
        if (cin.fail() || metodo < 1 || metodo > 2) {
            cin.clear();  // Limpiar el indicador de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
            cout << "Entrada incorrecta, elige nuevamente\n";
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    }

    while (true) {
        cout << "Ingrese la semilla: ";
        cin >> semilla;

        if (cin.fail()) {
            cin.clear();  // Limpiar el indicador de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
            cout << "Entrada incorrecta, elige nuevamente\n";
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    }

    string nuevaClave = convertirABinario(clave);
    string nuevaCedula = convertirABinario(cedula);

    if(metodo == 1){
        cedula = codificarBinarioMetodo1(nuevaCedula,semilla);
        clave = codificarBinarioMetodo1(nuevaClave, semilla);
    }
    else{
        cedula = codificarBinarioMetodo2(nuevaCedula,semilla);
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

void registrarUsuario(){//pide los datos del usuario, convierte a binario la info y la codifica segun las condiciones
    Usuario usuario;
    bool cedula = false;
    string cedula1, clave, saldo;
    int metodo = 0, semilla;
    while(metodo < 1 || metodo > 2){
        cout << "Ingrese el metodo para codificar la informacion (1 o 2): ";
        cin >> metodo;
        if (cin.fail() || metodo < 1 || metodo > 2) {
            cin.clear();  // Limpiar el indicador de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
            cout << "Entrada incorrecta, elige nuevamente\n";
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    }

    while (true) {
        cout << "Ingrese la semilla: ";
        cin >> semilla;

        if (cin.fail()) {
            cin.clear();  // Limpiar el indicador de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
            cout << "Entrada incorrecta, elige nuevamente\n";
        } else {
            break;  // Salir del bucle si la entrada es válida
        }
    }

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

void guardarUsuarios(){ //añade la informacion del mapa en el archivo "usuarios.txt"
    ofstream archivo;
    archivo.open("usuarios.txt");
    for(auto& usuario : usuarios){
        archivo << usuario.second.cedula << " " << usuario.second.clave << " " << usuario.second.saldo << ";" <<endl;
    }
    archivo.close();
}
