
#include <vector>
#include <iostream>
#include <exception>

using namespace std;

class Calc{
private:
    std::vector<double>* elementos;
public:
    Calc() {
        elementos = new vector<double>();
    }

    void registrarElemento(double elemento){
        elementos->push_back(elemento);

    }

    unsigned int obtenerNumeroElementos(){
        return elementos->size();
    }

    double obtenerElementoMayor(){
        if (obtenerNumeroElementos()>0){
            double m = (*elementos)[0];
            for(double e : *elementos)
                if (e>m)
                    m = e;
            return m;
        }
        throw logic_error("No hay elementos");

    }

    double obtenerElementoMenor(){
        if (obtenerNumeroElementos()>0){
            double m = (*elementos)[0];
            for(double e : *elementos)
                if (e<m)
                    m = e;
            return m;
        }
        throw logic_error("No hay elementos");

    }

    double calcularPromedio(){
        if (obtenerNumeroElementos()>0){
            double s = 0;
            for(double e : *elementos)
                s+=e;
            return s/obtenerNumeroElementos();
        }
        throw logic_error("No hay elementos");
    }

    double obtenerMediana(){
        if (obtenerNumeroElementos()>0){
            for(unsigned int i=0; i<elementos->size()-1; i++)
                for (unsigned int j=i+1; j<elementos->size();j++)
                    if ( (*elementos)[i]>(*elementos)[j] )
                        swap((*elementos)[i],(*elementos)[j]);
            double mediana = 0;
            unsigned int m = (obtenerNumeroElementos() / 2);
            if (obtenerNumeroElementos() % 2 == 0)
                mediana = ((*elementos)[m-1]+(*elementos)[m])/2;
            else
                mediana = (*elementos)[m];
            return mediana;
        }
        throw logic_error("No hay elementos");
    }

    ~Calc(){

   }



};
