//
// Created by Macarena Oyague on 2019-09-21.
//

#include <vector>
using namespace std;
#include <iostream>

template <class T>

class Conjunto {

private:

    vector <T>* elementos;

public:

    Conjunto(vector<T>* elementos){
        this->elementos=elementos;
    }

    Conjunto(){}

    vector <T> *getElementos() const {
        return elementos;
    }

    void setElementos(vector<T>* elementos){
        Conjunto::elementos=elementos;
    }

    bool existeElemento(T e){
        for (T elemento: *elementos)
            if(elemento==e)
                return true;
        return false;
    }

    void adicionarElementos(vector<T> *elementos2){
        for(T e: *elementos2)
            if (! existeElemento(e))
                elementos->push_back(e);
    }

    Conjunto <T>* realizarUnion(Conjunto *c){
        Conjunto <T>* nuevoConjunto=new Conjunto<T>();
        nuevoConjunto->adicionarElementos(elementos);
        nuevoConjunto->adicionarElementos(c->getElementos());
        return nuevoConjunto;
    }

    Conjunto <T>*realizarInterseccion(Conjunto<T>* c){
        vector <T>* nuevoVector=new vector<T>;
        Conjunto<T>* nuevoConjunto=new Conjunto<T>();
        for (T e: *elementos)
            for (T i: *c->getElementos())
                if (i==e)
                    nuevoVector->push_back(e);
        nuevoConjunto->adicionarElementos(nuevoVector);
        return nuevoConjunto;
    }

    Conjunto <T>* realizarDiferencia(Conjunto *c){
        for(T e: *c->getElementos())
            if(! )
    }

    void mostrarElementos(){
        cout<<"{";
        for(T e: *elementos)
            cout<<e<<" ,";
        cout<<"}";
    }
};
