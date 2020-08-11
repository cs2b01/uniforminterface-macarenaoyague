//
// Created by Macarena Oyague on 2019-09-06.
//

#ifndef INTENTOS_SOBRECARGADEOPERADORES_H
#define INTENTOS_SOBRECARGADEOPERADORES_H

#include "Matriz.h"
#include "OperacionesDeMatrices.h"

Matriz operator +(Matriz &m1, Matriz &m2)
{
    return Sumar(m1,m2);
}

Matriz operator *(Matriz &m1, Matriz &m2)
{
    return Multiplicar(m1,m2);
}

Matriz operator -(Matriz &m1, Matriz &m2)
{
    return Restar(m1,m2);
}

Matriz operator *(double escalar, Matriz &m)
{
    return ProductoEscalar(m,escalar);
}

Matriz operator +(Matriz &m)
{
    return RealizarTranspuesta(m);
}

#endif //INTENTOS_SOBRECARGADEOPERADORES_H
