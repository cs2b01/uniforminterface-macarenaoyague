#include <iostream>
#include <string>
#include <functional>
using namespace std;

int main() {
    // Declaracion de la expresion Lambda
    //auto power = [](float base, float exponente){return pow(base,exponente);};
    function<float (float,float)> power = [](float base, float exponente){
        return pow(base,exponente);
    };

    // Uso de la expresion Lambda
    cout<< power(2,3)<<endl;
    cout<< power(3,3)<<endl;
    return 0;
}