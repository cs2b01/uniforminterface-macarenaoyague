//
// Created by Macarena Oyague on 2019-10-08.
//

#include <vector>
using namespace std;
#include "string"
#include <fstream>
#include <iostream>
#include <sstream>


class Frecuencia {
private:
    vector <int> *notasTxt;
    string fileName;
public:
    Frecuencia(const string &fileName): fileName(fileName) {
        this->notasTxt=new vector<int>;
    }

    Frecuencia();

    void abrirArchivo(string &fileName);

    void vaciarDatos(){
        ifstream fileNotas;
        fileNotas.open(fileName);
        string number;
        auto notasString=new vector<string>;
        while (getline(fileNotas, number, ','))
            notasString->push_back(number);
        for (size_t i=0; i<notasString->size(); i++)
        {
            stringstream notaString(notasString->at(i));
            int notaInt;
            notaString>>notaInt;
            notasTxt->push_back(notaInt);
        }
    }

    void getNotas(){
        for (int nota: *notasTxt)
            cout<<nota<<" ";
    }
};
