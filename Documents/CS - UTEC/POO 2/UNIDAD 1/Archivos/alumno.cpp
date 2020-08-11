//
// Created by estanislao.contreras on 10/5/2019.
//

#include <string>

using namespace std;

class Alumno{
private:
    string nombreCompleto;
public:
    Alumno(string nombreCompleto):nombreCompleto(nombreCompleto){

    }

    string getNombreCompleto() const{
        return nombreCompleto;
    }
};

