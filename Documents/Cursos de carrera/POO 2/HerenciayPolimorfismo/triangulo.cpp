//
// Created by estanislao.contreras on 8/19/2019.
//

#include "triangulo.h"

Triangulo::Triangulo(float x, float y, Signo signo, float b, float h) : Figura(x, y, signo), b(b), h(h) {}

float Triangulo::getB() const {
    return b;
}

void Triangulo::setB(float b) {
    Triangulo::b = b;
}

float Triangulo::getH() const {
    return h;
}

void Triangulo::setH(float h) {
    Triangulo::h = h;
}

float Triangulo::calcularArea() {
    return b*h/2;
}
