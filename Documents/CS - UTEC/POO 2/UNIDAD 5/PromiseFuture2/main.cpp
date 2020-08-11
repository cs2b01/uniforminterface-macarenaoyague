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

void producer(promise<string>* prom){
    println("Producer has started");
    for(auto i=1; i<=5; i++){
        println("Producer is working "+ to_string(i));
        this_thread::sleep_for(chrono::seconds(1));
    }
    prom->set_value("Data");
    println("Producer has sent data");
    for(auto i=1; i<=5; i++){
        println("Producer continues working "+ to_string(i));
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    println("Producer has finished");
}

void consumer(future<string> fut){
    println("Consumer has started...");
    for(auto i=1; i<=10; i++){
        println("Consumer is working " + to_string(i));
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    println("Consumer is waiting for Producer's data");
    auto data = fut.get();
    println("Consumer has received: "+ data);
    for(auto i=1; i<=5; i++){
        println("Consumer continues working " + to_string(i));
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    println("Consumer has finished");
}



int main() {
    println("Main process has started...");

    // 1. Crear promise
    promise<string>* promise1 = new promise<string>();
    // 2. Obtener future a partie de promise
    future<string> future1 = promise1->get_future();

    // 3. Crear los procesos en hilos separados y enviar como parametros
    //    los puntos de comunicacion:
    //    promise para el productor (quien entrega el dato)
    //    futuere para el consumidor (quien recibe el dato)

    println("Main process is creating producer and consumer");
    thread* productor = new thread(producer,promise1);
    thread* consumidor = new thread(consumer,move(future1));
    //move CAMBIA la dirección de un objeto o elemento o algo con variable a la dirección a la que se le asigna el thread

    productor->join();
    consumidor->join();
    delete promise1;
    delete productor;
    delete consumidor;

    println("Main process has finished");

    return 0;
}