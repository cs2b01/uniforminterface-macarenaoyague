#include <iostream>
using namespace std;

int main() {
    
    int a;
    a=8;
    cout<<"a="<<a<<" , &a="<<&a<<endl;

    int *b;
    b=&a;
    cout<<"b="<<b<<" , &b="<<&b<<" , *b="<<*b<<endl;

    int **c;
    c=&b;
    cout<<"c="<<c<<" , &c="<<&c<<" , *c="<<*c<<" , **c="<<*c<<endl;




    int D [3] = {1,2,3};

    int* E = new int [3];

    int** F = new int* [3];

    E[0] = D[0]; //se está copiando el valor
    E[1] = D[1];
    E[2] = D[2];

    F[0] = &E[0]; //se está copiando la posición
    F[1] = &E[1];
    F[2] = &E[2];

    cout<<F<<" "<<E<<" "<<D<<endl;
    cout<<F[0]<<" "<<E[0]<<" "<<D[0]<<endl;
    cout<<*F[0]<<" "<<E[0]<<" "<<D[0]<<endl;





    int A, B, C;

    cin>>A>>B>>C;

    int *** arrayA = new int** [A];
    fill (arrayA, arrayA + A, nullptr);

    int ** arrayB = new int* [B];
    fill (arrayB, arrayB + B, nullptr);

    int arrayC [C];

    arrayC[0] = 3;
    arrayB[0] = &arrayC[0];
    arrayA[0] = &arrayB[0];

    cout<<arrayA<<" "<<arrayB<<" "<<arrayC<<endl;
    cout<<arrayA[0]<<" "<<arrayB[0]<<" "<<arrayC[0]<<endl;
    cout<<*arrayA[0]<<" "<<*arrayB[0]<<" "<<arrayC[0]<<endl;
    cout<<**arrayA[0]<<" "<<*arrayB[0]<<" "<<arrayC[0]<<endl;

    return 0;
}