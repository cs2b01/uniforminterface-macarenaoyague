#include <iostream>
#include <math.h>
using namespace std;

#include <string>

void ejercicio1(){
    double x;
    cout<<"Ingresar x: ";
    cin>>x;
    double estimado=x/2;
    double raiz=sqrt(x);
    while (estimado!=raiz){
        estimado=(estimado+x/estimado)/2;
    }
    cout<<estimado<<endl;
}

void ejercicio2 (){
        int bit_total=0;
        int bit;
        int contador_de_1=0;
        for (int x=0;x<8;x++)
        {
            do {
                cout << "Ingrese 0 o 1: ";
                cin >> bit;
            } while (bit!=0&&bit!=1);
            bit_total=bit_total*10+bit;
        }
        for (int x=1;x<9;x++)
        {
            bit=bit_total%10;
            bit_total=bit_total/10;
            if(bit==1)
                contador_de_1++;
        }
        if ((contador_de_1+1)/2>contador_de_1/2)
        cout<<"Es paridad impar "<<endl;
        else cout<<"Es paridad par "<<endl;
};

void ejercicio3(){
    string mensaje;
    cout<<"Cifrar el mensaje: ";
    getline (cin, mensaje);
    for (int x=0; x<mensaje.size();x++){
        if ((97<=mensaje[x]&&mensaje[x]<120) || (65<=mensaje[x]&&mensaje[x]<88))
            mensaje[x]+=3;
        switch(mensaje[x])
        {
            case 'x':
                mensaje[x]='a';
            case 'y':
                mensaje[x]='b';
            case 'z':
                mensaje[x]='c';
            case 'X':
                mensaje[x]='A';
            case 'Y':
                mensaje[x]='B';
            case 'Z':
                mensaje[x]='C';
                break;
        }
    }
    cout<<mensaje;
}

void ejercicio3_2(){
    string mensaje;
    int n;
    cout<<"Inserte el mensaje: ";
    getline(cin, mensaje);
    cout<<"Inserte el numero de espacios a desplazar: ";
    cin>>n;
    for (int x=0; x<mensaje.size();x++)
    {
        if (97<=mensaje[x]&&mensaje[x]<120){
            if ((mensaje[x]+n)<=120)
                mensaje[x]+=n;
            else
                mensaje[x]+=n-23;
        }
        if (65<=mensaje[x]&&mensaje[x]<88){
            if ((mensaje[x]+n)<=88)
                mensaje[x]+=n;
            else
                mensaje[x]+=n-23;
        }
    }
    cout<<mensaje;
}

int main() {
    ejercicio3_2();
    return 0;
}