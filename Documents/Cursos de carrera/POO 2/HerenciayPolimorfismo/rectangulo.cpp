//
// Created by estanislao.contreras on 8/19/2019.
//

#include "rectangulo.h"

Rectangulo::Rectangulo(float x, float y, Signo signo, float b, float h) : Triangulo(x, y, signo, b, h) {}

float Rectangulo::calcularArea() {
    return b*h;
}
