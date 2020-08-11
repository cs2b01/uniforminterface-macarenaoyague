//
// Created by Macarena Oyague on 2019-09-06.
//

#ifndef INTENTOS_MATRIZ_H
#define INTENTOS_MATRIZ_H

#include <iostream>
#include <vector>
using namespace std;
#import <ctime>
#include <cstdlib>


class Matriz {

private:
    vector<int> *filas, *columnas;
    vector<double> *datos;
    int fila, columna;

public:
    Matriz();
    Matriz(int fila, int columna);
    size_t getSize();
    int getFila();
    void setFila(int fila);
    int getColumna();
    void setColumna(int columna);
    void insertar(int fila, int columna, double dato);
    int getDatoFila(size_t indice);
    void setDatoFila(size_t indice, int dato);
    int getDatoColumna(size_t indice);
    void setDatoColumna(size_t indice, int dato);
    double getDatoDato(size_t indice);
    void setDatoDato(size_t indice, double dato);
    void llenarRand(size_t numDatos, int numMax);
    void ordenarporFilas();
    void ordenarporColumnas();
    virtual ~Matriz();
};


#endif //INTENTOS_MATRIZ_H
