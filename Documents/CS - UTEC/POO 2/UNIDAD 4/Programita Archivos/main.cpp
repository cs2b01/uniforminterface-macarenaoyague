#include <iostream>
#include "clase.cpp"
#include "databes.cpp"


int main() {
    Database notas("datos.txt");
    notas.vaciarDatos();
    notas.getDatos();

    return 0;
}