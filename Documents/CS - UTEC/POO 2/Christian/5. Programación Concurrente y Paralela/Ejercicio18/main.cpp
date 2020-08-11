#include <thread>
#include <future>
#include <iostream>
#include <string>
using namespace std;

void producer(promise<string>* prom) {
    cout<<"Producer is working... "<<endl;
    this_thread::sleep_for(chrono::seconds(5));
    prom->set_value("Data from Producer\n");
}

void consumer(future<string> fut) {
    cout<<"Consumer is working... "<<endl;
    cout<<"Waiting for data "<<endl;
    cout << fut.get()<<endl;
}

int main()
{
    promise<string>* prom = new promise<string>();
    future<string> fut = prom->get_future();
    std::thread* t1 = new thread(producer, prom);
    std::thread* t2= new thread(consumer, move(fut));

    t1->join();
    t2->join();
    delete t1;
    delete t2;
    return 0;
}

