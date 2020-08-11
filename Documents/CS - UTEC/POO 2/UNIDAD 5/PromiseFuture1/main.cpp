#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

std::mutex mtx;

template <class T>
void println(T any){
    mtx.lock();
    cout<<any<<endl;
    mtx.unlock();
}

void producer(int n, promise<string> *prom ){
    println("Child thread is working...");
    for(auto i=1; i<=n; i++){
        println("Child thread is executing instruction "+to_string(i));
        this_thread::sleep_for(chrono::seconds(2));
    }
    println("Producer has sent data");
    prom->set_value("Producer's data");
    println("Producer has finished");
}

int main() {

    println("Main thread is working ");

    // 1. Crear el objeto promise indicando el tipo de dato
    promise<string>* promise1 = new promise<string>();

    // 2. Obtener el objeto future usando el promise
    future<string> future1 = promise1->get_future();

    // 3. Crear el hilo y pasar como parametro el objeto promise
    thread* thread1 = new thread(producer,5,promise1);

    // 4. Esperar por el resultado que entrega el hilo usando future.get()
    auto data = future1.get();

    for (auto i=1; i<=10; i++){
        println("Main thread is executing instruction "+to_string(i));
        this_thread::sleep_for(chrono::seconds(1));
    }

    println("Received Data : "+data);
    thread1->join();
    delete promise1;
    delete thread1;
    println("Main thread has finished");
    return 0;

}