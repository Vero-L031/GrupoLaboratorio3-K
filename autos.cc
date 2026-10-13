#include <iostream>
#include <queue>
#include <string>
//libreria para limpiar el buffer porque nos daba problemas xdddddd
//fuente: https://stackoverflow.com/questions/53617343/c-how-to-clear-buffer
#include <limits> 

struct Auto {
    std::string modelo;
    std::string placa;
    std::string color;
};

void agregarAuto(std::queue<Auto>& cola);
void atenderAuto(std::queue<Auto>& cola);
void mostrarCola(std::queue<Auto> cola);

int main() {
    std::queue<Auto> colaTaller;
    int opcion;

    do {
        std::cout << "\n--- SISTEMA DEL TALLER ---\n";
        std::cout << "1. Agregar Auto\n";
        std::cout << "2. Atender Auto\n";
        std::cout << "3. Mostrar Cola\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        
        if (!(std::cin >> opcion)) { // Evita bucles infinitos si meten una letra
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, introduce un numero.\n";
            continue;
        }
        
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                agregarAuto(colaTaller);
                break;
            case 2:
                atenderAuto(colaTaller);
                break;
            case 3:
                mostrarCola(colaTaller);
                break;
            case 4:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);

    return 0;
}

void agregarAuto(std::queue<Auto>& cola) {
    Auto nuevo;

    std::cout << "Modelo: ";
    std::getline(std::cin, nuevo.modelo);
    
    std::cout << "Placa: ";
    std::getline(std::cin, nuevo.placa);
    
    std::cout << "Color: ";
    std::getline(std::cin, nuevo.color);

    cola.push(nuevo);
    std::cout << "Auto agregado a la cola con exito.\n";
}

void atenderAuto(std::queue<Auto>& cola) {
    if (cola.empty()) {
        std::cout << "No hay mas autos para atender.\n";
        return;
    }

    Auto atendido = cola.front(); 
    cola.pop();                   

    std::cout << "\n--- AUTO ATENDIDO ---\n";
    std::cout << "Modelo: " << atendido.modelo << "\n";
    std::cout << "Placa:  " << atendido.placa << "\n";
    std::cout << "Color:  " << atendido.color << "\n";
    std::cout << "------------------\n";
}

void mostrarCola(std::queue<Auto> cola) {
    if (cola.empty()) {
        std::cout << "No hay autos en espera.\n";
        return;
    }

    int posicion = 1;
    std::queue<Auto> copia = cola; 
    while (!copia.empty()) {
        Auto actual = copia.front();
        std::cout << posicion << ". Modelo: " << actual.modelo << "  Placa: " << actual.placa << " Color: " << actual.color << "\n";
        copia.pop();
        posicion++;
    }
}
