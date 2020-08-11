#include <iostream>
#include "pc2.cpp"

int main() {
    Examen* examen = new Examen("postulantes.csv");
    examen->listarPostulantesCiencias();
    delete examen;

}