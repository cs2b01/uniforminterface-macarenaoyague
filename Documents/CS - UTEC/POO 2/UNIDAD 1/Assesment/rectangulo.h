//
// Created by Macarena Oyague on 2019-08-28.
//

#ifndef ASSESMENT_RECTANGULO_H
#define ASSESMENT_RECTANGULO_H


#include "cuadrado.h"

class rectangulo: public cuadrado{
private:
    double ancho;
public:
    rectangulo(double x, double y, double largo, double ancho);
};


#endif //ASSESMENT_RECTANGULO_H
