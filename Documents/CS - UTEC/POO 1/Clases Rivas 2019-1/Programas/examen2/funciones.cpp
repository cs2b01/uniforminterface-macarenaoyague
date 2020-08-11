//
// Created by Macarena Oyague on 2019-04-28.
//
#include <iostream>
#include "funciones.h"
using namespace std;

void correr_reloj(){
    int n;
    cout<<"Inserte un número entero: ";
    cin>>n;
    reloj(n);
}

void reloj(int numero){
    int contador1=2, contador2=numero-1;
    for (int x=1;x<=numero;x++){
        cout<<"*";
        if (x==numero)
            cout<<endl;
    }
    for(int x=1;x<=(numero-1)/2; x++){
        for (int y=1;y<=(numero); y++){
            if (y==contador1)
                cout<<"*";
            if (y==contador2-1)
                cout<<"*";
            else
                cout<<" ";
        }
        contador1=contador1+1;
        contador2=contador2-1;
        cout<<endl;
    }
    contador1=(numero+1)/2; contador2=contador1+1;
    for(int x=1;x<=(numero-1)/2; x++){
        for (int y=1;y<=(numero); y++){
            if (y==contador1)
                cout<<"*";
            if (y==contador2-1)
                cout<<"*";
            else
                cout<<" ";
        }
        contador1=contador1-1;
        contador2=contador2+1;
        cout<<endl;
    }
    for (int x=1;x<=numero;x++){
        cout<<"*";
        if (x==numero)
            cout<<endl;}
}

void reloj2(int numero){

};

void correr_sumatoria(){

};

void sumatoria(int n){
    float suma=0.0;
    float num=1, num_menos_1=1, num_menos_2=1, temp=0;
    //posicion 1
    for (int x=3; x<=n; x++){
        num=num_menos_1+num_menos_2;
        num_menos_2=num_menos_1;
        num_menos_1=num;
        suma=1/num;
    }
    cout<<"Suma: "<<suma;
};
float sumatoria_2(int n){
    float suma=0.0;
    if (n==1)
        return 1;
    if(n==2)
        return 1;
    else
        return ((sumatoria_2(n-1))+sumatoria_2(n-2));
}

void mostrar_sumatoria_2(int n){
    cout<<1/sumatoria_2(n);
}
