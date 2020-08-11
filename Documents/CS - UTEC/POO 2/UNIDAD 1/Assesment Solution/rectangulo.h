//
// Created by estanislao.contreras on 8/19/2019.
//

#ifndef POO2_RECTANGULO_H
#define POO2_RECTANGULO_H

#include "triangulo.h"

class Rectangulo : public Triangulo {
public:
    Rectangulo(float x, float y, Signo signo, float b, float h);

    float calcularArea() override;
};


#endif //POO2_RECTANGULO_H
