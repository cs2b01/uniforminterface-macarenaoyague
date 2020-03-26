//
// Created by Macarena Oyague on 2019-09-11.
//

#ifndef MATRIZ_OPERACIONESDEMATRICES_H
#define MATRIZ_OPERACIONESDEMATRICES_H

#include "Matriz.h"

template <class elemento>
Matriz<elemento> Sumar (Matriz<elemento> &m1, Matriz<elemento> &m2){
    Matriz<elemento> m3;
    if (m1.getFila()==m2.getFila()&&m1.getColumna()==m2.getColumna())
    {
        m3.setFila(m1.getFila());
        m3.setColumna(m1.getColumna());
        for (size_t i=0; i<m1.getSize(); i++) {
            elemento suma = 0;
            for (size_t j = 0; j < m2.getSize(); ++j) {
                bool fueSumado=false;
                if (m1.getDatoFila(i) == m2.getDatoFila(j))
                    if (m1.getDatoColumna(i) == m2.getDatoColumna(j)) {
                        suma = m1.getDatoDato(i) + m2.getDatoDato(j);
                        fueSumado=true;
                        m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), suma);
                    }
                if (!fueSumado)
                    m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), m1.getDatoDato(i));
            }
        }
        for (size_t i=0; i<m2.getSize(); i++)
        {
            for (size_t j=0; j<m3.getSize(); ++j) {
                if (m2.getDatoFila(i)==m3.getDatoFila(j))
                {
                    if (m2.getDatoColumna(i)==m3.getDatoColumna(j))
                    {
                    }
                }
                else
                    m3.insertar(m2.getDatoFila(i), m2.getDatoColumna(i), m2.getDatoDato(i));
            }
        }
    }
    return m3;
}

template <class elemento>
Matriz<elemento> Restar (Matriz<elemento> &m1, Matriz<elemento>& m2){
    Matriz<elemento> m3;
    if (m1.getFila()==m2.getFila()&&m1.getColumna()==m2.getColumna())
    {
        m3.setFila(m1.getFila());
        m3.setColumna(m1.getColumna());
        for (size_t i=0; i<m1.getSize(); i++) {
            elemento resta = 0;
            for (size_t j = 0; j < m2.getSize(); ++j) {
                bool fueRestado=false;
                if (m1.getDatoFila(i) == m2.getDatoFila(j))
                    if (m1.getDatoColumna(i) == m2.getDatoColumna(j)) {
                        resta = m1.getDatoDato(i) - m2.getDatoDato(j);
                        fueRestado=true;
                        m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), resta);
                    }
                if (!fueRestado)
                {
                    resta=m1.getDatoDato(i)*(-1);
                    m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), resta);
                }
            }
        }
        for (size_t i=0; i<m2.getSize(); i++)
        {
            for (size_t j=0; j<m3.getSize(); ++j) {
                if (m2.getDatoFila(i)==m3.getDatoFila(j))
                {
                    if (m2.getDatoColumna(i)==m3.getDatoColumna(j))
                    {
                    }
                }
                else
                    m3.insertar(m2.getDatoFila(i), m2.getDatoColumna(i), m2.getDatoDato(i)*(-1));
            }
        }
    }
    return m3;
}

template <class elemento>
Matriz<elemento> ProductoEscalar(Matriz<elemento> &m1, float escalar){
    Matriz<elemento> m2;
    for(size_t i=0; i<m1.getSize();i++)
    {
        elemento dato=m1.getDatoDato(i)*escalar;
        m2.insertar(m1.getDatoFila(i),m1.getDatoColumna(i),dato);
    }
    return m2;
}

template <class elemento>
Matriz<elemento> RealizarTranspuesta (Matriz<elemento> &m1){
    Matriz<elemento> m3;
    m3.setFila(m1.getColumna());
    m3.setColumna(m1.getFila());
    for (size_t i=0; i<m1.getSize(); i++)
        m3.insertar(m1.getDatoColumna(i),m1.getDatoFila(i),m1.getDatoDato(i));
    return m3;
}
template <class elemento>
Matriz<elemento> Multiplicar(Matriz<elemento> &m1, Matriz<elemento> &m2){
    Matriz<elemento> m3;
    if(m1.getColumna() == m2.getFila()){
        m3.setFila(m1.getFila());
        m3.setColumna(m2.getColumna());
        m1.ordenarporFilas();
        m2.ordenarporColumnas();
        elemento multiplicacion;
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
            if (i!=0)
                if(m1.getDatoFila(i-1))
                    if (multiplicacion!=0)
                        m3.insertar(m1.getDatoFila(i), m1.getDatoColumna(i), multiplicacion);
        }
    }
    return m3;
}

#endif //MATRIZ_OPERACIONESDEMATRICES_H
