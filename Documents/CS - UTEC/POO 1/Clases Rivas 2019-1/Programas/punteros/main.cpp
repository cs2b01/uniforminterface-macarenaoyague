#include <iostream>
#include "ejemplos.h"
using namespace std;
#include<random>

int main() {
    random_device rd;

    int n=10;
    int *pi1=new int[n];
    int *pi1_otramanera;
    pi1_otramanera=new int;
    int *pi2=new int[n]();
    int *pi3=new int[n] {1,2,3,4,5,6,7,8,9,10};

    for (int i=0; i<n; i++)
        cout<<pi1[i]<<", ";
    cout<<endl;

//usando aritmetica de punteros
    for (int i=0;i<n;i++)
        cout<<*(pi1+i)<<", ";
    cout<<endl;

    delete []pi1;
    delete []pi2;
    delete []pi3;
    delete []pi1_otramanera;

    int sizearray;
    cout<<"tamaño del arreglo: ";
    cin>>sizearray;
    int *array=new int [sizearray];
    for (int i=0; i<sizearray;i++)
//necesito numeros del 1-20, por eso que hago +1, ya que esto hace numeros del 0-19
        array[i]=rd()%20+1;
    int dato;
    cout<<"dato a buscar: ";
    cin>>dato;
    int contador=0;
    for (int i=0; i<sizearray;i++)
        if (dato==array[i])
            contador++;
    cout<<"numero de veces encontrado el dato en el array: "<<contador<<endl;
    delete [] array;

    int numero;
    cout<<"numero n: ";
    cin>>numero;
    int *arreglo=new int [numero];
    for (int i=0; i<numero;i++)
//del 0 al 4 + 1
        arreglo[i]=rd()%5+1;
    for (int i=0; i<numero;i++)
        cout<<arreglo[i]<<", ";
    cout<<endl;
    int numero_m;
    cout<<"numero m: ";
    cin>>numero_m;
    int *temp=new int [numero_m+numero];
    for (int i=0; i<numero;i++)
        temp[i]=arreglo[i];
    delete [] arreglo;
    int add_aleatorio;
    for (int i=numero; i<(numero_m+numero); i++)
    {
        add_aleatorio=0;
        while (add_aleatorio<=5)
            add_aleatorio=rd()%10+1;
        temp[i]=add_aleatorio;
    }
    arreglo=temp;
    cout<<"tamaño del arreglo n+m: "<<numero+numero_m<<endl;
    for (int i=0; i<(numero_m+numero); i++)
        cout<<arreglo[i]<<", ";
    cout<<endl;
    for (int i=0; i<(numero_m+numero); i++)
        cout<<temp[i]<<", ";
    cout<<endl;
    delete [] arreglo;
    delete [] temp;
    

    int fila=8, columna=4;
    //puntero que apunta a arreglo de punteros
    int **pMatriz=new int*[fila];
    for (size_t i=0;i<fila;i++)
        //cada puntero del arreglo apunta a un arreglo
        pMatriz[i]=new int[columna];
    //matriz filaxcolumna creada

    for (int x=0;x<fila;x++)
        for (int y=0;y<columna;y++)
            pMatriz[x][y]=rd()%20+1;

    for (int x=0;x<fila;x++)
        for (int y=0;y<columna;y++)
            cout<<pMatriz[x][y]<<", ";

    cout<<endl<<endl;

    int suma;

    for (int x=0;x<fila;x++)
    {
        suma=0;
        for (int y=0;y<columna;y++)
        {
            suma=suma+pMatriz[x][y];
        }
        cout<<"la suma de fila "<<x+1<<" es "<<suma<<endl;
    }
    cout<<endl;

    for (int x=0;x<columna;x++)
    {
        suma=0;
        for (int y=0;y<fila;y++)
        {
            suma=suma+pMatriz[y][x];
        }
        cout<<"la suma de columna "<<x+1<<" es "<<suma<<endl;
    }
    cout<<endl;

    pMatriz[1][2]=10;
    //pMatriz guarda la dirección del puntero 0
    //el puntero 0 guarda la dirección de un arreglo
    cout<<*(*(pMatriz+1)+2);

    return 0;
}