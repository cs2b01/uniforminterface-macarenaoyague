#include <iostream>
#include <string>
using namespace std;

template <class T>
T buscarPrimeroQue(T* array, bool condicion(T)){
    for ( ; array!= nullptr ; array++) {
        if (condicion(*array))
            return *array;
    }
    return T();
}

bool esPar(int n){
    return n%2 == 0;
}

bool esImpar(int n){
    return n%2 == 1;
}

bool esNegativo(int n){
    return n < 0;
}


int main() {
    int numeros[] = {11,23,25,20,-2,22,27};
    cout<<buscarPrimeroQue(numeros,esPar)<<endl;
    cout<<buscarPrimeroQue(numeros,esImpar)<<endl;
    cout<<buscarPrimeroQue(numeros,esNegativo)<<endl;
    return 0;
}