#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Sum{
private:
    vector<T>* sumandos;
public:
    Sum(){
        sumandos = new vector<T>();
    }
    T operator()(){
        T sumatoria = 0;
        for(T sumando : *sumandos)
            sumatoria+=sumando;
        return sumatoria;
    }

    Sum* push(T sumando){
        sumandos->push_back(sumando);
        return this;
    }
    ~Sum(){
        sumandos->clear();
        delete sumandos;
    }

};

int main() {
    // Declaramos el objeto Sum
    Sum<int>* sum = (new Sum<int>())->push(10)->push(12)->push(13);
    // Ejecutamos el functor
    cout<< (*sum)()<< endl;

    return 0;
}