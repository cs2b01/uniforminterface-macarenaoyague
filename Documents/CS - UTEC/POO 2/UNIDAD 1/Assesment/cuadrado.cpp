//
// Created by Macarena Oyague on 2019-08-28.
//

#include "cuadrado.h"

cuadrado::cuadrado(double x, double y, double largo) : figura(x, y), largo(largo) {}

void cuadrado::setLargo(double largo) {
    this->largo=largo;
}

double cuadrado::getLargo() {
    return largo;
}

