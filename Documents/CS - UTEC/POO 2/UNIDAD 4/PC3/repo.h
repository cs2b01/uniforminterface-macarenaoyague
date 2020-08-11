//
// Created by Macarena Oyague on 2019-11-09.
//
using namespace std;
#include "string"
#include <fstream>

#ifndef PC3_REPO_H
#define PC3_REPO_H



template <class T>

class Repo{

private:

    string separador;

    vector<T*>* elements;

public:

    Repo(const string &separador) : separador(separador) {
        elements = new vector<T*>;
    }

    vector<T*> *getElements() const {
        return elements;
    }

    const string &getSeparador() const {
        return separador;
    }

    Repo<T>* insert(T* item){
        elements->push_back(item);
        Repo<T>* insert = this;
        return insert;
    }

    Repo<T>* load_from(string fileName, function<T* (string)> deserializer){
        fstream* archivo = new fstream(fileName, ios_base::in);
        string linea;
        if (archivo){
            getline(*archivo,linea);
            while (getline(*archivo,linea)){
                T* elemento = deserializer(linea);
                elements->push_back(elemento);
            }
            archivo->close();
        }
        delete archivo;
        Repo<T>* load_from = this;
        return load_from;
    }

    Repo<T>* save_to(string fileName, function<string (T*)> serializer){
        fstream* archivo = new fstream(fileName, ios_base::out);
        if (archivo) {
            for(T* elemento: *elements)
                *archivo << serializer(elemento)<<endl;
            archivo->close();
        }
        delete archivo;
        Repo<T>* save_to = this;
        return  save_to;
    }

    vector<T*>* select(function<bool (T*)> where, function<bool(T*,T*)> order_by){
        std::vector<T*>* selectedElements = new vector<T*>;
        for (T* elemento: *elements)
            if(where(elemento))
                selectedElements->push_back(elemento);
        sort(selectedElements->begin(), selectedElements->end(), order_by);
        return selectedElements;
    }

    void select_and_save(string fileName, function<bool (T*)> where, function<bool(T*,T*)> order_by, function<string (T*)> serializer ){
        fstream* archivo = new fstream(fileName, ios_base::out);
        if (archivo) {
            for(T* element: *elements)
                *archivo << serializer(element)<<endl;
            archivo->close();
        }
        delete archivo;
    }

    unsigned int count(function<bool (T*)> where){
        unsigned int count = 0;
        for(T* elemento: *elements)
            if (where(elemento))
                count++;
        return count;
    }

    T* min(function<bool (T*)> where, function<bool (T*, T*)> comp){
        T* min;
        int cont = 0;
        for (T* elemento: *elements)
            if(where(elemento))
                if (cont==0)
                {
                    min  = elemento;
                    cont++;
                }
                else
                {
                    comp(min, elemento);
                    if (!comp(min, elemento))
                        min = elemento;
                }
        return min;
    }

    T* max(function<bool (T*)> where, function<bool (T*, T*)> comp){
        T* max;
        int cont = 0;
        for (T* elemento: *elements)
            if(where(elemento))
                if (cont==0)
                {
                    max  = elemento;
                    cont++;
                }
                else
                {
                    if (!comp(max, elemento))
                        max = elemento;
                }
        return max;
    }

    double sum(function<bool (T*)> where, function<double (T*)> accumulate){
        double acumulando = 0;
        for (T* elemento: *elements)
            if(where(elemento))
                acumulando += accumulate(elemento);
        return acumulando;
    }

    virtual ~Repo() {
        for(T* elemento: *elements)
            delete elemento;
        delete elements;
    }

};




#endif //PC3_REPO_H
