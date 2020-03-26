//
// Created by Macarena Oyague on 2019-08-28.
//

#ifndef ASSESMENT_TRIANGULO_H
#define ASSESMENT_TRIANGULO_H


#include "figura.h"

class triangulo: public figura{
private:
    double base, altura;
public:
    triangulo(double x, double y, double base, double altura);
};


#endif //ASSESMENT_TRIANGULO_H
