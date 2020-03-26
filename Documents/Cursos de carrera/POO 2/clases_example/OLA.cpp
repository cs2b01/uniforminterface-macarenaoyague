//
// Created by Macarena Oyague on 2019-08-26.
//

#include "OLA.h"

OLA::OLA(int &edad, const string &name){
    this->edad=edad;
    this->name=name;
}

OLA::OLA() {}

void OLA::setEdad(int edad) {
    this->edad=edad;
}

int OLA::getEdad() {
    return edad;
}

void OLA::read() {
    cout<<"Hola "<<name<<" tienes "<<edad<<" años.";
}

OLA::OLA(int edad) {
    this->edad=edad;
}

OLA::OLA(const string &name){
    this->name=name;
}

string OLA::getName() {
    return name;
}

OLA::~OLA() {

}

void OLA::setName(const string &name) {
    this->name=name;
}
