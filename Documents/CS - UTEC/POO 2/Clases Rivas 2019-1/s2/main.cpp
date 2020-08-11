#include <iostream>
using namespace std;

int main() {

    return 0;
}







//concepto tipo abstracto de datos. incluye algoritmo (estructura) y destruccion.


//lista simplemente enlazada: cada elemento se enlaza a traves de un puntero.
//      cada nodo tiene dos elementos: el valor por referencia y un puntero (referencia)
//      al siguiente nodo (un cuadrado dividido en dos)
//      value y next, tiene un puntero (head) y un elemento final tail
//      <ver imagen>
//  empty: si la lista esta vacía
//  print: imprimir la lista desde una posición i
//  size: cantidad de nodos