#include <iostream>
#include <queue>

struct Auto
{
    std::string modelo;
    std::string placa;
    std::string color;
};


void agregarAuto(std::queue<Auto>& cola);

int main(){


    return 0;
}

void agregarAuto(std::queue<Auto>& cola){
    Auto nuevo;

    std::cout<< "Modelo: ";
    getline(std::cin, nuevo.modelo);
    std::cout<< "Modelo: ";
    getline(std::cin, nuevo.modelo);
    std::cout<< "Modelo: ";
    getline(std::cin, nuevo.modelo);

    cola.push(nuevo);

    std::cout<<"Auto Generado en la cole \n";



}