#include <iostream>
#include <string>
#include <vector>
#include <future>
#include <thread>

using namespace std;

long long int fibonacci(unsigned int n){
    if (n == 0 || n == 1)
        return n;
    long long int n1 = 0;
    long long int n2 = 1;
    long long int r = 0;
    for (auto i = 2; i<=n; i++ ){
        r = n1 + n2;
        n1 = n2;
        n2 = r;
    }
    return r;

}

vector<long long int>* fillFibonacci(unsigned int n, unsigned int threads){
    vector<long long int>* v = new vector<long long int>();
    unsigned int c = 0;
    while (c<=n){
        vector<future<long long int>>* results = new vector<future<long long int>>();
        for (auto i=0; i<threads && c<=n; i++){
            results->push_back(async(fibonacci,c));
            c++;
        }
        for (auto i=0 ; i<results->size(); i++){
            auto fib = (*results)[i].get();
            v->push_back(fib);
        }
        delete results;
    }
    return v;
}

int main() {
    auto* v = fillFibonacci(50,4);
    for (long long int f : *v)
        cout<<f<<endl;
    delete v;

    return 0;
}