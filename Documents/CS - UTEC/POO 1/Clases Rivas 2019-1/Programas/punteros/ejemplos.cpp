//
// Created by Macarena Oyague on 2019-05-17.
//

#include "ejemplos.h"

#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

void ejemplo_1(){

    //crea el puntero en el stack
    double* ptrDouble= nullptr;
    cout<<ptrDouble<<endl;

    //guarda espacio en el HEAP

    //reservacion de acceso individual, guarda una dirección (primer byte) libre en heap del tamaño del type
    ptrDouble=new double;
    cout<<ptrDouble<<endl;

    cout<< sizeof(double)<<endl;
    cout<<ptrDouble+1<<endl;

    //modificando el espacio, valor anexado a la dirección que guardo
    *ptrDouble=10;
    cout<<*ptrDouble<<endl;
    *ptrDouble=*ptrDouble+20;
    cout<<*ptrDouble<<endl;

    //toda reservacion necesita ser borrada
    delete ptrDouble;
};

void ejemplo_2(){
    //la manera antigua, antes de que exista el new

    //reservacion utilizando malloc, es la forma
    int* ptrEntero=(int*)malloc(sizeof(int));
    delete ptrEntero;
}

void ejemplo_3(){

    srand(time(nullptr));

    //reservación de arreglo dinámico
    const int n=30;
    int* arr=new int [30];

    for (int i=0; i<n;i++)
        arr[i]=rand()%10;

    for (int i=0; i<n;i++)
        cout<<arr[i]<<endl;

    //liberacion del arreglo
    delete [] arr;
}