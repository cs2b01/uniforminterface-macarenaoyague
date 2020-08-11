//
// Created by Macarena Oyague on 2020-02-13.
//

#ifndef CIFRASENALEMAN_NUMEROSCARDINALES_H
#define CIFRASENALEMAN_NUMEROSCARDINALES_H


class NumerosCardinales{

private:

    vector <string> Z1 = {"ein", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun"};
    vector <string> Z2 = {"zehn", "elf", "zwölf"};
    vector <string> Z3 = {"drei", "vier", "fünf", "sech", "sieb", "acht", "neun"};
    vector <string> Z4 = {"zwan", "vier", "fünf", "sech", "sieb", "acht", "neun"};
    vector <string> Z5 = {"hundert"};
    vector <string> Z6 = {"tausend"};
    vector <string> drei = {"drei"};
    vector <string> zehn = {"zehn"};
    vector <string> zig = {"zig"};
    vector <string> ssig = {"ssig"};
    vector <string> und = {"und"};

public:

    NumerosCardinales() = default;

    const vector<string> &getZ1() const {return Z1;}
    const vector<string> &getZ2() const {return Z2;}
    const vector<string> &getZ3() const {return Z3;}
    const vector<string> &getZ4() const {return Z4;}
    const vector<string> &getZ5() const {return Z5;}
    const vector<string> &getZ6() const {return Z6;}
    const vector<string> &getDrei() const {return drei;}
    const vector<string> &getZehn() const {return zehn;}
    const vector<string> &getZig() const {return zig;}
    const vector<string> &getSsig() const {return ssig;}
    const vector<string> &getUnd() const {return und;}
};






#endif //CIFRASENALEMAN_NUMEROSCARDINALES_H
