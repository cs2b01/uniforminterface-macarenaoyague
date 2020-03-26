//
// Created by estanislao.contreras on 8/19/2019.
//

#include "area_compuesta.h"
#include <iostream>

using namespace std;


AreaCompuesta::AreaCompuesta() {
    figuras = new vector<Figura*>();
}

void AreaCompuesta::componerArea(Figura *figura) {
    figuras->push_back(figura);
}

Centroide *AreaCompuesta::calcularCentroide() {
    float sumAiXi = 0,  sumAiYi=0, sumAi = 0 ;

    for(Figura* figura: *figuras){
        cout<<figura->getSigno()*figura->calcularArea()<<"*"<<figura->getCentroide()->getX()<<endl;
        cout<<figura->getSigno()*figura->calcularArea()<<"*"<<figura->getCentroide()->getY()<<endl;
        cout<<figura->getSigno()*figura->calcularArea()<<endl;
        cout<<"----------------"<<endl;

        sumAiXi += figura->getSigno()*figura->calcularArea()*figura->getCentroide()->getX();
        sumAiYi += figura->getSigno()*figura->calcularArea()*figura->getCentroide()->getY();
        sumAi += figura->getSigno()*figura->calcularArea();
    }
    return new Centroide(sumAiXi/sumAi, sumAiYi/sumAi);

}

AreaCompuesta::~AreaCompuesta() {
    for(Figura* figura: *figuras){
        delete figura;
    }
    delete figuras;
}
