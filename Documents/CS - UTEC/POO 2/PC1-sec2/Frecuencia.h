//
// Created by Macarena Oyague on 2019-09-15.
//

#ifndef PC1_SEC2_FRECUENCIA_H
#define PC1_SEC2_FRECUENCIA_H

#include <vector>
using namespace std;
#include "string"
#include <fstream>
#include <iostream>
#include <sstream>


class Frecuencia {
private:
    vector <int> *notasTxt;
    vector <int> *frecuencias;
    string fileName;
public:
    Frecuencia(const string &fileName);
    Frecuencia();
    void abrirArchivo(string &fileName);
    void vaciarDatos();
    vector <int> * valoresXi();
    vector <int> * frecuenciaAbsoluta();
    vector <int> * frecuenciaAbsolutaAcumulada();
    vector <int> * frecuenciaRelativa();
    vector <int> * frecuenciaRelativaAcumulada();
    void calcularFrecuencias();
};


#endif //PC1_SEC2_FRECUENCIA_H
