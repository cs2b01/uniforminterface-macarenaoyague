//
// Created by Macarena Oyague on 2019-10-09.
//


#ifndef POSTULANTECIENCIAS_H
#define POSTULANTECIENCIAS_H

#include "postulante.h"

class PostulanteCiencias : public Postulante{
public:
    PostulanteCiencias(const string &facultad, const string &dni, const string &nombreCompleto, unsigned int lectura,
                       unsigned int redaccion, unsigned int matematica) : Postulante(facultad, dni, nombreCompleto,
                                                                                     lectura, redaccion, matematica) {}
    double calificacion() override{
        return 10*lectura+10*redaccion+7.5*matematica;
    }
};

#endif
