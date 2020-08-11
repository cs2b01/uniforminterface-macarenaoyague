#include <thread>
#include <future>
#include <iostream>
#include <string>
using namespace std;

void worker(int n, promise<string> *prom) {
    cout<<"Child thread "<<this_thread::get_id()<<" working... "<<endl;
    for (int i = 1; i<=n; i++ ){
        cout<<"Instruction "<<i<<"..."<<endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
    prom->set_value("Resultado enviado desde Worker\n");
}

int main()
{
    cout<<"Main thread "<<this_thread::get_id()<<" working... "<<endl;

    promise<string>* prom = new promise<string>();
    future<string> fut = prom->get_future();
    thread* t2 = new thread(worker, 10, prom);


    for (int i = 1; i<=5; i++ ){
        cout<<"Main Instruction "<<i<<"..."<<endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
    cout<< fut.get() << std::endl;
    t2->join();
    delete t2;
    delete prom;
    return 0;
}
