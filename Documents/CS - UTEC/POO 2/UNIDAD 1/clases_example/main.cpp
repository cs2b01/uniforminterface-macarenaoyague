#include <iostream>
using namespace std;
#include <string.h>
#include "OLA.h"

int main() {
    OLA yo (12);
    OLA el= OLA (14);
    el.setName("Bruno");
    OLA ella("Monica");
    cout<<yo.getEdad()<<endl;
    cout<<ella.getName();
    return 0;
}