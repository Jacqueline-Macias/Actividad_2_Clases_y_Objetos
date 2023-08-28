#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class Neurona {
private:
    int id;
    double voltaje;
    int pos_x;
    int pos_y;
    int red;
    int green;
    int blue;

public:
    Neurona(int _id, double _voltaje, int _pos_x, int _pos_y, int _red, int _green, int _blue);
    void print();
};

class AdministradorNeuronas {
private:
    std::vector<Neurona> neuronas;

public:
    void agregar_inicio(Neurona neurona);
    void agregar_final(Neurona neurona);
    void mostrar();
};

Neurona::Neurona(int _id, double _voltaje, int _pos_x, int _pos_y, int _red, int _green, int _blue)
    : id(_id), voltaje(_voltaje), pos_x(_pos_x), pos_y(_pos_y), red(_red), green(_green), blue(_blue) {}

void Neurona::print() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Voltaje: " << voltaje << std::endl;
    std::cout << "Posición X: " << pos_x << std::endl;
    std::cout << "Posición Y: " << pos_y << std::endl;
    std::cout << "Red, Green, Blue: (" << red << ", " << green << ", " << blue << ")" << std::endl;
}

void AdministradorNeuronas::agregar_inicio(Neurona neurona) {
    neuronas.insert(neuronas.begin(), neurona);
}

void AdministradorNeuronas::agregar_final(Neurona neurona) {
    neuronas.push_back(neurona);
}

void AdministradorNeuronas::mostrar() {
    for (const Neurona& neurona : neuronas) {
        neurona.print();
        std::cout << std::endl;
    }
}

int main() {
    Neurona neurona1(1, 0.5, 10, 20, 255, 0, 0);
    Neurona neurona2(2, 0.8, 15, 25, 0, 255, 0);
    Neurona neurona3(3, 0.3, 5, 10, 0, 0, 255);

    AdministradorNeuronas adminNeuronas;
    adminNeuronas.agregar_inicio(neurona1);
    adminNeuronas.agregar_final(neurona2);
    adminNeuronas.agregar_final(neurona3);

    adminNeuronas.mostrar();

    return 0;
}

