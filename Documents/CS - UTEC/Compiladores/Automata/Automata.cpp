//
// Created by Macarena Oyague on 2020-04-02.
//

#include "Automata.h"

void Automata::setQ(vector<Estado> &Q) {
    Automata::Q = Q;
}

void Automata::setAlfabeto(Alfabeto &alfabeto) {
    Automata::alfabeto = alfabeto;
}

void Automata::setF(vector<Estado*> F) {
    Automata::F = F;
}

void Automata::setQ0(Estado q0) {
    Automata::q0 = &q0;
}

Estado* Automata::buscarEstado(string nombre) {
    for (auto estado: Q)
        if (estado.getNombre() == nombre)
            return &estado;
}

Estado *Automata::transiciones(string input) {

    Estado *estadoActual = q0;
    char alias;
    string estadoSiguiente;

    for (int i = 0; i<input.size(); i++)
    {
        alias = alfabeto.getAlias(input[i]);
        estadoSiguiente = estadoActual->getEstadoSiguiente(alias);
        estadoActual = buscarEstado(estadoSiguiente);
    }

    return estadoActual;

}

bool Automata::validarInput(string input) {
    Estado *estadoFinal = transiciones(input);
    for (auto estadoAceptacion: F)
        if (estadoAceptacion == estadoFinal)
            return true;

    return false;
}





