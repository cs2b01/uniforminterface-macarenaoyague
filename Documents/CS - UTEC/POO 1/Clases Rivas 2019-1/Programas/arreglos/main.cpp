#include <iostream>
using namespace std;

#include <vector>

#include "funciones.h"

int main() {
    vector <int> vec;
    vec=llenar_vector(100);
    prom(vec);
    return 0;
}