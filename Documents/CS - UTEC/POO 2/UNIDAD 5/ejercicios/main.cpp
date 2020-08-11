#include <iostream>
using namespace std;
#include "math.h"
#include <future>
#include <thread>
#include <vector>




long long int fibonacci(int n)
{
    if (n == 0 or n == 1)
        return n;
    return fibonacci(n-2) + fibonacci(n-1);
}

vector<long long int> fillFibonacci(unsigned int n, unsigned int threads){
    unsigned int rango = floor (n/threads) + 1;
    vector<long long int>* v = new vector<long long int>;
    vector<future<long long int>>* results = new vector<future<long long int>>;

    int c = 0;
    while (c<n){
        for (auto i=0; i<threads; i++){

        }
    }
}

int main() {
    std::cout<<fibonacci(0);
    return 0;
}

