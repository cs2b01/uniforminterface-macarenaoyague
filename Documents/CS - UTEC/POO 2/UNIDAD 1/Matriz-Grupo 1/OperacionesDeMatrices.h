//
// Created by Macarena Oyague on 2019-09-06.
//

#ifndef INTENTOS_OPERACIONESDEMATRICES_H
#define INTENTOS_OPERACIONESDEMATRICES_H

#include "Matriz.h"

Matriz Sumar (Matriz &m1, Matriz &m2){
    Matriz m3;
    if (m1.getFila()==m2.getFila()&&m1.getColumna()==m2.getColumna()) {
        m3.setFila(m1.getFila());
        m3.setColumna(m1.getColumna());
        for (size_t i = 0; i < m1.getSize(); i++) {
            double suma = 0;
            bool fueSumado = false;
            for (size_t j = 0; j < m2.getSize(); ++j) {
                if (m1.getDatoFila(i) == m2.getDatoFila(j))
                    if (m1.getDatoColumna(i) == m2.getDatoColumna(j)) {
                        suma = m1.getDatoDato(i) + m2.getDatoDato(j);
                        fueSumado = true;
                    }
            }
            if (!fueSumado)
                m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), m1.getDatoDato(i));
            else
                m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), suma);
        }
        for (size_t i = 0; i < m2.getSize(); i++) {
            bool iguales = false;
            for (size_t j = 0; j < m2.getSize(); ++j) {
                if (m2.getDatoFila(i) == m1.getDatoFila(j))
                    if (m2.getDatoColumna(i) == m1.getDatoColumna(j))
                        iguales = true;
            }
            if (!iguales)
                m3.insertar(m2.getDatoFila(i), m2.getDatoColumna(i), m2.getDatoDato(i));
        }
    }
    return m3;
}

Matriz Restar (Matriz &m1, Matriz& m2){
    Matriz m3;
    if (m1.getFila()==m2.getFila()&&m1.getColumna()==m2.getColumna())
    {
        m3.setFila(m1.getFila());
        m3.setColumna(m1.getColumna());
        for (size_t i=0; i<m1.getSize(); i++) {
            double resta = 0;
            bool fueRestado=false;
            for (size_t j = 0; j < m2.getSize(); ++j) {
                if (m1.getDatoFila(i) == m2.getDatoFila(j))
                    if (m1.getDatoColumna(i) == m2.getDatoColumna(j)) {
                        resta = m1.getDatoDato(i) - m2.getDatoDato(j);
                        fueRestado=true;
                    }
            }
            if (!fueRestado)
                m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), m1.getDatoDato(i));
            else
                m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), resta);
        }
        for (size_t i = 0; i < m2.getSize(); i++) {
            bool iguales = false;
            for (size_t j = 0; j < m2.getSize(); ++j) {
                if (m2.getDatoFila(i) == m1.getDatoFila(j))
                    if (m2.getDatoColumna(i) == m1.getDatoColumna(j))
                        iguales = true;
            }
            if (!iguales)
                m3.insertar(m2.getDatoFila(i), m2.getDatoColumna(i), (m2.getDatoDato(i))*(-1));
        }
    }
    return m3;
}

Matriz ProductoEscalar(Matriz &m1, double escalar){
    Matriz m2;
    for(size_t i=0; i<m1.getSize();i++)
    {
        double dato=m1.getDatoDato(i)*escalar;
        if (dato!=0)
            m2.insertar(m1.getDatoFila(i),m1.getDatoColumna(i),dato);
    }
    return m2;
}

Matriz RealizarTranspuesta (Matriz &m1){
    Matriz m3;
    m3.setFila(m1.getColumna());
    m3.setColumna(m1.getFila());
    for (size_t i=0; i<m1.getSize(); i++)
        m3.insertar(m1.getDatoColumna(i),m1.getDatoFila(i),m1.getDatoDato(i));
    return m3;
}

Matriz Multiplicar(Matriz &m1, Matriz &m2){
    Matriz m3;
    if(m1.getColumna() == m2.getFila()){
        m3.setFila(m1.getFila());
        m3.setColumna(m2.getColumna());
        m1.ordenarporFilas();
        m2.ordenarporColumnas();
        double multiplicacion;
        for (size_t i=0; i<m1.getSize(); i++) {
            multiplicacion = 0;
            for (size_t j = 0; j < m2.getSize(); ++j) {
                if (m1.getDatoFila(i) == m2.getDatoColumna(j))
                {
                    if (m1.getDatoColumna(i) == m2.getDatoFila(j)) {
                        multiplicacion=multiplicacion + m1.getDatoDato(i)*m2.getDatoDato(j);
                    }
                }
            }
            if (multiplicacion!=0)
                        m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), multiplicacion);
        }
    }
    Matriz m4;
    double sumando=m3.getDatoDato(0);
    int tempFila=m3.getDatoFila(0);
    for (size_t i=1; i<m3.getSize(); i++) {
        if (m3.getDatoFila(i) == tempFila)
            sumando = sumando + m3.getDatoDato(i);
        else {
            if (sumando!=0) {
                m4.insertar(tempFila, tempFila, sumando);
            }
            tempFila = m3.getDatoFila(i);
            sumando=m3.getDatoDato(i);
        }
    }
    if (sumando!=0)
        m4.insertar(tempFila,tempFila, sumando);
    return m4;
}



#endif //INTENTOS_OPERACIONESDEMATRICES_H
