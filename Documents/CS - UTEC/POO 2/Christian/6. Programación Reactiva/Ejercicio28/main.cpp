#include <iostream>
#include <string>
#include <functional>
using namespace std;

template <class T>
T find(T* array, function<bool (T)> criteria){
    for ( ; array!= nullptr ; array++) {
        if (criteria(*array))
            return *array;
    }
    return T();
}



int main() {
    int numeros[] = {11,23,25,20,-2,22,27};
    cout<<find<int>(numeros,[](int n){return n%2==0;})<<endl;
    cout<<find<int>(numeros,[](int n){return n%2!=0;})<<endl;
    cout<<find<int>(numeros,[](int n){return n<0;})<<endl;
    return 0;
}