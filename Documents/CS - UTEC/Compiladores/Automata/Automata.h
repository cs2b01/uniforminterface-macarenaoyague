//
// Created by Macarena Oyague on 2020-04-02.
//

#ifndef AUTOMATA_AUTOMATA_H
#define AUTOMATA_AUTOMATA_H

#include "Estado.h"
#include "Alfabeto.h"
#include <vector>
using namespace std;

class Automata {

private:
    vector <Estado&> Q;
    Alfabeto alfabeto;
    Estado* q0;
    vector <Estado*> F;
    Estado *buscarEstado(string nombre);
    Estado* transiciones(string input);

public:
    void setQ(vector<Estado> &Q);
    void setAlfabeto(Alfabeto &alfabeto);
    void setQ0(Estado q0);
    void setF(vector<Estado*> F);
    bool validarInput(string input);
};


#endif //AUTOMATA_AUTOMATA_H
