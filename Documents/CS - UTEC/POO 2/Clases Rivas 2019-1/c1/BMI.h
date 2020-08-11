//---Function Declarations

#include <iostream>
#include <string>

using namespace std;

#ifndef S1_BMI_H
#define S1_BMI_H


class BMI {
//variables
public:
    //---Default Constructor
    BMI();

    //---Overload Constructor
    BMI(string, int, double);

    //Destructor
    ~BMI();

    //Accessor Functions
    string getname() const;
        //getname - return name

    int getheight() const;
        //getheight-returns height

    double getweight()const;

    //Mutator Functions. they dont return a value
    //we dont use const because we are going to be modifyeng
    //act like overload constructor but modify one variable at a time
    void setname(string);
    //set name - set name of patient
    //@param string - name of patient

    void setheight(int);

    void setweight(double);

    double calculateBMI();
    //calculates BMI of patient
    //@return double-BMI of student



private:
    //---Member variables
    //como son privadas, POR ESO CREAMOS LOS GETS!!
    string newname;
    int newheight;
    double newweight;

};


#endif //S1_BMI_H
