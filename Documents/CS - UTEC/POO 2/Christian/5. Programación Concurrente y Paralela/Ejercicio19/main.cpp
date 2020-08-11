#include <iostream>
#include <string>
#include <future>

using namespace std;

unsigned int fibo(unsigned int n){
    if (n <= 1)
        return n;
    else {
        unsigned int n_2 = 0, n_1 = 1, fib = 0;
        for (int i=1; i<n; i++){
            fib = n_2 + n_1;
            n_2 = n_1;
            n_1 = fib;
        }
        return fib;
    }
}



void fibo2(unsigned int n, promise<unsigned int>* prom ){
    if (n <= 1)
        prom->set_value(n);
    else {
        unsigned int n_2 = 0, n_1 = 1, fib = 0;
        for (unsigned int i=1; i<n; i++){
            fib = n_2 + n_1;
            n_2 = n_1;
            n_1 = fib;
        }
        prom->set_value(fib);
    }
}

int main() {
    // Recuperar valores de un thread

    // Primera manera: promise & future
    // Se debe acondicionar la funcion para trabajar con promise
    promise<unsigned int>* prom = new promise<unsigned int>();
    future<unsigned int> fut = prom->get_future();
    thread* t1 = new thread(fibo2,10,prom);
    cout<< fut.get()<<endl;
    delete t1;

    //Segunda manera: async & future
    // se usa la funcion tal cual
    future<unsigned  int> result = async(fibo,10);
    cout<< result.get()<<endl;
    return 0;
}