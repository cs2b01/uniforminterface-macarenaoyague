#include <iostream>
#include <string>
using namespace std;

class Power{
private:
    float exponent;
public:
    Power(float exponent) :exponent(exponent){

    }
    float operator()(float base ){
        return pow(base,exponent);
    }

};

int main() {

    // Inicializacion de objetos Power con su exponente
    Power* alcubo = new Power(3);
    Power* alcuadrado = new Power(2);

    // Ejecucion el functor() pasando la base
    cout<< (*alcubo)(2) << endl;
    cout<< (*alcuadrado)(5) << endl;

    delete alcubo;
    delete alcuadrado;

    return 0;
}