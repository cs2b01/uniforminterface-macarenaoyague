//
// Created by Macarena Oyague on 2020-04-01.
//

#ifndef AUTOMATA_ESTADO_H
#define AUTOMATA_ESTADO_H

#include "string"
#include <map>
using namespace std;

class Estado {

private:
    string nombre;
    multimap <char, string> transiciones;

public:
    Estado(const string &nombre);
    void setTransiciones(const multimap<char, string> &transiciones);
    string getEstadoSiguiente(char categoria);

    const string &getNombre() const;
};


#endif //AUTOMATA_ESTADO_H
