//
// Created by estanislao.contreras on 8/19/2019.
//

#include "circulo.h"
#include <math.h>

Circulo::Circulo(float x, float y, Signo signo, float r) : Figura(x, y, signo), r(r) {}

float Circulo::calcularArea() {
    return M_PI*r*r;
}

float Circulo::getR() const {
    return r;
}

void Circulo::setR(float r) {
    Circulo::r = r;
}
