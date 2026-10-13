#include <iostream>
#include <queue>
#include <string>

struct Auto
{
    std::string modelo;
    std::string placa;
    std::string color;
};

void agregarAuto(std::queue<Auto> &cola);
void mostrarCola(std::queue<Auto> cola);

int main()
{

    return 0;
}

void agregarAuto(std::queue<Auto> &cola)
{
    Auto nuevo;

    std::cout << "Modelo: ";
    getline(std::cin, nuevo.modelo);
    std::cout << "Modelo: ";
    getline(std::cin, nuevo.modelo);
    std::cout << "Modelo: ";
    getline(std::cin, nuevo.modelo);

    cola.push(nuevo);

    std::cout << "Auto Generado en la cole \n";
}

// mostramos los autos en espera
void mostrarCola(std::queue<Auto> cola)
{

    if (cola.empty())
    {
        std::cout << "No hay autos en espera." << std::endl;
        return;
    }

    int posicion = 1;
    while (!cola.empty())
    {
        Auto actual = cola.front();
        std::cout << posicion << ". Modelo: " << actual.modelo << "  Placa: " << actual.placa << " Color: " << actual.color << std::endl;
        cola.pop();
        posicion++;
    }
}