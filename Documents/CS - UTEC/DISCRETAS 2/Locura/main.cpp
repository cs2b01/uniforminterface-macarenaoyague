#include <iostream>
#include <utility>
#include <map>
using namespace std;

class Cubo{
private:
    string lados [6];
    pair <string, string>* pairs[3];
    void findPairs(){
        pairs[0] = new pair <string, string> (lados[0], lados[3]);
        pairs[1] = new pair <string, string> (lados[1], lados[4]);
        pairs[2] = new pair <string, string> (lados[2], lados[5]);
    }
public:
    Cubo(string& lado1, string& lado2, string& lado3, string& lado4, string& lado5, string& lado6){
        lados[0] = lado1;
        lados[1] = lado2;
        lados[2] = lado3;
        lados[3] = lado4;
        lados[4] = lado5;
        lados[5] = lado6;
        findPairs();
    }

    pair<string, string> *const *getPairs() const {
        return pairs;
    }
};

class Fila{
public:
    Cubo orden [4];
};

class Juego{
private:
    Cubo *cubo1;
    Cubo *cubo2;
    Cubo *cubo3;
    Cubo *cubo4;

    pair<string,string> caritas1[4];
    pair<string,string> caritas2[4];


public:
    Juego(Cubo *cubo1, Cubo *cubo2, Cubo *cubo3, Cubo *cubo4) : cubo1(cubo1), cubo2(cubo2), cubo3(cubo3),
                                                                cubo4(cubo4) {}
    void jugar(){

        auto pairsDeUno = cubo1->getPairs();
        auto pairsDeDos = cubo2->getPairs();
        auto pairsDeTres = cubo3->getPairs();
        auto pairsDeCuatro= cubo4->getPairs();

        for (int i = 0; i < 3; i++){
            for (int k = 0; i < 3; k++){
                for (int q = 0; i < 3; q++){
                    for (int p = 0; i < 3; p++){
                        if(pairsDeUno[i]->first != pairsDeDos[k]->first){
                            if(pairsDeUno[i]->first != pairsDeTres[q]->first){
                                if(pairsDeUno[i]->first != pairsDeCuatro[p]->first){
                                    if(pairsDeDos[k]->first != pairsDeTres[q]->first){
                                        if(pairsDeDos[k]->first != pairsDeCuatro[p]->first){
                                            if(pairsDeTres[q]->first != pairsDeCuatro[p]->first){
                                                caritas1[0] = *pairsDeUno[i];
                                                caritas1[1] = *pairsDeDos[k];
                                                caritas1[2] = *pairsDeTres[q];
                                                caritas1[3] = *pairsDeCuatro[p];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};


int main() {

    return 0;
}