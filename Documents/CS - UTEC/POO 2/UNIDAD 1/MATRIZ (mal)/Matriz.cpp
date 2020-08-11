//
// Created by Macarena Oyague on 2019-09-11.
//

#include "Matriz.h"


template <class elemento> Matriz<elemento>::Matriz(){
    filas=new vector<int>;
    columnas=new vector<int>;
    datos=new vector<elemento>;
    fila=0;
    columna=0;
}

template <class elemento> Matriz<elemento>::Matriz(int fila, int columna) {
    filas=new vector<int>;
    columnas=new vector<int>;
    datos=new vector<elemento>;
    this->fila=fila;
    this->columna=columna;
}

template <class elemento>
size_t Matriz<elemento>::getSize() {
    size_t size=columnas->size();
    return size;
}
template <class elemento>
int Matriz<elemento>::getFila() {
    if (fila==0)
        for (size_t i=0; i<getSize(); i++)
            if (fila<filas->at(i))
                fila=filas->at(i);
    return fila;
}
template <class elemento>
void Matriz<elemento>::setFila(int fila) {
    this->fila=fila;
}
template <class elemento>
int Matriz<elemento>:: getColumna() {
    if (columna==0)
        for (size_t i=0; i<getSize(); i++)
            if (columna<columnas->at(i))
                columna=columnas->at(i);
    return columna;
}
template <class elemento>
void Matriz<elemento>::setColumna(int columna) {
    this->columna=columna;
}
template <class elemento>
void Matriz<elemento>::insertar(int fila, int columna, elemento dato) {
    filas->push_back(fila);
    columnas->push_back(columna);
    datos->push_back(dato);
}
template <class elemento>
int Matriz<elemento>::getDatoFila(size_t indice) {
    int dato=filas->at(indice);
    return dato;
}
template <class elemento>
void Matriz<elemento>::setDatoFila(size_t indice, int dato) {
    filas->insert(filas->begin()+indice,dato);
}
template <class elemento>
int Matriz<elemento>::getDatoColumna(size_t indice) {
    int dato=columnas->at(indice);
    return dato;
}

template <class elemento>
void Matriz<elemento>::setDatoColumna(size_t indice, int dato) {
    columnas->insert(columnas->begin()+indice,dato);
}

template <class elemento>
elemento Matriz<elemento>::getDatoDato(size_t indice) {
    elemento dato=datos->at(indice);
    return dato;
}

template <class elemento>
void Matriz<elemento>::setDatoDato(size_t indice, elemento dato){
    datos->insert(datos->begin()+indice,dato);
}

template <class elemento>
void Matriz<elemento>::llenarRand(size_t numDatos, int numMax) {
    srand(time(nullptr));
    for (int i=0; getSize()!=numDatos; i++)
    {
        int randFila=rand()%(this->fila);
        int randColumna=rand()%(this->columna);
        elemento randDato=rand()%(numMax*100);
        randDato=randDato/100;
        insertar(randFila, randColumna, randDato);
    }
}

template <class elemento>
void Matriz<elemento>::ordenarporFilas() {
    size_t size=getSize();
    for (size_t a=0; a<size; a++)
    {
        for (size_t i=0; i<size; i++)
        {
            if (filas->at(a)>filas->at(i))
            {
                elemento tempDato=datos->at(i);
                int tempColumna=columnas->at(i);
                int tempFila=filas->at(i);
                filas->at(i)=filas->at(a);
                columnas->at(i)=columnas->at(a);
                datos->at(i)=datos->at(a);
                datos->at(a)=tempDato;
                columnas->at(a)=tempColumna;
                datos->at(a)=tempFila;
            }
        }
    }
}

template <class elemento>
void Matriz<elemento>::ordenarporColumnas() {
    size_t size=getSize();
    for (size_t a=0; a<size; a++)
    {
        for (size_t i=0; i<size; i++)
        {
            if (columnas->at(a)>columnas->at(i))
            {
                elemento tempDato=datos->at(i);
                int tempColumna=columnas->at(i);
                int tempFila=filas->at(i);
                filas->at(i)=filas->at(a);
                columnas->at(i)=columnas->at(a);
                datos->at(i)=datos->at(a);
                datos->at(a)=tempDato;
                columnas->at(a)=tempColumna;
                datos->at(a)=tempFila;
            }
        }
    }
}

template <class elemento>
Matriz<elemento>::~Matriz() {
    delete filas;
    delete columnas;
    delete datos;
}