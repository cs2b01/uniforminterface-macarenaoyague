#include <iostream>
#include <vector>
using namespace std;


int main() {
                    vector <double> age (4);
                    age[0]=0.33;
                    age[1]=22.0;
                    age[2]=27.2;
                    age[3]=54.2;
                    //o no poner el tamaño y usar age.push_back(value)
    return 0;
}


//pointer: object that holds an address value
//int* ptr=&var guarda la direccion de esa variable
//*ptr to know the value the object is pointing we use that (por ejemplo hacemos un cout para revelarlo)

//double* p = new double[4]; // allocate 4 doubles on the free store
//double x = *p; // read the (first) object pointed to by p
//                  p[0] means exactly the same as *p
//double y = p[2]; // read the 3rd object pointed to by p
//p[2] = 9.9;// write to the 3rd object pointed to by p
//double x = *p; // read the object pointed to by p
//                  el objeto que se esta creando se guardara en la direc
//                  ejemplo: double x = p[3];p[3] = 4.4;
//                  otro ejemplo: double* p2 = new double{5.5}; no le da nombre a variable solo le da ese inicio, but its the same
//*p = 8.8; // write to the object pointed to by p

//A pointer really doesn’t know how many objects it points to
//it only points the first one

//double* p0; *p0 = 7.0;
// This will assign 7.0 to some location in memory. We have no idea which part of memory that will be.
//OUT OF RANGE!!!!....but works... “My program crashed mysteriously”
//we need to initialize it with double* p0=new double;
//The new operator allocates (“gets”) memory from the free store.

//double* p4 = new double[5] {0,1,2,3,4};
//double* p5 = new double[] {0,1,2,3,4};
//the number of elements can be left out when a set of elements is provided.

//delete nombredelpuntero; frees the memory for an individual object allocated by new.
//delete[ ] nombredelpuntero; frees the memory for an array of objects allocated by new.
//   liberar el espacio almacenado en el heap luego de usar el puntero

//int* p = nullptr; es estupido crearlo hasta no saber a que apuntar
//pero igual si pones delete y el puntero, normal porque no apunta a nada, no borras nada tmp



//The major problem with pointers is that a pointer doesn’t “know” how many elements it points to.
//Given vector, there is no reason to allocate memory using new just to deallocate it using delete[ ] at the end of a function.

//example:
//  double* pd = new double[3]; pd[2] = 2.2;
//  pd[4] = 4.4;
//  pd[–3] = –3.3;
//OUT OF RANGE!!.... but works...wrong
//It will even access pd[–3] as if the location three doubles before what pd points to was part of our allocation


////vector es una clase y se pone entre los parentesis el tamaño,
////usamos una libreria que ya tiene la clase hecha
//nombredelvector.size() tamaño del vector

//reinterpret_cast ?¿ convert an int to a pointer or to convert one pointer type to another
//sizeof(variable/typename) el tamaño que esta ocupando en memoria -number of bytes-