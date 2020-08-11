#include <iostream>

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "SobrecargaDeOperadores.h"
#include "Matriz.h"


void Pruebas1();
//void Pruebas2();

int Main() {
    Pruebas1();
    return 0;

}


void Pruebas1(){
    Matriz<float> m1(2,3);
    m1.setDatoFila(0,1);
    m1.setDatoColumna(0,1);
    m1.setDatoDato(0,1);
    m1.setDatoFila(1,1);
    m1.setDatoColumna(1,2);
    m1.setDatoDato(1,2);
    m1.setDatoFila(2,1);
    m1.setDatoColumna(2,3);
    m1.setDatoDato(2,3);
    Matriz<float>m2(3,2);
    m2.setDatoFila(0,1);
    m2.setDatoColumna(0,1);
    m2.setDatoDato(0,3);
    m2.setDatoFila(1,2);
    m2.setDatoColumna(1,1);
    m2.setDatoDato(1,8);
    m2.setDatoFila(2,3);
    m2.setDatoColumna(2,1);
    m2.setDatoDato(2,0);

    Matriz<float> m5=m1*m2;
    cout<<endl<<"Matriz m5=m1*m2:";
    cout<<endl<<m5.getDatoDato(0);
    cout<<endl<<m5.getDatoFila(0);
    cout<<endl<<m5.getDatoColumna(0);
    Matriz<float> m6=2.6*m1;
    cout<<endl<<"Matriz m6=2.6*m1:";
    cout<<endl<<m6.getDatoDato(0);
    cout<<endl<<m6.getDatoFila(0);
    cout<<endl<<m6.getDatoColumna(0);
    Matriz <float>m7=+m1;
    cout<<endl<<"Matriz m7=+m1:";
    cout<<endl<<m7.getDatoDato(0);
    cout<<endl<<m7.getDatoFila(0);
    cout<<endl<<m7.getDatoColumna(0);

    Matriz <float>m17(4,3);
    m17.setDatoFila(0,1);
    m17.setDatoColumna(0,1);
    m17.setDatoDato(0,1);
    m17.setDatoFila(1,1);
    m17.setDatoColumna(1,2);
    m17.setDatoDato(1,2);
    m17.setDatoFila(2,1);
    m17.setDatoColumna(2,3);
    m17.setDatoDato(2,3);
    Matriz <float>m18(4,3);
    m18.setDatoFila(0,1);
    m18.setDatoColumna(0,1);
    m18.setDatoDato(0,3);
    m18.setDatoFila(1,2);
    m18.setDatoColumna(1,1);
    m18.setDatoDato(1,8);
    m18.setDatoFila(2,3);
    m18.setDatoColumna(2,1);
    m18.setDatoDato(2,0);

    Matriz <float>m3=(m17+m18);
    cout<<endl<<"Matriz m3=m17+m18:";
    cout<<endl<<m3.getDatoDato(0);
    cout<<endl<<m3.getDatoFila(0);
    cout<<endl<<m3.getDatoColumna(0);
    Matriz <float>m4=(m17-m18);
    cout<<endl<<"Matriz m4=m1-m2:";
    cout<<endl<<m4.getDatoDato(0);
    cout<<endl<<m4.getDatoFila(0);
    cout<<endl<<m4.getDatoColumna(0);
}