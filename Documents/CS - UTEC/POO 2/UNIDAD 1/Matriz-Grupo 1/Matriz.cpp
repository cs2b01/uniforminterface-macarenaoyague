//
// Created by Macarena Oyague on 2019-09-06.
//

#include "Matriz.h"


Matriz::Matriz() {
    filas=new vector<int>;
    columnas=new vector<int>;
    datos=new vector<double>;
    fila=0;
    columna=0;
}

Matriz::Matriz(int fila, int columna) {
    filas=new vector<int>;
    columnas=new vector<int>;
    datos=new vector<double>;
    this->fila=fila;
    this->columna=columna;
}

size_t Matriz::getSize() {
    size_t size=columnas->size();
    return size;
}

int Matriz::getFila() {
    if (fila==0)
        for (size_t i=0; i<getSize(); i++)
            if (fila<filas->at(i))
                fila=filas->at(i);
    return fila;
}

void Matriz::setFila(int fila) {
    this->fila=fila;
}

int Matriz:: getColumna() {
    if (columna==0)
        for (size_t i=0; i<getSize(); i++)
            if (columna<columnas->at(i))
                columna=columnas->at(i);
    return columna;
}

void Matriz::setColumna(int columna) {
    this->columna=columna;
}

void Matriz::insertar(int fila, int columna, double dato) {
    filas->push_back(fila);
    columnas->push_back(columna);
    datos->push_back(dato);
}

int Matriz::getDatoFila(size_t indice) {
    int dato=0;
    if (getSize()!=0)
        dato=filas->at(indice);
    return dato;
}

void Matriz::setDatoFila(size_t indice, int dato) {
    filas->insert(filas->begin()+indice,dato);
}

int Matriz::getDatoColumna(size_t indice) {
    int dato=0;
    if (getSize()!=0)
        dato=columnas->at(indice);
    return dato;
}

void Matriz::setDatoColumna(size_t indice, int dato) {
    columnas->insert(columnas->begin()+indice,dato);
}

double Matriz::getDatoDato(size_t indice) {
    double dato=0;
    if (getSize()!=0)
        dato=datos->at(indice);
    return dato;
}


void Matriz::setDatoDato(size_t indice, double dato){
    datos->insert(datos->begin()+indice,dato);
}

void Matriz::llenarRand(size_t numDatos, int numMax) {
    srand(time(nullptr));
    for (int i=0; getSize()!=numDatos; i++)
    {
        int randFila=rand()%(this->fila);
        while (randFila==0)
            randFila=rand()%(this->fila);
        int randColumna=rand()%(this->columna);
        while (randColumna==0)
            randColumna=rand()%(this->fila);
        double randDato=rand()%(numMax*100);
        randDato=randDato/100;
        insertar(randFila, randColumna, randDato);
    }
}

void Matriz::ordenarporFilas() {
    size_t size=getSize();
    for (size_t a=0; a<size; a++)
    {
        for (size_t i=0; i<size; i++)
        {
            if (filas->at(a)>filas->at(i))
            {
                double tempDato=datos->at(i);
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

void Matriz::ordenarporColumnas() {
    size_t size=getSize();
    for (size_t a=0; a<size; a++)
    {
        for (size_t i=0; i<size; i++)
        {
            if (columnas->at(a)>columnas->at(i))
            {
                double tempDato=datos->at(i);
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

Matriz::~Matriz() {
    delete filas;
    delete columnas;
    delete datos;
}
