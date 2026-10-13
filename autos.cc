#include <iostream>
#include <queue>

struct Auto {
    std::string modelo;
    std::string placa;
    std::string color;
};

// Declaración de funciones
void agregarAuto(std::queue<Auto>& cola);
void atenderAuto(std::queue<Auto>& cola);

int main() {
    std::queue<Auto> colaTaller;
    int opcion;

    do {
        std::cout << "\n--- SISTEMA DEL TALLER ---\n";
        std::cout << "1. Agregar Auto\n";
        std::cout << "2. Atender Auto\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1:
                agregarAuto(colaTaller);
                break;
            case 2:
                atenderAuto(colaTaller);
                break;
            case 3:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 3);

    return 0;
}

// Función para registrar un nuevo auto
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

// Función para atender al primer auto de la cola
void atenderAuto(std::queue<Auto>& cola) {
    if (cola.empty()) {
        std::cout << "No hay mas autos para atender.\n";
        return;
    }

    Auto atendido = cola.front(); 
    cola.pop();                   

    std::cout << "\n=== AUTO ATENDIDO ===\n";
    std::cout << "Modelo: " << atendido.modelo << "\n";
    std::cout << "Placa:  " << atendido.placa << "\n";
    std::cout << "Color:  " << atendido.color << "\n";
    std::cout << "=====================\n";
}
