//
// Created by Macarena Oyague on 2019-09-11.
//

#ifndef MATRIZ_SOBRECARGADEOPERADORES_H
#define MATRIZ_SOBRECARGADEOPERADORES_H

#include "Matriz.h"
#include "OperacionesDeMatrices.h"

template <class elemento>
Matriz<elemento> operator +(Matriz<elemento> &m1, Matriz<elemento> &m2)
{
    return Sumar(m1,m2);
}

template <class elemento>
Matriz<elemento> operator *(Matriz<elemento> &m1, Matriz<elemento> &m2)
{
    return Multiplicar(m1,m2);
}

template <class elemento>
Matriz<elemento> operator -(Matriz<elemento> &m1, Matriz<elemento> &m2)
{
    return Restar(m1,m2);
}

template <class elemento>
Matriz<elemento> operator *(float escalar, Matriz<elemento> &m)
{
    return ProductoEscalar(m,escalar);
}

template <class elemento>
Matriz<elemento> operator +(Matriz<elemento> &m)
{
    return RealizarTranspuesta(m);
}

#endif //MATRIZ_SOBRECARGADEOPERADORES_H
