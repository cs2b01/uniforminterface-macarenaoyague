#include <iostream>
using namespace std;

int main() {
    string h ="9";
    string hola;
    hola.push_back(char(h[1] +1));
    hola.push_back(h[2]);

    cout<<h[0]-1;
    return 0;
}