//
// Created by Macarena Oyague on 2019-09-02.
//

#ifndef MATRIZDISPERSA_MATRIZ_H
#define MATRIZDISPERSA_MATRIZ_H

#include <iostream>
#include <vector>
using namespace std;

template <class elemento>

class Matriz {

private:

    vector<int> *filas, *columnas;
    vector<elemento> *datos;
    int fila, columna;

public:

    Matriz() {
        filas=new vector<int>;
        columnas=new vector<int>;
        datos=new vector<elemento>;
        fila=0;
        columna=0;
    }

    void insert(int fila, int columna, elemento dato) {
        filas->push_back(fila);
        columnas->push_back(columna);
        datos->push_back(dato);
        if (this->fila<fila)
            this->fila=fila;
        if (this->columna<columna)
            this->columna=columna;
    }

    int getFila() {
        return fila;
    }

    int getColumna() {
        return columna;
    }

    void clean(){
        //ver como limpiar la matriz, si por ejemplo ya existe un dato en 2x3
        // y alguien escribe otro, eliminar el anterior
    }

    virtual ~Matriz() {
        delete filas;
        delete columnas;
        //faltaria borrar el resto de datos, no se si es necesario
    }
};


#endif //MATRIZDISPERSA_MATRIZ_H
