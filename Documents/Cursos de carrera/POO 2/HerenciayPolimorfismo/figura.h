//
// Created by estanislao.contreras on 8/19/2019.
//

#ifndef POO2_FIGURA_H
#define POO2_FIGURA_H

#include "centroide.h"

enum Signo{
    positivo = 1,
    negativo = -1
};


class Figura {
protected:
    Signo signo;
    Centroide *centroide;
public:
    Figura(float x, float y, Signo signo);
    virtual float calcularArea() = 0;
    Signo getSigno() const;
    Centroide *getCentroide() const;

    virtual ~Figura();

};


#endif //POO2_FIGURA_H
