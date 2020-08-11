#include <iostream>
#include <map>
#include <sstream>
using namespace std;


class X{

};

class Y{
    Y *subclase;
    int data;
};


class holaClass{
public:
    int data;
    holaClass *head;
    holaClass(int data) : data(data) {}

};

int main() {

    holaClass *claseA = new holaClass(6);

    holaClass *claseB = new holaClass(8);
    claseB->head = claseA;


    holaClass *claseC;
    claseC = claseA;

    holaClass **claseDobleP = &claseB;

    //*claseDobleP = claseB;

    //cout<<(*claseDobleP)->data<<"    "<<claseA->data<<"    ";
    //if((*claseDobleP)->data != claseB->data) std::cout<<"holas "<<endl;

    //claseDobleP = &(*claseDobleP)->head;
    //cout<<(*claseDobleP)->data;

    claseB = nullptr;
    //if (*claseDobleP == nullptr) cout<<"ALEGRIA";

    //(*claseDobleP)->data = 100;
   //std::cout<<(*claseDobleP)->data<<" "<<claseB->data<<" "<<claseC->data;

    map<string, int> table; ///vector of pairs


    string cell ="=22+2+1";



    cell = cell.substr (1,cell.size());

    cout<<cell<<"   ";

    stringstream X(cell);
    int count = 0;

    while (true);
    {
        getline(X, cell, '+');
        cout<<cell;
        count++;
    }

    //AAA AZ ZA A AA


    return 0;
}
