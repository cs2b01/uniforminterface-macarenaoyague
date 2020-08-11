#include <iostream>
#include "process.cpp"
using namespace std;

int main() {
    SynProcess* a=new SynProcess("proceso1");
    a->run();
    AsyncProcess* b=new AsyncProcess("proceso 2", "cliente 1");
    b->run();









    auto queer = new Queue <Process,10>;
    queer->enqueue(a);
    if (queer->isFull()==true)
        cout<<4444;

    return 0;
}