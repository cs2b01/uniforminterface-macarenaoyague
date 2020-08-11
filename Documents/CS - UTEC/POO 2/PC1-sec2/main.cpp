#include <iostream>
using namespace std;

#include "Frecuencia.h"

int main() {
    Frecuencia notas("notas1.txt");
    notas.vaciarDatos();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}