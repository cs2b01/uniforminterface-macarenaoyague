#include <iostream>
#include <string>

using namespace std;

void print(string message){
    cout<<message<<endl;
}

int main() {
    // Punteros a funciones

    // 1 Forma: Declaracion explicita
    //1.1  Declaracion del variable puntero a funcion
    //   que recibe un string y retorna void
    void (* ptr1 ) (string);
    //1.2 Asignando direccion de print a variable
    //   del tipo puntero
    ptr1 = print;

    //1.3. Ejecutando la funcion a traves del puntero
    ptr1("Hello, World with pointer");

    // 2 Forma : Declaracion automatica

    // 2.1 Declaracion de puntero y asignacion direccion
    //     de print
    auto ptr2 = print;
    // 2.2 Ejecutando la funcion a traves del puntero
    ptr2("Hello, World with auto");
    return 0;
}