#include <iostream>
#include <map>
#include <future>
#include <vector>
#include <math.h>
#include <thread>

using namespace std;

long long int sumaDivisores(long long int num){
    long long int suma = 0;
    for (int i = 1; i<num; i++)
        if (num%i == 0)
            suma+=i;
    return suma;
}

/*map<long long int, long long int>* paralelMap(long int from, long int to){
    auto *paralelMap = new map<long long int , long long int>();
    for(long long int i = from; i<to; i++)
        (*paralelMap)[i] = sumaDivisores(i);
    return paralelMap;
}*/

map<long long int , long long int>* findMapDivisores(long long int max){

    auto *mapa = new map<long long int , long long int>();

    int numberThreads = thread::hardware_concurrency();

    long long int cont = 2;
    long long int cont2 = 2;

    while (cont<=max){

        vector<future<long long int>>* hilos = new vector<future<long long int>>();
        vector <long long int> conts;

        for (auto i=0; i<numberThreads && cont<=max; i++){
            hilos->push_back(async(sumaDivisores,cont));
            cont++;
        }

        for (auto i=0 ; i<hilos->size(); i++){
            auto sumaDivisores = (*hilos)[i].get();
            (*mapa)[cont2] = sumaDivisores;
            cont2++;
        }
        hilos->clear();
        delete hilos;
    }

    return mapa;
}

map<long long int , long long int>* findMapFriends(map<long long int , long long int>* mapDivisores){

    auto mapFriends = new map<long long int , long long int>;

    for(auto it = mapDivisores->begin(); it!=mapDivisores->end(); it++)
        for(auto it2 = mapDivisores->begin(); it2!=mapDivisores->end(); it2++)
        {
            if (it->first != it->second)
                if(it->first == it2->second and it->second == it2->first)
                    if(mapFriends->find(it->first) == mapFriends->end() and
                    mapFriends->find(it->second) == mapFriends->end())
                        (*mapFriends)[it->first] = it2->first;
        }

    return mapFriends;
}

void print(map<long long int, long long int>* mapFriends){
    for(auto it = mapFriends->begin(); it!=mapFriends->end(); it++)
        cout <<it->first<<","<<it->second<<endl;
}

int main() {
    auto mapDivisores = findMapDivisores(10000);
    auto mapFriends = findMapFriends(mapDivisores);
    print(mapFriends);
    return 0;
}