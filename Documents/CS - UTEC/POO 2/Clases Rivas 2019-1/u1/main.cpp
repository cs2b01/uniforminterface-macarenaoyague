#include <iostream>
using namespace std;

int main() {
    int* arr=new int [20];
    for (int i=0;i<=19;i++)
    {
        arr[i]=i+1;
    }
    cout<<"Datos en orden inverso"<<endl;
    for (int i=19;i>=0;i--)
    {
        cout<<arr[i]<<endl;
    }

    delete [] arr;

    int* arr2=new int [21];

    for (int i=0;i<=9;i++)
    {
        arr2[i]=arr[i];
    }
    int x;
    cout<<endl<<"Introduce en que posicion quieres que este el 99: ";
    cin>>x;
    arr2[x]=99;
    for (int i=11;i<=20;i++)
    {
        arr2[i]=arr[i-1];
    }
    cout<<endl<<"Nuevo array de numeros "<<endl;
    for (int i=0;i<=20;i++)
    {
        cout<<arr2[i]<<endl;
    }

    delete [] arr2;

    int* arr3=new int [16];
    cout<<endl<<"Introduce en que posicion quieres empezar a borrar los datos ";
    cin>>x;
    for (int i=0;i<=x;i++)
    {
        arr3[i]=arr2[i];
    }
    for (int i=x;i<=16;i++)
    {
        arr3[i]=arr2[i+5];
    }
    cout<<endl<<"Datos del arreglo 3: "<<endl;
    for (int i=15;i>=0;i--)
    {
        cout<<endl<<arr3[i];
    }

    return 0;
}


//arreglo de 20 datos consecutivos del 1 al 20 y que imprima en orden inverso
//el 99 entre el 10 y 11 imprimir en orden
//borrar 5 datos en orden que el usuario escoja