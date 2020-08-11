//
// Created by Macarena Oyague on 2020-04-01.
//

#include "Alfabeto.h"
using namespace std;

Alfabeto::Alfabeto() {}

void Alfabeto::setCategorias(const unordered_map<char, char> &categorias) {
    Alfabeto::categorias = categorias;
}

char Alfabeto::getAlias (char caracter){
    for (auto line: categorias)
        if (line.first == caracter)
            return line.second;
    return 'o';
}
