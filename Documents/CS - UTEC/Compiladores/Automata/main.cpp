#include <iostream>
#include <vector>
#include "Automata.h"
using namespace std;

void fillAlfabeto(Alfabeto& alfabeto);
void fillEstado(Estado &estado, string fillW, string fillA, string fillO, string fillP);



int main() {

    Alfabeto alfabeto;
    fillAlfabeto(alfabeto);


    vector <Estado> Q;
    Estado e0("e0");    fillEstado(e0, "e1", "r0", "r0", "r0");     Q.push_back(e0);
    Estado e1("e1");    fillEstado(e1, "e1", "e2", "r0", "r0");     Q.push_back(e1);
    Estado e2("e2");    fillEstado(e2, "e3", "r0", "r0", "r0");     Q.push_back(e2);
    Estado e3("e3");    fillEstado(e3, "e3", "r1", "r1", "e4");     Q.push_back(e3);
    Estado e4("e4");    fillEstado(e4, "f", "r1", "r1", "r1");      Q.push_back(e4);
    Estado f("f");      fillEstado(f, "f", "r1", "r1", "e4");       Q.push_back(f);
    Estado r0("r0");    fillEstado(r0, "r0", "r0", "r0", "r0");     Q.push_back(r0);
    Estado r1("r1");    fillEstado(r1, "r1", "r1", "r1", "r1");     Q.push_back(r1);

    vector <Estado*> F;
    F.push_back(&f);

    Automata automata;
    automata.setQ(Q);
    automata.setAlfabeto(alfabeto);
    automata.setF(F);
    automata.setQ0(e0);

    cout<<automata.validarInput("maca@gmail.com");
    return 0;
}


void fillAlfabeto(Alfabeto& alfabeto){

    unordered_map<char, char> categorias;

    for (char i = 97; i<=122; i++)
        categorias[i] = 'w';
    for (char i = 65; i<=90; i++)
        categorias[i] = 'w';
    for (char i = 48; i<=57; i++)
        categorias[i] = 'w';
    categorias[95] = 'w';

    categorias[64] = 'a';

    categorias[46] = 'p';

   alfabeto.setCategorias(categorias);
}

void fillEstado(Estado &estado, string fillW, string fillA, string fillO, string fillP){
    multimap <char, string> transiciones;
    transiciones.insert(pair <char, string> ('w', fillW));
    transiciones.insert(pair <char, string> ('a', fillA));
    transiciones.insert(pair <char, string> ('o', fillO));
    transiciones.insert(pair <char, string> ('p', fillP));
    estado.setTransiciones(transiciones);
}