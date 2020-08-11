//
// Created by Macarena Oyague on 2019-10-09.
//

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Conjuntos{

private:
    vector<string>* conjunto;

public:

    Conjuntos(vector<string> *conjunto) : conjunto(conjunto) {};

    vector<string> *getConjunto() const {
        return conjunto;
    }

    void ImprimirA(){
        string linea, letra, signo, elementos, name, a;
        fstream *archivo = new fstream("conjuntos.txt", ios_base::in);
        fstream *temp = new fstream("temp.txt", ios_base::out);

        if(archivo){
            while(!archivo->eof()) {
                *archivo >> letra >> signo >> elementos;
                *temp << elementos << endl;
            }
        }
        archivo->close();

        temp->open("temp.txt", ios_base::in);

        if(temp){
            string T;
            while(getline(*temp, T, ','));
            cout << T << " ";
            temp->close();
        }
    }

};