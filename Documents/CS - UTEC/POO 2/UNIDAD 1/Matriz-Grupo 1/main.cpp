#include <iostream>
#include "SobrecargaDeOperadores.h"

void PruebaSumayResta();
void PruebaMultiplicacion();
void PruebaProductoEscalaryTranspuesta();

int main(){
    PruebaSumayResta();
    PruebaMultiplicacion();
    PruebaProductoEscalaryTranspuesta();
}


void PruebaSumayResta(){

    Matriz m1(4,3);
    m1.setDatoFila(0,1);
    m1.setDatoColumna(0,1);
    m1.setDatoDato(0,1);
    m1.setDatoFila(1,1);
    m1.setDatoColumna(1,2);
    m1.setDatoDato(1,2);
    m1.setDatoFila(2,1);
    m1.setDatoColumna(2,3);
    m1.setDatoDato(2,3);

    cout<<endl<<"     Matriz m1"<<endl;
    cout<<endl<<"Datos no nulos: ";
    for (size_t i=0; i<m1.getSize();i++)
        cout<<endl<<m1.getDatoFila(i)<<"x"<<m1.getDatoColumna(i)<<":    "<<m1.getDatoDato(i);

    Matriz m2(4,3);
    m2.setDatoFila(0,1);
    m2.setDatoColumna(0,1);
    m2.setDatoDato(0,3);
    m2.setDatoFila(1,2);
    m2.setDatoColumna(1,1);
    m2.setDatoDato(1,8);
    m2.setDatoFila(2,3);
    m2.setDatoColumna(2,1);
    m2.setDatoDato(2,9);

    cout<<endl<<endl<<"     Matriz m2"<<endl;
    cout<<endl<<"Datos no nulos: ";
    for (size_t i=0; i<m2.getSize();i++)
        cout<<endl<<m2.getDatoFila(i)<<"x"<<m2.getDatoColumna(i)<<":    "<<m2.getDatoDato(i);

    Matriz m3=m1+m2;
    cout<<endl<<endl<<"     Matriz m3=m1+m2"<<endl;
    cout<<endl<<"Datos no nulos ";
    for (size_t i=0; i<m3.getSize();i++)
        cout<<endl<<m3.getDatoFila(i)<<"x"<<m3.getDatoColumna(i)<<":    "<<m3.getDatoDato(i);

    Matriz m4=m1-m2;
    cout<<endl<<endl<<"     Matriz m4=m1-m2"<<endl;
    cout<<endl<<"Datos no nulos ";
    for (size_t i=0; i<m4.getSize();i++)
        cout<<endl<<m4.getDatoFila(i)<<"x"<<m4.getDatoColumna(i)<<":    "<<m4.getDatoDato(i);

}

void PruebaMultiplicacion(){

    Matriz m1(6,8);
    m1.setDatoFila(0,4);
    m1.setDatoColumna(0,1);
    m1.setDatoDato(0,1);
    m1.setDatoFila(1,4);
    m1.setDatoColumna(1,2);
    m1.setDatoDato(1,2);
    m1.setDatoFila(2,4);
    m1.setDatoColumna(2,3);
    m1.setDatoDato(2,3);

    cout<<endl<<endl<<"     Matriz m1"<<endl;
    cout<<endl<<"Datos no nulos:    ";
    for (size_t i=0; i<m1.getSize();i++)
        cout<<endl<<m1.getDatoFila(i)<<"x"<<m1.getDatoColumna(i)<<":    "<<m1.getDatoDato(i);

    Matriz m2(8,3);
    m2.setDatoFila(0,1);
    m2.setDatoColumna(0,4);
    m2.setDatoDato(0,3);
    m2.setDatoFila(1,2);
    m2.setDatoColumna(1,4);
    m2.setDatoDato(1,8);
    m2.setDatoFila(2,3);
    m2.setDatoColumna(2,4);
    m2.setDatoDato(2,8);

    cout<<endl<<endl<<"     Matriz m2"<<endl;
    cout<<endl<<"Datos no nulos: ";
    for (size_t i=0; i<m2.getSize();i++)
        cout<<endl<<m2.getDatoFila(i)<<"x"<<m2.getDatoColumna(i)<<":    "<<m2.getDatoDato(i);


    Matriz m3=m1*m2;
    cout<<endl<<endl<<"     Matriz m3=m1*m2"<<endl;
    cout<<endl<<"Datos no nulos ";
    for (size_t i=0; i<m3.getSize();i++)
        cout<<endl<<m3.getDatoFila(i)<<"x"<<m3.getDatoColumna(i)<<":    "<<m3.getDatoDato(i);
}

void PruebaProductoEscalaryTranspuesta(){

    Matriz m1(14,35);
    m1.llenarRand(9,400);
    m1.ordenarporFilas();
    cout<<endl<<endl<<"     Matriz m1"<<endl;
    cout<<endl<<"Datos no nulos ";
    for (size_t i=0; i<m1.getSize();i++)
        cout<<endl<<m1.getDatoFila(i)<<"x"<<m1.getDatoColumna(i)<<":    "<<m1.getDatoDato(i);

    Matriz m2=2*m1;
    cout<<endl<<endl<<"     Matriz m2=2*m1"<<endl;
    cout<<endl<<"Datos no nulos ";
    for (size_t i=0; i<m2.getSize();i++)
        cout<<endl<<m2.getDatoFila(i)<<"x"<<m2.getDatoColumna(i)<<":    "<<m2.getDatoDato(i);

    Matriz m3=+m1;
    cout<<endl<<endl<<"     Matriz m3=+m1"<<endl;
    cout<<endl<<"Datos no nulos ";
    for (size_t i=0; i<m3.getSize();i++)
        cout<<endl<<m3.getDatoFila(i)<<"x"<<m3.getDatoColumna(i)<<":    "<<m3.getDatoDato(i);
}

