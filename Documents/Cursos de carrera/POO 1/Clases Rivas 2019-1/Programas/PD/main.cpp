#include <iostream>
using namespace std;

int contar_superaciones_stack(int* arr, int n){
    int temp=arr[0];
    int contador=0;
    for (int i = 1; i < n; ++i) {
        if (temp<arr[i])
            contador++;
        temp=arr[i];
    }
    return contador;
};

void ej1_stack(){
    int n;
    cin>>n;
    int arr[n];
    int temp;
    for (int i = 0; i < n ; ++i) {
        cin>>temp;
        arr[i]=temp;
    }
    cout<<"Numero de superaciones"<<contar_superaciones_stack(arr, n);
}

void ej1_heap(){
    int n;
    cin>>n;
    int *arr= nullptr;
    arr=new int [n];

    int temp;

    for (int i = 0; i < n ; ++i) {
        cin>>temp;
        arr[i]=temp;
    }

    temp=arr[0];

    int contador=0;
    for (int i = 1; i < n; ++i) {
        if (temp<arr[i])
            contador++;
        temp=arr[i];
    }

    cout<<"Numero de superaciones: "<<contar_superaciones_stack(arr, n);

    delete [] arr;
}

void intercalar_arreglos_stack(int* arr1, int* arr2, int n, int *arr3){
    int contador=0;
    for (int i=0; i<2*n; i++)
    {
        if (i<n)
            arr3[i]=arr2[i];
        else
        {
            arr3[i]=arr1[contador];
            contador++;
        }
    }
}

void ej2_stack(){
    int n;
    cin>>n;
    int temp;
    int arr1[n];
    int arr2[n];
    int arr3[2*n];
    cout<<"Arreglo 1: ";
    for (int i = 0; i < n ; ++i) {
        cin>>temp;
        arr1[i]=temp;
    }
    cout<<"Arreglo 2: ";
    for (int i = 0; i < n ; ++i) {
        cin>>temp;
        arr2[i]=temp;
    }
    intercalar_arreglos_stack(arr1,arr2,n,arr3);
    for (int i = 0; i < 2*n ; ++i)
        cout<<arr3[i]<<endl;
};

int* intercalar_arreglos_heap(int n, int *arr1, int *arr2){
    int *arr3_b= nullptr;
    arr3_b=new int[2*n];
    int contador=0;
    for (int i=0; i<2*n; i++)
    {
        if (i<n)
            arr3_b[i]=arr2[i];
        else
        {
            arr3_b[i]=arr1[contador];
            contador++;
        }
    }
    return arr3_b;
}

void ej2_heap(){
    int n;
    cin>>n;
    int temp;
    int arr1[n];
    int arr2[n];
    cout<<"Arreglo 1: ";
    for (int i = 0; i < n ; ++i) {
        cin>>temp;
        arr1[i]=temp;
    }
    cout<<"Arreglo 2: ";
    for (int i = 0; i < n ; ++i) {
        cin>>temp;
        arr2[i]=temp;
    }
    int *arr3=intercalar_arreglos_heap(n, arr1, arr2);
    for (int i = 0; i < 2*n ; ++i)
        cout<<arr3[i]<<endl;
    delete [] arr3;
};


int main() {
    ej2_heap();

    return 0;
}