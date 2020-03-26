// Ejercicio02
// Busca la palabra mas usada en el archivo biblia.txt

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int totalCaracteres=0, totalPalabras=0, totalLineas=0;
    char c;
    string palabra;
    int i=0;

    fstream fin("biblia.txt", ios::in) ;

    //Cuenta los caracteres
    while (fin>>c)
        ++totalCaracteres;

    fin.close();
    fin.open("biblia.txt", ios::in) ;
    //Cuenta las palabras
    while (fin>>palabra)
        ++totalPalabras;

    fin.close();
    fin.open("biblia.txt", ios::in) ;
    // Cuenta las filas
    while (getline(fin, palabra))
        ++totalLineas;

    cout<<"Caracteres = "<<totalCaracteres<<endl;
    cout<<"Palabras   = "<<totalPalabras<<endl;
    cout<<"Lineas     = "<<totalLineas<<endl;

    return 0;
}