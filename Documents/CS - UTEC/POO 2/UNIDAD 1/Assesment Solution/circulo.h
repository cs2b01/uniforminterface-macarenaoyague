//
// Created by estanislao.contreras on 8/19/2019.
//

#ifndef POO2_CIRCULO_H
#define POO2_CIRCULO_H

#include "figura.h"

class Circulo : public Figura {
private:
    float r;
public:
    Circulo(float x, float y, Signo signo, float r);

    float calcularArea() override;

    float getR() const;

    void setR(float r);

};


#endif //POO2_CIRCULO_H
