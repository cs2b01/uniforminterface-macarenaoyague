#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <random>
#include <future>
using namespace std;


unsigned int suma(vector <unsigned int>* v1, vector<unsigned int>::iterator inicio, vector<unsigned int>::iterator fin){
    int sum;
    while (inicio != fin){
        sum += *inicio;
        inicio++;
    }
    return sum;
}

unsigned int sumando(vector <unsigned int>* v1, unsigned int threads){
    unsigned int contador = 0;
    unsigned int iterando = 0;

    if ((threads*2)/2 == threads)
        iterando = v1->size()/threads;
    else
        iterando = v1->size()/threads + 1;

    vector <future<unsigned int>> * sumandoThreads = new vector<future<unsigned int>>;

    for (int i = 1; i<=threads; i++)
    {
        sumandoThreads->push_back(async(suma, v1, v1->begin()+contador, v1->begin()+iterando));
        contador = iterando;
        iterando += iterando;
    }

    unsigned int suma;
    for (int i = 0; i<sumandoThreads->size(); i++)
        suma += (sumandoThreads->at(i)).get();
    return suma;
}

void fillRandomNumbers(vector<unsigned int>*v){
    const unsigned int MAX = 100000;
    for (int i=0; i<MAX; i++)
        v->push_back(rand()%1000);
}

int main() {

    srand(time(0));


    auto v = new std::vector <unsigned int>;

    fillRandomNumbers(v);

    int sum = 0;

    future<unsigned int> result1 = async(suma, v, v->begin(), v->begin()+v->size()/2);

    future<unsigned int> result2 = async(suma, v, v->begin()+v->size()/2, v->end());

    auto s1 = result1.get();
    auto s2 =result2.get();

    cout<<s1+s2;

    unsigned int suma = sumando(v, 4);
    return 0;
}