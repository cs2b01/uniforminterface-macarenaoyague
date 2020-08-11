#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <future>

using namespace std;
/*
template<class T>
T sum(T* array, unsigned int from, unsigned int to){
    T result = T();
    for(unsigned int i=from; i<=to; i++)
        result+=array[i];
    return result;
}*/


unsigned int sum(unsigned int* array, unsigned int from, unsigned int to){
    unsigned int result = 0;
    for(unsigned int i=from; i<=to; i++)
        result+=array[i];
    return result;
}


int main() {
    const int MAX = 100000;

    srand(time(0));
    unsigned int* array = new unsigned int[MAX];
    for (int i=0; i<MAX;i++ )
        array[i] = rand()%1000;

    // Using time point and system_clock
    chrono::time_point<chrono::system_clock> start, end;

    cout<<"Sin Hilos"<<endl;
    start = chrono::system_clock::now();
    cout << "sum (array,0,MAX)= " << sum(array,0,MAX) << '\n';
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << "s\n\n\n";

    cout<<" Con Hilos "<<endl;
    start = chrono::system_clock::now();

    future<unsigned int> s1 = async(sum,array,0,49999);
    future<unsigned int> s2 = async(sum,array,50000,100000);
    cout << "sum async = " << s1.get() + s2.get() << '\n';
    end = chrono::system_clock::now();
    elapsed_seconds = end - start;
    end_time = std::chrono::system_clock::to_time_t(end);
    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}