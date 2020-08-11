#include <iostream>
#include <string>
using namespace std;

// Plantilla de Funciones / Funcion generica
// Esta parametrizando los argumentos y el retorno de la funcion
template <class T>
T getMax(T n1, T n2){
    return n1 > n2 ? n1 : n2;
}



int main() {
    // Uso de la plantilla o funcion generica
    // Se tiene que especificar el tipo de dato de la plantilla.
    cout<<getMax<int>(12,20)<<endl;
    cout<<getMax<double>(45454.3,2)<<endl;
    cout<<getMax<string>("xyz","yab")<<endl;
    return 0;
}