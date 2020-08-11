//
// Created by Macarena Oyague on 2019-09-11.
//

#ifndef MATRIZ_MATRIZ_H
#define MATRIZ_MATRIZ_H

#include <iostream>
#include <vector>
using namespace std;
#include <ctime>
#include <cstdlib>

template <class elemento>

class Matriz{

private:
    vector<int> *filas, *columnas;
    vector<elemento> *datos;
    int fila, columna;

public:
    Matriz<elemento>();
    Matriz<elemento>(int fila, int columna);
    size_t getSize();
    int getFila();
    void setFila(int fila);
    int getColumna();
    void setColumna(int columna);
    void insertar(int fila, int columna, elemento dato);
    int getDatoFila(size_t indice);
    void setDatoFila(size_t indice, int dato);
    int getDatoColumna(size_t indice);
    void setDatoColumna(size_t indice, int dato);
    elemento getDatoDato(size_t indice);
    void setDatoDato(size_t indice, elemento dato);
    void llenarRand(size_t numDatos, int numMax);
    void ordenarporFilas();
    void ordenarporColumnas();
    virtual ~Matriz<elemento>();
};


#endif //MATRIZ_MATRIZ_H
