#include <iostream>
#include <string>

#include "BMI.h"

using namespace std;

int main() {
   string name;
   int height;
   double weight;
   cout<<"Enter your name";
   cin>>name;
   cout<<"Enter your height";
   cin>>height;
   cout<<"Enter your weight";
   cin>>weight;
  BMI Student_1(name,height,weight);
      //--- o simplemente rellenarlo con datos y borrar los cin
      //(seria como otro ejer)

    cout<<endl<<"Patient Name "<< Student_1.getname()<<endl<<
    "Height "<<Student_1.getheight()<<endl<<"Weight "<<
    Student_1.getweight()<<endl<<endl;

    cout<<"Enter your name";
    cin>>name;
    cout<<"Enter your height";
    cin>>height;
    cout<<"Enter your weight";
    cin>>weight;

    BMI Student_2;

    Student_2.setname(name);
    Student_2.setheight(height);
    Student_2.setweight(weight);

   cout<<endl<<"Patient Name "<< Student_2.getname()<<endl<<
   "Height "<<Student_2.getheight()<<endl<<"Weight "<<
   Student_2.getweight()<<endl<<"BMI "<<Student_2.calculateBMI();

   cout<<endl<<"Student 1 Name" <<Student_1.getname()<<endl;
   //a pesar de haber usarl el get denuevo, se guardo en el objeto!!

    return 0;
}