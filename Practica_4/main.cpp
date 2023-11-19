#include "red.h"
#include <cctype>

int main(){
    red Red;
    int opcion = 0;

    while (opcion != 9) { // 9 será la opción para salir
        cout << "\nBienvenido a nuestra red \n1. Agregar enrutador\n2. Remover enrutador\n3. Actualizar tabla de enrutamiento\n"
                "4. Cargar red desde archivo\n5. Costo de envio\n6. Camino mas eficiente\n7. Generar red aleatoria\n"
                "8. Imprimir tabla de enrutamiento\n9. Salir\n";

        cout << "Seleccione una opcion: ";
                cin >> opcion;

        while (!(cin >> opcion) || opcion < 1) {
            cin.clear();  // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada no válida

            cout << "Opcion no valida. Por favor, ingrese un numero positivo: ";
        }

        switch (opcion) {
        case 1: {
            cout << "Ingrese el nombre del nuevo enrutador: ";
            string nuevo;
            cin >> nuevo;
            // Convertir a mayúsculas
            transform(nuevo.begin(), nuevo.end(), nuevo.begin(), ::toupper);

            // Verificar que sea solo una letra
            if(nuevo.size() != 1 || !isalpha(nuevo[0])){ // Si el nombre del enrutador no es una sola letra
                cout << "El nombre del enrutador debe ser una sola letra.\n"; // Imprimir un mensaje de error
            }
            else{
                //Verificar que el nombre no esté repetido
                if (Red.getEnrutadores().count(nuevo) > 0) { // Si el nombre del enrutador ya está en uso
                    cout << "El nombre del enrutador ya está en uso.\n";
                }
                else{ // Si el nombre del enrutador no está en uso
                    Red.agregarEnrutador(nuevo); // Agregar el nuevo enrutador a la red
                    Red.guardarArchivo("redes.txt"); // Guardar la red en un archivo
                    cout << "Enrutador agregado con éxito\n";
                }
            }
            break;
        }
        case 2: {
            cout << "ingrese el nombre del enrutador a eleminar: ";
            string eliminar; // Declarar una variable para almacenar el nombre del enrutador a eliminar
            cin >> eliminar;
            if (Red.getEnrutadores().count(eliminar) <= 0){
                cout << "El nombre del enrutador no existe.\n"; // Imprimir un mensaje de error
            }
            else{ // Si el nombre del enrutador existe
                Red.eliminarEnrutador(eliminar);
                Red.guardarArchivo("redes.txt"); // Guardar la red en un archivo
                cout << "\nEnrutador eliminado con exito" << endl;
            }
            break;
        }
        case 3: {
            cout << "Bienvenido al menú de actualizar tabla de enrutamiento\n"<< endl;
                        cout << "ingrese el enrutador origen" << endl; // Solicitar al usuario que ingrese el enrutador origen
            string principal; // Declarar una variable para almacenar el enrutador origen
            cin >> principal; // Leer el enrutador origen
            cout << "Ingrese el enrutador destino"<< endl; // Solicitar al usuario que ingrese el enrutador destino
            string secundario; // Declarar una variable para almacenar el enrutador destino
            cin >> secundario; // Leer el enrutador destino
            cout << "Ingrese el costo"<< endl; // Solicitar al usuario que ingrese el costo
            int costo; // Declarar una variable para almacenar el costo
            cin >> costo; // Leer el costo
            Red.actualizarTablaEnrutamiento(principal, secundario,  costo); // Actualizar la tabla de enrutamiento
            cout << "Tabla actulizada con exito" << endl; // Imprimir un mensaje de éxito
            break;
        }
        case 4: {
            Red.leerArchivo("Aleatorios.txt"); // Cargar la red desde un archivo
            Red.guardarArchivo("redes.txt"); // Guardar la red en un archivo
            cout << "Archivo Leido con exito" << endl; // Imprimir un mensaje de éxito
            break;
        }
        case 5: {
            cout << "Costo de envio" << endl;; // Imprimir un mensaje
            cout << "Ingrese el enrutador de origen" << endl; // Solicitar al usuario que ingrese el enrutador de origen
            string origen; // Declarar una variable para almacenar el enrutador de origen
            cin >> origen; // Leer el enrutador de origen
            cout << "Ingrese el enrutador de destino" << endl; // Solicitar al usuario que ingrese el enrutador de destino
            string destino; // Declarar una variable para almacenar el enrutador de destino
            cin >> destino; // Leer el enrutador de destino
            cout << "El costo del envio será: " << Red.costo(origen, destino); // Calcular e imprimir el costo de envío
            break;
        }
        case 6: {
            cout << "Camino mas eficiente" << endl;; // Imprimir un mensaje
            cout << "Ingrese el enrutador de origen" << endl; // Solicitar al usuario que ingrese el enrutador de origen
            string origen1; // Declarar una variable para almacenar el enrutador de origen
            cin >> origen1; // Leer el enrutador de origen
            cout << "Ingrese el enrutador de destino" << endl; // Solicitar al usuario que ingrese el enrutador de destino
            string destino1; // Declarar una variable para almacenar el enrutador de destino
            cin >> destino1; // Leer el enrutador de destino
            cout << "El camino mas eficiente de "<< origen1 << " a " << destino1 << " sera:"; // Imprimir un mensaje
            vector<string> camino = Red.caminoCorto(origen1, destino1); // Calcular el camino más corto
            for(auto nodo: camino){ // Recorrer el camino
                cout << nodo << " -> " ; // Imprimir cada nodo del camino
            }
            break;
        }
        case 7: {
            cout << "Ingrese el numero de enrutadores que quieres generar: "; // Solicitar al usuario que ingrese el número de enrutadores
            int numeros; // Declarar una variable para almacenar el número de enrutadores
            cin >> numeros; // Leer el número de enrutadores
            Red.redAleatoria(numeros); // Generar una red aleatoria
            Red.guardarArchivo("Aleatorios.txt"); // Guardar la red en un archivo
            cout << "Archivo generado con exito" << endl; // Imprimir un mensaje de éxito
            break;
        }
        case 8: {
            cout << "Tabla de enrutadores" << endl; // Imprimir un mensaje
            Red.mostrarTablaEnrutadores(); // Mostrar las tablas de enrutamiento
            break;
        }
        case 9: {
            cout << "Saliendo del programa. ¡Hasta luego!\n";
                break;
        }
        default: {
            cout << "Opcion invalida, intente de nuevo.\n";
            break;
        }
        }
    }
    return 0;
}
