#include <iostream>
using namespace std;

int duplicarPorValor (int num){
    int numeroNuevo = num * 2;
    cout<<numeroNuevo<<endl;
    return numeroNuevo;
}

void duplicarPorReferencia (int &num){
    num = num * 2;
    cout<<num<<endl;
}

int main() {
    /*

    const int FILAS = 3;
    const int COLUMNAS = 5;
    int m [FILAS][COLUMNAS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j ++)
            cout << m [i][j]<<" ";
        cout<<endl;
    }

    */

    /*

    int array [7];

    string dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves",
           "Viernes", "Sabado", "Domingo"};

    for (int i = 0; i < 7; i++)
    {
        cout<<"Canastas del día "<<i + 1<<": ";
        cin>>array[i];
    }

    int maxFor;
    int maxWhile;

    int maxIndiceFor = 0;
    int maxIndiceWhile = 0;

    maxFor = array[0];
    maxWhile = array[0];

    for (int i = 1; i < 7; i++)
        if (array[i] > maxFor)
        {
            maxFor = array[i];
            maxIndiceFor = i;
        }

    int contador = 1;
    while (contador < 7)
    {
        if (array[contador] > maxWhile)
        {
            maxWhile = array[contador];
            maxIndiceWhile = contador;
        }
        contador ++;
    }

    cout<<"El dia con mayor cantidad de canastas es "<<dias[maxIndiceFor]<<endl;
    cout<<"El dia con mayor cantidad de canastas es "<<dias[maxIndiceWhile]<<endl;

     */

    float arr[10] = {11, 19, 10, 8, 5, 15, 16, 13, 13, 14};

    float suma = 0;

    for (int i = 0; i < 10; i++)
       suma += arr[i];

    float promedio = suma / 10;

    cout<<"El promedio es: "<<promedio<<endl;

    int alumnosSobrePromedio = 0;

    for (int i = 0; i < 10; i++)
        if (arr[i] > promedio)
            alumnosSobrePromedio++;

    cout<<"El número de alumnos mayor al promedio es: "<<alumnosSobrePromedio<<endl;

    float min = arr[0];
    float max = arr[0];

    for (int i = 1; i < 10; i++){
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    cout<<"Nota mínima: "<<min<<endl;
    cout<<"Nota máxima: "<<max<<endl;

    int alumnosMenorA15 = 0;

    for (int i = 0; i < 10; i++)
        if (arr[i] < 15)
            alumnosMenorA15++;

    cout<<"Numero de alumnos con nota menor a 15: "<<alumnosMenorA15<<endl;

    return 0;
}


