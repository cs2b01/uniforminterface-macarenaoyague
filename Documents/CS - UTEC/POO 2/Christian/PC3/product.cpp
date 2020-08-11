//
// Created by estanislao.contreras on 6/8/2019.
//
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Product{
private:
    string brand;
    string code;
    string name;
    string category;
    double price;
public:

    Product(const string &code,const string &brand, const string &name, const string &category, double price) : brand(
            brand), code(code), name(name), category(category), price(price) {}

    Product(string line){
        string elements[5];
        string str = line;
        stringstream ss(str);
        string token;
        for (int i = 0; getline(ss,token, ';'); ++i) {
            elements[i]=token;
        }
        code = elements[0];
        brand = elements[1];
        name = elements[2];
        category = elements[3];
        price = stod(elements[4]);
    }

    const string &getCode() const {
        return code;
    }

    void setCode(const string &code) {
        Product::code = code;
    }

    const string &getBrand() const {
        return brand;
    }

    void setBrand(const string &brand) {
        Product::brand = brand;
    }


    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Product::name = name;
    }

    const string &getCategory() const {
        return category;
    }

    void setCategory(const string &category) {
        Product::category = category;
    }


    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Product::price = price;
    }

    string toLine(){
        return code+";"+brand+";"+name+";"+category+";"+to_string(price)+"\n";
    }

};
