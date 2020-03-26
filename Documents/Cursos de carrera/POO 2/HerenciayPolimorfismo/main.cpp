#include <iostream>

#include "triangulo.h"
#include "rectangulo.h"
#include "circulo.h"
#include "area_compuesta.h"

using namespace std;

int main() {
    AreaCompuesta* areaCompuesta = new AreaCompuesta();
    areaCompuesta->componerArea( new Rectangulo(45,10,positivo,30,20));
    areaCompuesta->componerArea( new Circulo(45,10,negativo,7.5));
    areaCompuesta->componerArea( new Triangulo(20,6.67,positivo,30,20));
    auto* centroide = areaCompuesta->calcularCentroide();

    cout<<"Xcg = "<<centroide->getX()<<", Ycg = "<<centroide->getY();

    delete areaCompuesta;
    return 0;
}