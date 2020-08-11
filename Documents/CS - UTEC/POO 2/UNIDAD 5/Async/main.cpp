#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <future>
#include <math.h>
#include <mutex>

using namespace std;

const unsigned  int MAX = 100000;

// Mutex para la region critica
std::mutex mtx;

template <class T>
void print(T any){
    mtx.lock();
    cout<<any;
    mtx.unlock();
}


using namespace std;

unsigned int sum(vector<unsigned int>* v, unsigned int from, unsigned int to){
    print("Child thread ");
    print(this_thread::get_id());
    print(" working...\n");
    unsigned int result = 0;
    for(auto i = from; i<to; i++)
        if (i<v->size())
            result+=(*v)[i];
    print("Child thread ");
    print(this_thread::get_id());
    print(" finished...\n");

    return result;
}



unsigned int sum_with_threads(vector<unsigned int>* v, unsigned int threads){

    unsigned int range = floor(v->size()/threads)+1;

    vector<future<unsigned int>>* results = new vector<future<unsigned int>>();

    for(auto i =0; i<threads; i++){
        results->push_back(async(sum,v,i*range,(i+1)*range));
    }

    unsigned int result = 0;

    for(auto i =0; i<threads; i++){
        result = result + (*results)[i].get();
    }

    return result;
}


void fillRandomNumbers(vector<unsigned int>* v){
    for (auto i=0; i<MAX; i++)
        v->push_back(rand()%1000);

}

int main() {

    cout<<"Main thread "<<this_thread::get_id()<<" working..."<<endl;

    srand(time(0));

    vector<unsigned int>* v = new vector<unsigned int>();

    fillRandomNumbers(v);


    future<unsigned int> result1 = async(sum, v, 0, MAX/2);

    future<unsigned int> result2 = async(sum, v, MAX/2, v->size());

    auto s1 = result1.get();
    auto s2 =result2.get();

    cout<<"sum: "<<s1+s2<<endl;


    unsigned int r = sum_with_threads(v,3);
    cout<< "Suma "<<r<<endl;

    cout<<"Main thread "<<this_thread::get_id()<<" finished "<<endl;
    return 0;
}