#include <iostream>
#include <string>
using namespace std;

template <class R, class P>
R funcion(P arg){
    R result;
    // Logica para usar arg P
    // obtener R

    return result;
}

template <class A>
class MiClase{
private:
    A atributo;
public:
    MiClase(A atributo) : atributo(atributo) {}

    A getAtributo() const {
        return atributo;
    }
};

template <class T1, class T2>
class MiSegundaClase{
private:
    T1 atributo;
public:
    MiSegundaClase(T1 atributo) : atributo(atributo) {}
    T2 miMetodo(){
      T2 result;
      // Logica para obtener result
      return result;
    }
};

// T -- Type - Tipo de dato del array
// S -- Size - Tipo de dato del tamaño del array
template <class T, class S>
class MiArray{
private:
    T* items;
public:
    MiArray(S size = 10){
        items = new T[size];
    }
    ~MiArray(){
        for(auto item : items)
            delete item;
        delete[] items;
    }
};

template < class A, class B>
class ClaseCompuesta{

private:
    A atributoA;
    B atributoB;
public:
    ClaseCompuesta(A a, B b){
        this->atributoA = a;
        this->atributoB = b;
    }
};




int main() {
    string result = funcion<string,int>(10);
    MiClase<double> * objeto = new MiClase<double>(34.5);
    objeto->getAtributo();

    MiArray<string, unsigned char>* miArray = new MiArray<string, unsigned char>();
    MiArray<string, long>* miArray2 = new MiArray<string, long>(65565);

    auto * obj = new ClaseCompuesta<int, MiArray<string,int>* >(2, new MiArray<string,int>(100));


    return 0;
}