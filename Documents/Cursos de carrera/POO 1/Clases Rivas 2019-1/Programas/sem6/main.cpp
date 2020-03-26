#include <iostream>
using namespace std;

int fib_iterativo (int n){
    int fib=1;
    int fib_menos1=0;
    int fib_menos2=0;
    for (int x=0; x<=n; x++)
    {
        if(x==0){
            fib=x;
        }
        if (x==1){
            fib_menos1=fib;
            fib=fib_menos1+x;
        }
        if (x>=2){
            fib_menos2=fib_menos1;
            fib_menos1=fib;
            fib=fib_menos1+fib_menos2;
        }
    }
    return fib;
}

int fib_recursivo (int n){
    if (n<=1)
        return n;
    else return fib_recursivo(n-1)+fib_recursivo(n-2);
}

int main() {
    cout << fib_iterativo(10)<<endl;
    cout << fib_recursivo(10);
    return 0;
}
