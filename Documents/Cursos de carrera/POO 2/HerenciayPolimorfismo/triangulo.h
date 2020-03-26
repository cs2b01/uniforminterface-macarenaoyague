//
// Created by estanislao.contreras on 8/19/2019.
//

#ifndef POO2_TRIANGULO_H
#define POO2_TRIANGULO_H

#include "figura.h"

class Triangulo : public Figura {
protected:
    float b;
    float h;
public:
    Triangulo(float x, float y, Signo signo, float b, float h);

    float calcularArea() override;

    float getB() const;

    void setB(float b);

    float getH() const;

    void setH(float h);
};


#endif //POO2_TRIANGULO_H
