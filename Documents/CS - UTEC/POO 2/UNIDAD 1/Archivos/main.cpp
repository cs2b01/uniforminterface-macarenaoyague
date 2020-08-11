#include <iostream>
#include "lista_alumnos.cpp"

int main() {
    std::cout << "Lista de alumnos" << std::endl;
    ListaAlumnos* lista = new ListaAlumnos("Alumnos.txt");
    lista->registrar(new Alumno("Juan Carlos Rodriguez"));
    lista->registrar(new Alumno("Ana Montero"));
    lista->imprimir();
    lista->guardar("Alumnos.csv");
    delete lista;
    return 0;
}