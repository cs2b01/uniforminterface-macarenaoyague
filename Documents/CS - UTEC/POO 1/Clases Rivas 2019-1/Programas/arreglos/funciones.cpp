//
// Created by Macarena Oyague on 2019-05-07.
//

#include "funciones.h"

vector <int> crear_vector (){
    vector <int> vec;
    return vec;
}

int randint(int first, int last){
    srand(time(nullptr));
    int random=first+rand()%(last-first+1);
    return random;
}

vector<int> llenar_vector (int n){
    vector <int> vec= crear_vector();
    for (int i=0;i<=n; i++)
        vec.push_back(randint(1,6));
    return vec;
}

float prom(vector<int> vec, int n){

}