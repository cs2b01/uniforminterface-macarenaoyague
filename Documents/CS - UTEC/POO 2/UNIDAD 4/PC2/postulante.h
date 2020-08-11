//
// Created by Macarena Oyague on 2019-10-09.
//
#ifndef POSTULANTE_H
#define POSTULANTE_H

#include <string>
using namespace std;

class Postulante{
protected:
    string facultad;
    string dni;
    string nombreCompleto;
    unsigned int lectura;
    unsigned int redaccion;
    unsigned int matematica;
public:
    Postulante(const string &facultad, const string &dni, const string &nombreCompleto, unsigned int lectura,
               unsigned int redaccion, unsigned int matematica) : facultad(facultad), dni(dni),
                                                                  nombreCompleto(nombreCompleto), lectura(lectura),
                                                                  redaccion(redaccion), matematica(matematica) {}
    virtual double calificacion() = 0;

    const string &getFacultad() const {
        return facultad;
    }

    const string &getDni() const {
        return dni;
    }

    const string &getNombreCompleto() const {
        return nombreCompleto;
    }

    unsigned int getLectura() const {
        return lectura;
    }

    unsigned int getRedaccion() const {
        return redaccion;
    }

    unsigned int getMatematica() const {
        return matematica;
    }
};

#endif
