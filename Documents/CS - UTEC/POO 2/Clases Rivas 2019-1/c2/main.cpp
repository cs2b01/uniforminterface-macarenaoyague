//dynamic
// create variables not in regular computer memory, instead in head

#include <iostream>

using namespace std;

int* print(int*);

//print-print the value of pointer is pointing to
//int*-pointer that is pointing to an integer


int main() {

    int* p1;
    p1 = new int; //point to an unknown integer

    *p1 = 45;

    print(p1);
    //no usamos el special caracter si es que ya lo pusimos en la funcion

    return 0;
}
 int* print (int *pointer){
    cout<<"Pointer 1 "<<*pointer<<endl;
    return pointer;
}


//DMA: pointer is a variable whose value is the address of another variable
//ponters allow to refer to the same space in memory from multiple locations
//if i update memory in one location, the change can be seen from another location
//i save space being able to share the components in my data structures
//DMA: set array size dynamically during run time rather than at compile time
//helps when i dont know in advance about the number of items (variable values) to be stored

//puntero int* a guardado en el stack y apunta al heat
//el puntero tiene el tamaño igual no importa si apunta a double, string, etc
//no hay direcciones mas grandes ni chicas, son del mismo tamaño
//size of puntero es 0
//el ultimo puntero q se crea es el primero q se destruye



// puntero: valor de x, nombre x, tipo (it, double, char..) seguido por *, direccion &x,
//indireccion/de referencia es *x
//usos del puntero: utilizar memoria dinamica , polimorfismo, arreglos, referencias
//guarda en el stack, la unica manera de acceder al heap es por medio de punteros,
// en otra zona de memoria guarda el codigo, en otra la memoria estatica (estas dos ultimas
// no las exploraremos por ahora) <imagen1>

//stack=monton
//heap=pila, se va a apilar, lo ultimo que entra es lo primero que sale

//  a) int* x ( se crea en el stack)<imagen 1>
//  b) x=new int (separa un espacio de memoria en el heat para que ingrese ahi un entero: cantidad de bytes)
//     (si quiero saber el tamaño uso sizeof)
//          mira el -calculo del espacio- (para eso es el tipo de variable),
//          ocurre la -reservación del espacio-<imagen 1>
//          y toma la primera dirección disponible en el heat -asignación de dirección-
//  c) *x=20 (le asigna a la dirección a guardar el numero 20, en la direccion guardada por el puntero le introduce el 20
//      porque habia guardado esa cantidad de bytes, en este caso 8) <imagen 1>
//  d) delete x (se tiene que borrar en orden porque es una pila <imagen2>)

//  a) int* y=new int [20] (reservo 20 espacios de memoria, pero en bytes es 8 de intx20 elementos)
//  b) delete [] y


//      para C...
//                  investigar el x=malloc(size)
//                  reservación de memoria con el x=malloc(sizeof(int))
//                  lo que hace es mas flexible
//                  *x=20
//                  pero ahi tengo que hacer el delete con free(x)
//                  para arreglos
//                  y=malloc(sizeof(int)*20)
//                  free(y)

//gestion de memoria capitulo 7
//ver vectores, es como una lista en python, es la estructura que por default debemos usar en c++
//