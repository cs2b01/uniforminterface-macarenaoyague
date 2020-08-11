#include <iostream>

#include "examen.h"

int main() {
    Examen examen ("postulantes");
    examen.listarIngresantesCiencias("ciencassss.csv");
    examen.listarIngresantesLetras("letras.csv");
    examen.leer();
    return 0;
}
