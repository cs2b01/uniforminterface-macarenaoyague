#include <iostream>
#include <string>
#include <thread>

using namespace std;

void imprimirPares(int n){
    cout<<"Impresion de los "<<n<<" primeros pares"<<endl;
    for (int i=1 ; i<=n; i++)
        cout<<"\tPar No "<<i<<" --> "<<2*i<<endl;
}

void imprimirImpares(int n){
    cout<<"Impresion de los "<<n<<" primeros impares"<<endl;
    for (int i=1 ; i<=n; i++)
        cout<<"\tImpar No "<<i<<" --> "<<2*i-1<<endl;
}

int main() {
    cout<<"Hola Mundo"<<endl;

    thread* t1 = new thread(imprimirPares,1000);


    thread* t2 = new thread(imprimirImpares,1000);


    cout<<"Chau Mundo"<<endl;

    t1->join();
    t2->join();

    delete t1;
    delete t2;

    return 0;
}