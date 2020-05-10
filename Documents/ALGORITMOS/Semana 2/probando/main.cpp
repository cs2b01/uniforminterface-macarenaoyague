#include <iostream>
#include "stack.h"
#include "queue.h"
#include "forward.h"
using namespace std;

int main() {


    ForwardList<int> lista1;
    lista1.push_front(1);
    lista1.push_front(2);
    lista1.push_front(3);
    lista1.push_front(4);
    lista1.push_back(5);

    ForwardList<int> lista2;
    lista1.push_front(1);
    lista1.push_front(2);
    lista1.push_front(3);
    lista1.push_front(4);
    lista1.push_back(5);

    lista1.merge(lista2);

    cout<<lista1[6]<<endl;

    //cout<<lista1.front()<<" "<<lista1.back()<<endl;


    return 0;
}
