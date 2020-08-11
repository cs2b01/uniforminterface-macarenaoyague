#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <thread>
#include <sstream>
#include <future>

using namespace std;


class Calc{
private:
    vector <float> *elementos;
public:
    Calc() {
        elementos=new vector <float>;
    }

    void registrarElemento(float elemento){
        elementos->push_back(elemento);
    }

    size_t obtenerNumeroElementos(){
        size_t NumeroElementos=elementos->size();
        return NumeroElementos;
    }

    float obtenerElementoMayor(){
        float mayor=elementos->at(0);
        for (size_t i=1; i<obtenerNumeroElementos(); i++)
            if(elementos->at(i)>mayor)
                mayor=elementos->at(i);
        return mayor;

    }

    float obteneElementoMenor(){
        float menor=elementos->at(0);
        for (size_t i=1; i<obtenerNumeroElementos(); i++)
            if(elementos->at(i)<menor)
                menor=elementos->at(i);
        return menor;
    }

    float calcularPromedio(){
        float suma=0;
        for (size_t i=0; i<obtenerNumeroElementos(); i++)
            suma=suma+elementos->at(i);
        float promedio=suma/(obtenerNumeroElementos());
        return promedio;
    }

    void ordenar(){
        float temp;
        for (size_t i=0; i<obtenerNumeroElementos();i++)
            for (size_t a=0; a<obtenerNumeroElementos(); a++)
            if ((elementos->at(i))>(elementos->at(a)))
            {
                temp=elementos->at(i);
                elementos->at(i)=elementos->at(a);
                elementos->at(a)=temp;
            }
    }

    float obtenerMediana(){
        ordenar();
        float mediana;
        size_t size=obtenerNumeroElementos();
        if ((size%2)==0)
            mediana=(elementos->at((size-1)/2)+elementos->at(((size-1)/2)+1))/2;
        else
            mediana=(elementos->at(size/2));
        return mediana;
    }


    ~Calc(){
        delete elementos;
   }



};
