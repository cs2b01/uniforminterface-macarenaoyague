//
// Created by Macarena Oyague on 2019-10-09.
//

#ifndef POSTULANTELETRAS_H
#define POSTULANTELETRAS_H

#include "postulante.h"

class PostulanteLetras: public Postulante{
public:
    PostulanteLetras(const string &facultad, const string &dni, const string &nombreCompleto, unsigned int lectura,
                     unsigned int redaccion, unsigned int matematica) : Postulante(facultad, dni, nombreCompleto,
                                                                                   lectura, redaccion, matematica) {}
    double calificacion() override{
        return 7.5*lectura+7.5*redaccion+10*matematica;
    }
};

#endif