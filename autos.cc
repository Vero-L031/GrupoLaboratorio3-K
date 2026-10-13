 #include <iostream>
 #include <queue>

 struct Auto
 {
std::string modelo;
std::string placa;
std::string color;

 };

 void atenderauto(std::queue<Auto>& cola);
 int main(){
    std::queue<Auto> colaTaller;
    return 0;
 }

void atenderAuto(std::queue<Auto>& cola){
    
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