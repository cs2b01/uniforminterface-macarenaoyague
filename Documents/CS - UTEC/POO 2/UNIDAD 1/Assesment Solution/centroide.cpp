//
// Created by estanislao.contreras on 8/19/2019.
//

#include "centroide.h"

Centroide::Centroide(float x, float y) : x(x), y(y) {}

float Centroide::getX() const {
    return x;
}

void Centroide::setX(float x) {
    Centroide::x = x;
}

float Centroide::getY() const {
    return y;
}

void Centroide::setY(float y) {
    Centroide::y = y;
}
