#include <iostream>
using namespace std;
#include <sstream>
#include <vector>
#include "forward.h"

int main() {

    List<int>* lista = new ForwardList<int>();

    lista->push_front(4);
    cout<<lista->front();
    lista->pop_front();
    cout<<"holis";


   /*
    List<int>* lista = new ForwardList<int>();

    lista->push_front(4);
    lista->push_front(5);
    lista->push_front(7);
    lista->push_front(42);
    cout<<lista->front()<<" "<<lista->back()<<endl;

    lista->clear();
    cout<<lista->empty()<<endl;
    cout<<lista->searchNode(0);
    cout<<lista->front()<<" "<<lista->back()<<endl;*/

    return 0;
}