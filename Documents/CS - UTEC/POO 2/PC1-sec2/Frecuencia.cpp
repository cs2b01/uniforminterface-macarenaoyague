//
// Created by Macarena Oyague on 2019-09-15.
//

#include "Frecuencia.h"


Frecuencia::Frecuencia(const string &fileName) : fileName(fileName) {
    this->notasTxt=new vector<int>;
    this->frecuencias=new vector <int>;
}

Frecuencia::Frecuencia() {
    this->notasTxt=new vector<int>;
    this->frecuencias=new vector <int>;
    this->fileName=" ";
}

void Frecuencia::abrirArchivo(string &fileName) {
    this->fileName=fileName;
}

void Frecuencia::vaciarDatos() {
    ifstream fileNotas;
    fileNotas.open(fileName.c_str());
    string number;
    vector <string>* notasString=new vector<string>;
    while (getline(fileNotas, number, ','))
        notasString->push_back(number);
    vector <int> notasDesordenadas;
    for (size_t i=0; i<notasString->size(); i++)
    {
        stringstream notaString(notasString->at(i));
        int notaInt=0;
        notaString>>notaInt;
        notasDesordenadas.push_back(notaInt);
    }
    size_t c=0;
    for (size_t i=0; i<notasDesordenadas.size(); i++)
    {
        c=i;
        for (size_t a=c+1; a<notasDesordenadas.size(); a++)
            if (notasDesordenadas[c]<notasDesordenadas[a])
            {
                int temp=notasDesordenadas[c];
                notasDesordenadas[c]=notasDesordenadas[a];
                notasDesordenadas[a]=temp;
                c=a;
            }
    }

}

vector <int> * Frecuencia::valoresXi() {
    vector <int>* notas=new vector <int>;
    notas->push_back(notasTxt->at(0));
    for(size_t i=1; i<notasTxt->size(); i++)
        for (size_t a=0; a<notas->size(); a++)
            if (notasTxt->at(i)<8)
}

vector <int> * Frecuencia::frecuenciaAbsoluta() {
    frecuencias->push_back(notas->at(0));

}

vector <int> * Frecuencia::frecuenciaAbsolutaAcumulada() {

}

vector <int> * Frecuencia::frecuenciaRelativa() {

}

void Frecuencia::frecuenciaRelativaAcumulada() {

}

void Frecuencia::calcularFrecuencias() {
    if (fileName!=" ")
    {
        vaciarDatos();
        frecuenciaAbsoluta();
        frecuenciaAbsolutaAcumulada();
        frecuenciaRelativa();
        frecuenciaRelativaAcumulada();
    }
}
