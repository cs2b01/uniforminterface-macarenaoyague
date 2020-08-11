#include <iostream>
#include "stack.h"
#include "queue.h"
#include "forward.h"
#include "linked.h"
#include "circular.h"
using namespace std;

int main() {

    LinkedList<int> lista1;
    lista1.push_front(100);
    lista1.push_front(20);
    lista1.push_front(1);
    lista1.push_front(90);

    lista1.pop_back();
    cout<<lista1.back();
    lista1.pop_back();
    cout<<lista1.back();
    lista1.pop_back();
    cout<<lista1.back();

    return 0;
}
