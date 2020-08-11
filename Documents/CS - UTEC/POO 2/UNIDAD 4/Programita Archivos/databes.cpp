
//
// Created by Macarena Oyague on 2019-10-08.
//

#include <iostream>
#include <vector>
using namespace std;
#include "string"
#include <fstream>
#include <sstream>

class Database {

private:

    vector <int> *id;
    vector <string> *gender;
    vector <int> *year;
    vector <string> *name;
    string fileName;

public:

    Database(const string &fileName): fileName(fileName) {
        this->id=new vector<int>;
        this->gender=new vector<string>;
        this->year=new vector<int>;
        this->name=new vector<string>;
    }

    void vaciarDatos(){
        ifstream fileNotas;
        fileNotas.open(fileName);
        string element;
        auto idString=new vector<string>;
        auto yearString=new vector<string>;
        int contador = 1;
        while (getline(fileNotas, element, ','))
        {
            if (contador == 1)
                idString->push_back(element);
            else if (contador == 2)
                gender->push_back(element);
            else if (contador == 3)
                yearString->push_back(element);
            else
            {
                name->push_back(element);
                contador=0;
            }
            contador++;
        }
        for (size_t i=0; i<yearString->size(); i++)
        {
            stringstream stringYear(yearString->at(i));
            stringstream stringId(idString->at(i));
            int yearInt;
            int idInt;
            stringYear>>yearInt;
            year->push_back(yearInt);
            stringId>>idInt;
            id->push_back(idInt);
        }
        delete idString;
        delete yearString;
    }

    void getDatos(){
        for (int i=0; i<year->size(); i++)
            cout<<id->at(i)<<" "<<year->at(i)<<" "<<gender->at(i)<<" "<<name->at(i)<<endl;
    }
};
