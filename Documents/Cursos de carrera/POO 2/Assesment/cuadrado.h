//
// Created by Macarena Oyague on 2019-08-28.
//

#ifndef ASSESMENT_CUADRADO_H
#define ASSESMENT_CUADRADO_H


#include "figura.h"

class cuadrado: public figura {
private:
    double largo;
public:
    cuadrado(double x, double y, double largo);
    void setLargo(double largo);
    double getLargo();
};


#endif //ASSESMENT_CUADRADO_H
