#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

class Palabra{
private:
    string palabra;
    unsigned int contador;
public:
    Palabra(const string &palabra, unsigned int contador) : palabra(palabra), contador(contador) {}

    const string &getPalabra() const {
        return palabra;
    }

    unsigned int getContador() const {
        return contador;
    }
};

class Biblia{
private:
public:
    Palabra* obtnerPalabraMasUsada(){
        auto* contador = new map<string , unsigned int>();
        fstream* archivo = new fstream("biblia.txt", ios::in);
        string palabra;
        if (archivo){
            while (*archivo >> palabra){
                (*contador)[palabra]++;
            }
            archivo->close();
        }
        delete archivo;
        string palabrita;
        unsigned int mayor = 0;
        for(auto it = contador->begin(); it!=contador->end(); it++){
            if (it->second > mayor){
                palabrita = it->first;
                mayor = it->second;
            }
            cout<<it->first << " "<<it->second << " veces "<<endl;
        }
        return new Palabra(palabrita, mayor);
    }
};

int main() {
    Biblia* biblia = new Biblia();
    Palabra* palabra = biblia->obtnerPalabraMasUsada();
    cout<<"La palabra mas usada en la biblia es "<<palabra->getPalabra()<<endl;
    cout<<"Se repite "<<palabra->getContador()<<" veces"<<endl;
    delete palabra;
    delete biblia;
    return 0;
}