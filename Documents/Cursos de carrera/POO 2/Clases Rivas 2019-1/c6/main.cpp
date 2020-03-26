#include <iostream>
using namespace std;

class vect{
   int sz;    //size
   double* elem;    //a pointer to the element
public:
    vect(int s)      //constructor
        :sz{s},         //initialize sz
        elem{new double[s]} {/*...*/}//initialize elem
                //{
                  //  for(int i=0;i<s;++i)elem[i]=0;  //initialize elements
                //}
    ~vect() { delete[] elem; }      //destructor//free memory

    int size() const { return sz;}      //the current size

    double get(int n) const {return elem[n];}   //access: read
    void set(int n, double v) { elem[n]=v; }    //access: write
};

int main() {
    vect v(5);
    for (int i=0;  i<v.size(); ++i) {
        v.set(i,1.1*i);
        cout << "v[" << i << "]==" << v.get(i) << '\n'; }
    return 0;
}

//Pointers to class objects

vect* f(int s) {
    vect* p = new vect(s); // fill *p
    return p;
// allocate a vector on free store
}


void ff() {
    vect* q = f(4); // use *q
    delete q;
// free vector on free store
}