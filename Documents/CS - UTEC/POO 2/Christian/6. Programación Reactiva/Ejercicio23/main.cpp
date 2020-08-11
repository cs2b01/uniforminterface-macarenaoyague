#include <iostream>
#include <string>;

using namespace std;

class Printer{
public:
    void print(string message){
        cout<<message;
    }
    void printline(string message){
        cout<<message<<endl;
    }

};

int main() {
    // Punteros a metodos

    // 1. Crear un objeto
    Printer* printer = new Printer();
    // 2. Obtener el puntero al método
    auto ptr = &Printer::print;
    // 3. Ejecutar el método usando el objeto y el puntero
    (printer->*ptr)("Hello world from Method");
    delete printer;
    return 0;
}