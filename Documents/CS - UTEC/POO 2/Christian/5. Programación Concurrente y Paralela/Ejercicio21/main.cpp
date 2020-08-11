#include <iostream>
#include <string>
#include <thread>
#include <mutex>          // std::mutex

using namespace std;
std::mutex mtx; // mutex for critical sect

template <class T>

void imprimir(T algo){
    /* 1 Forma : Usando block y unblock
    mtx.lock();
    cout<<algo<<endl;
    mtx.unlock();
     */

    /* 1 forma: Usando lock_guard

    lock_guard<mutex> lck (mtx);
    cout<<algo<<endl;
}

void imprimirPares(int n){
    imprimir("Impresion de los "+to_string(n)+" primeros pares");
    for (int i=1 ; i<=n; i++)
        imprimir("\tPar No "+to_string(i)+" --> "+to_string(2*i));
}

void imprimirImpares(int n){
    imprimir("Impresion de los "+to_string(n)+" primeros impares");
    for (int i=1 ; i<=n; i++)
        imprimir("\tImpar No "+to_string(i)+" --> "+to_string(2*i-1));
}

int main() {
    imprimir("Hola Mundo");
    thread* t1 = new thread(imprimirPares,10);
    thread* t2 = new thread(imprimirImpares,10);
    t2->join();
    t1->join();

    imprimir("Chau Mundo");
    delete t1;
    delete t2;

    return 0;
}