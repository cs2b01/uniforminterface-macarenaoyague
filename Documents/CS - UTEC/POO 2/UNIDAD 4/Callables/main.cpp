#include <iostream>
using namespace std;
#include <functional>
#include "cmath"

#include <vector>

void print(const string& value) {
    cout << value << endl;
}

class Consola{
private:
    vector<string>* lineas;
public:
    Consola(){
        lineas = new vector<string>();
    };
    void out(string linea){
        lineas->push_back(linea);
    }
    void operator()(){//sobrecarga
        for(auto linea: *lineas)
            cout<<linea<< endl;
    }
};

class Printer{
public:
    void print(){
        cout<<"Prueba de ejecucion de metodo"<<endl;
    }
    void print2(const string& value){
        cout<<value<<endl;
    }
    void nombre(const string& value){
        cout<<"Mi nombre es"<<value<<endl;
    }
    void print_consola(Consola consola){
        consola();
    }
};

void PRUEBA(function<void(string)>funcion){
    funcion("hola");
}

bool AA(function<vector<string>()>funcionn, string a){
    vector<string> v = funcionn();
}

void PRUEBA2(void(*f)(const string&)){
    (*f)("hola");
}

void PRUEBA3 (function<void(Printer&)> method, Printer printer){
    method(printer);
}


vector<string> printt() {
    vector<string> aaa;
    return aaa;
}

int main() {

    AA(printt,"f");


    // Declaracion de puntero a funcion
    function<void(const string&)>funcion;
    // Asignación de direccion de memoria a puntero
    funcion = print;

    PRUEBA(funcion);
    PRUEBA(print);

    PRUEBA2(print);


    // Ejecución de la funcion a traves del puntero
    funcion("Imprimir a traves de puntero a funcion");

    // Declarar puntero a metodo y asignar la direccion de memoria del metodo
    auto puntero_metodo= & Printer::print;
    // Declara objeto
    Printer* printer = new Printer();
    // Ejecutar el metodo a traves del puntero a metodo
    (printer->*puntero_metodo)();



    //4-functors:
    Consola consola; //sin puntero
    consola.out("Linea 1");
    consola.out("Linea 2");
    consola.out("Linea 3");
    consola();//recien en esta linea, hace toda la imprecion de las lineas.

    printer->print_consola(consola);//aca se pasa por parametro, y se le llama a sus funciones(que tienen el parentesis adentro) imprimiendo lo mismo.

    //5. Expresiones lambda:
    //declaramos la funcion anonima
    auto power = [](float base, float exp){return pow(base, exp);};
    // Uso de la funcion anonima.
    cout<<power(10,2)<<endl;


    // Declaracion de puntero a funcion
    void (*puntero_funcion)(const string&);
    // Asignación de direccion de memoria a puntero
    puntero_funcion = print;
    // Ejecución de la funcion a traves del puntero
    puntero_funcion("Imprimir a traves de puntero a funcion");

    // Declarar puntero a metodo y asignar la direccion de memoria del metodo
    auto puntero_metodo2 = & Printer::print;


    // Declara objeto
    Printer printer2;

    PRUEBA3(&Printer::print, printer2);

    // Ejecutar el metodo a traves del puntero a metodo
    (printer2.*puntero_metodo2)();

    return 0;
}

