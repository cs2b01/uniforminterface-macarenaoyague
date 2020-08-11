//
// Created by estanislao.contreras on 8/19/2019.
//

#ifndef POO2_AREA_COMPUESTA_H
#define POO2_AREA_COMPUESTA_H

#include <vector>
#include "figura.h"
using namespace std;


class AreaCompuesta {
private:
    vector<Figura*>* figuras;
public:
    AreaCompuesta();
    void componerArea(Figura* figura);
    Centroide* calcularCentroide();

    virtual ~AreaCompuesta();

};


#endif //POO2_AREA_COMPUESTA_H
