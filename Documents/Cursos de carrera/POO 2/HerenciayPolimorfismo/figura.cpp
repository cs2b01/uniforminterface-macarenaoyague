//
// Created by estanislao.contreras on 8/19/2019.
//

#include "figura.h"

Figura::Figura(float x, float y, Signo signo) : signo(signo) {
    centroide = new Centroide(x,y);
}

Signo Figura::getSigno() const {
    return signo;
}

Centroide *Figura::getCentroide() const {
    return centroide;
}

Figura::~Figura() {
    delete centroide;
}
