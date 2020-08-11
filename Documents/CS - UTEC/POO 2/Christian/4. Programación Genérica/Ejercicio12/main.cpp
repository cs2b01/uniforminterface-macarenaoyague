#include <iostream>
#include <string>
using namespace std;

// Plantilla de Clase
// Se parametriza el tipo de dato a usar
// en los atributos, metodos y variables locales

template <class T>
class Pair{
private:
    T first;
    T second;
public:
    Pair(T first, T second): first(first), second(second){}
    T getMax(){
        return first>second ? first : second;

    }
    T getMin(){
        return first<second ? first : second;
    }
    T getFirst() const{
        return first;
    }

    T getSecond() const {
        return second;
    }

    void showPair(){
        cout<<"Pair ("<<first<<","<<second<<")"<<endl;
        cout<<"- Max value "<<getMax()<<endl;
        cout<<"- Min value "<<getMin()<<endl;
    }
};

int main() {
    Pair<int>* intPair = new Pair<int>(10,20);
    Pair<string>* stringPair = new Pair<string>("abc","xyz");
    Pair<double>* doublePair = new Pair<double >(454.55,657.33);

    intPair->showPair();
    stringPair->showPair();
    doublePair->showPair();

    delete intPair;
    delete stringPair;
    delete doublePair;
    return 0;
}