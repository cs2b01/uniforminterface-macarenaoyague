//
// Created by Macarena Oyague on 2019-06-04.
//

#ifndef CLASES_PANTALLA_H
#define CLASES_PANTALLA_H

#include <string>
using namespace std;

class Pantalla {
private:
    int largo;
    int ancho;
    bool prendido;
    std::string marca;
public:
    Pantalla();
    Pantalla(int l, int a, bool p,std::string marca);
    ~Pantalla();
    void prender();
    void apagar();
    bool get_prendido();
    string get_modelo();
};


#endif //CLASES_PANTALLA_H
