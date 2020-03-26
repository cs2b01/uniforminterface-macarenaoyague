//
// Created by Macarena Oyague on 2019-08-26.
//

#ifndef CLASES_EXAMPLE_OLA_H
#define CLASES_EXAMPLE_OLA_H

#include <string>
#include <iostream>
using namespace std;

class OLA {
public:
    OLA(int &edad, const string &name);
    OLA();
    OLA(int edad);
    OLA(const string &name);
    void setEdad(int edad);
    void setName(const string &name);
    int getEdad();
    string getName();
    void read();

    virtual ~OLA();

private:
    int edad;
    string name;
};


#endif //CLASES_EXAMPLE_OLA_H
