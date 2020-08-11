//---Function Definitions

#include "BMI.h"
//esto lee todo lo de h


BMI::BMI() {
    newheight=0;
    newweight=0.0;
}

BMI::BMI(string name, int heigh, double weight){
    newname=name;
    newheight=heigh;
    newweight=weight;
}

BMI::~BMI() {

}

string BMI::getname() const{
    return newname;
}

int BMI::getheight() const{
    return newheight;
}

double BMI::getweight()const{
    return newweight;
}

void BMI::setname(string name) {
    newname=name;
}

void BMI::setheight(int height){
    newheight=height;
}

void BMI::setweight(double weight){
    newweight=weight;
}

double BMI::calculateBMI() {
    return((newweight*703)/(newheight*newweight));
}