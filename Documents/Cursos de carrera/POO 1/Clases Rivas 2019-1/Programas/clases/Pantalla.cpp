//
// Created by Macarena Oyague on 2019-06-04.
//

#include "Pantalla.h"

Pantalla::Pantalla() {
    largo=0;
    ancho=0;
    prendido=true;
    marca="Huawei";
}

Pantalla::Pantalla(int l, int a, bool p, std::string marca) {
    largo=l;
    ancho=a;
    prendido=p;
    this->marca=marca;

}

Pantalla::~Pantalla() {

}

void Pantalla::prender() {
    prendido= true;
}

void Pantalla::apagar() {
    prendido=false;
}

bool Pantalla::get_prendido() {
    return prendido;
}

string Pantalla::get_modelo() {
    return marca;
}


