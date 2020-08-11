//
// Created by Macarena Oyague on 2020-04-01.
//

#include "Estado.h"

void Estado::setTransiciones(const multimap<char, string> &transiciones) {
    Estado::transiciones = transiciones;
}

string Estado::getEstadoSiguiente(char categoria) {
    for (auto line: transiciones)
        if (line.first == categoria)
            return line.second;
}

Estado::Estado(const string &nombre) : nombre(nombre) {}

const string &Estado::getNombre() const {
    return nombre;
}
