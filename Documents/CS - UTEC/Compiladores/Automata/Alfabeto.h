//
// Created by Macarena Oyague on 2020-04-01.
//

#ifndef AUTOMATA_ALFABETO_H
#define AUTOMATA_ALFABETO_H


#include <unordered_map>
using namespace std;

class Alfabeto {

private:

    //caracter, alias
    unordered_map<char, char> categorias;

public:

    Alfabeto();
    void setCategorias(const unordered_map<char, char> &categorias);
    char getAlias (char caracter);
};


#endif //AUTOMATA_ALFABETO_H
