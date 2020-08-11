//
// Created by Macarena Oyague on 2019-11-09.
//

#ifndef PC3_ELEMENT_H
#define PC3_ELEMENT_H


#include <string>
using namespace std;
#include <vector>
#include <sstream>

class Element {
private:
    string location;
    int year;
    long long int comm_code;
    string commodity;
    string flow;
    long long int trade_usd;
    long long int quantity;
    string category;
public:
    const string &getLocation() const {
        return location;
    }

    int getYear() const {
        return year;
    }

    long long int getComm_code() const {
        return comm_code;
    }

    const string &getCommodity() const {
        return commodity;
    }

    const string &getFlow() const {
        return flow;
    }

    long long int getTrade_usd() const {
        return trade_usd;
    }

    long long int getQuantity() const {
        return quantity;
    }

    const string &getCategory() const {
        return category;
    }

    Element(const string &location, int year, long long int comm_code, const string &commodity, const string &flow,
            long long int trade_usd, long long int quantity, const string &category) : location(location), year(year),
                                                                                       comm_code(comm_code),
                                                                                       commodity(commodity), flow(flow),
                                                                                       trade_usd(trade_usd),
                                                                                       quantity(quantity),
                                                                                       category(category) {}
};


// S    E   P  A R    A   D  O R        FALTA
Element* deserializer (string cadena){
    vector <string> campos;
    stringstream stream(cadena);
    string campo;
    while(getline(stream,campo,',')){
        if (campo == "")
            campos.push_back("0");
        else
            campos.push_back(campo);
    }
        return new Element(campos[0],stoll(campos[1]),stoll(campos[2]),campos[3],campos[4],
                stoll(campos[5]),stoll(campos[6]),campos[7]);
    }




#endif //PC3_ELEMENT_H
