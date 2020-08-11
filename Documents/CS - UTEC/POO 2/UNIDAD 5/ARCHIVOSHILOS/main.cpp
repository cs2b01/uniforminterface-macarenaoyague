#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <string>
#include <fstream>

using namespace std;

std::mutex mtx;
template <class T>
void println(T any){
    mtx.lock();
    cout<<any<<endl;
    mtx.unlock();
}

void producer(promise<string>* prom){
    string name = "archivo.txt";
    fstream *archivoIN = new fstream(name, ios_base::out);
    *archivoIN<<"hola";
    prom->set_value(name);
}

void consumer(future<string> fut){
    auto data = fut.get();
    fstream *archivoIN = new fstream(data, ios_base::out);
}



int main() {

    promise<string>* promise1 = new promise<string>();
    future<string> future1 = promise1->get_future();

    thread* productor = new thread(producer,promise1);
    thread* consumidor = new thread(consumer,move(future1));

    productor->join();
    consumidor->join();

    delete promise1;
    delete productor;
    delete consumidor;

    return 0;
}