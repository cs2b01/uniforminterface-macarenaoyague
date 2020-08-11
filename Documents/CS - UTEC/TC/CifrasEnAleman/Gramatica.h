//
// Created by Macarena Oyague on 2020-02-09.
//

#ifndef CIFRASENALEMAN_GRAMATICA_H
#define CIFRASENALEMAN_GRAMATICA_H
#endif //CIFRASENALEMAN_GRAMATICA_H

#include "NumerosCardinales.h"

class Scanner{
private:

    NumerosCardinales lenguaje;
    vector <string> vectorNumero;
    string palabraOriginal;
    string palabraComparada;
    string temp;
    string saveScan;

    void cutPalabraOriginal (int cont){
            int size = palabraOriginal.size();
            string temp;
            if (size!=cont){
                temp="";
                for (int i=cont; i<cont+7; i++)
                    temp = temp + palabraOriginal[i];
                if (temp=="hundert" or temp=="tausend")
                {
                    vectorNumero.push_back(temp);
                    cont = cont+7;
                    cutPalabraOriginal(cont);
                }
                temp = "";

                for (int i=cont; i<cont+6; i++)
                    temp = temp + palabraOriginal[i];
                if (temp=="sieben")
                {
                    vectorNumero.push_back(temp);
                    cont = cont+6;
                    cutPalabraOriginal(cont);
                }
                temp = "";

                for (int i=cont; i<cont+5; i++)
                    temp = temp + palabraOriginal[i];
                if (temp=="sechs" or temp=="zwölf")
                {
                    vectorNumero.push_back(temp);
                    cont = cont+5;
                    cutPalabraOriginal(cont);
                }
                temp = "";

                for (int i=cont; i<cont+4; i++)
                    temp = temp + palabraOriginal[i];
                if (temp=="zwei" or temp=="drei" or temp=="vier" or temp=="fünf" or temp=="sech" or temp=="sieb"
                    or temp=="acht" or temp=="zehn" or temp=="ssig" or temp=="zwan" or temp=="neun")
                {
                    vectorNumero.push_back(temp);
                    cont = cont+4;
                    cutPalabraOriginal(cont);
                }
                temp = "";

                for (int i=cont; i<cont+3; i++)
                    temp = temp + palabraOriginal[i];
                if (temp=="ein" or temp=="und" or temp=="elf" or temp=="zig")
                {
                    vectorNumero.push_back(temp);
                    cont = cont+3;
                    cutPalabraOriginal(cont);
                }
                temp = "";
            }
    }

    void addPalabra (string terminal){
        palabraComparada = palabraComparada + terminal;
    }

    void cleanPalabra (){
        palabraComparada="";
        temp=palabraComparada;
    }

    bool searchInVariable (vector<string> variables, string compara){
        for(const string terminal: variables)
            if (terminal==compara){
                temp = temp + terminal;
                return true;
            }
        return false;
    }

    bool compararPalabras(){
        if (temp==palabraOriginal)
            return true;
        return false;
    }

    bool Z2(int i){
        if (searchInVariable(lenguaje.getZ3(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getZehn(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        temp=palabraComparada;
        return false;
    }

    bool Z7(int i){
        if (searchInVariable(lenguaje.getZ4(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getZig(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        temp=palabraComparada;
        if (searchInVariable(lenguaje.getDrei(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getSsig(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        temp=palabraComparada;
        return false;
    }

    bool U(int i){
        if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getUnd(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        temp=palabraComparada;
        return false;
    }

    bool Z8(int i){
        if (U(i))
            if (Z7(i+2))
                return true;
        temp=palabraComparada;
        return false;
    }

    bool Z9(int i){
        if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getZ5(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        temp=palabraComparada;
        return false;
    }

    bool Z10(int i){
        if (Z10_a(i))
            return true;
        if (Z10_b(i))
            return true;
        return false;
    };

    bool Z11(int i){
        if (Z11_a(i)){
            return true;
        }
        if (Z11_b(i)){
            return true;
        }
        return false;
    }

    bool Z12(int i){
        if (Z10_a(i)){
            if (Z_1_2_7_8 (i+2))
                return true;
        }
        if (Z10_b(i)){
            if (Z_1_2_7_8 (i+3))
                return true;
        }
        return false;
    }

    bool Z13(int i){
        if (Z13_a(i))
            return true;
        if (Z13_b(i))
            return true;
        if (Z13_c(i))
            return true;
        if (Z13_d(i))
            return true;
        return false;
    }

    bool Z14(int i){
        if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i))){
            {
                addPalabra(vectorNumero.at(i));
                if (Z_1_2_7_8_9_11(i+1))
                    return true;
            }
        }
        cleanPalabra ();

        if (Z13_a_sinComparar(i))
            if (Z_1_2_7_8_9_11(i+2))
                return true;
        cleanPalabra ();

        if (Z13_b_sinComparar(i)!=0)
            if (Z_1_2_7_8_9_11(Z13_b_sinComparar(i)))
                return true;
        cleanPalabra ();

        if (Z13_c_sinComparar(i))
            if (Z_1_2_7_8_9_11(i+4))
                return true;
        cleanPalabra ();

        if (Z13_d_sinComparar(i))
            if (Z_1_2_7_8_9_11(i+5))
                return true;
        return false;
    }

public:

    Scanner(){}

    void setPalabraOriginal(){
        cout<<"Introduzca un número cardinal: ";
        cin>>palabraOriginal;
        cutPalabraOriginal(0);
        vectorNumero.push_back("");
        vectorNumero.push_back("");
        vectorNumero.push_back("");
    }

    bool doScan(){

        if (U(0))
            if (compararPalabras())
            {
                cout<<"Número válido según Regla 11";
                return true;
            }
        cleanPalabra ();


        if (Z2(0))
            if (compararPalabras())
            {
                cout<<"Número válido según Regla 1";
                return true;
            }
        cleanPalabra ();

        if (Z7(0))
            if(compararPalabras())
            {
                cout<<"Número válido según Regla 2/3";
                return true;
            }
        cleanPalabra ();

        if (Z8(0))
            if (compararPalabras())
            {
                cout<<"Número válido según Regla 4";
                return true;
            }
        cleanPalabra ();

        if (Z9(0))
            if (compararPalabras())
            {
                cout<<"Número válido según Regla 5";
                return true;
            }
        cleanPalabra ();

        if (Z10(0))
            if (compararPalabras())
            {
                cout<<"Número válido según Regla 6";
                return true;
            }
        cleanPalabra ();

        if (Z11(0))
            //filtro ya hecho
        {
            cout<<"Número válido según Regla 7";
            return true;
        }
        cleanPalabra ();


        if (Z12(0))
            //filtro ya hecho
        {
            cout<<"Número válido según Regla 8";
            return true;
        }
        cleanPalabra ();

        if (Z13(0))
            //filtro ya hecho
        {
            cout<<"Número válido según Regla 9";
            return true;
        }
        cleanPalabra ();

        if (Z14(0))
        {
            cout<<"Número válido según Regla 10";
            return true;
        }

        cout<<"Error: número no válido según reglas de la gramática";

        saveScan="false";

        return false;
    }

    string getSaveScan(){
        return saveScan;
    }

private:
    bool Z10_a(int i){
        if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i)))
            if(searchInVariable(lenguaje.getZ5(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        temp=palabraComparada;
        return false;
    }

    bool Z10_b(int i){
        if (Z2(i))
            if(searchInVariable(lenguaje.getZ5(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+2));
                return true;
            }
        temp=palabraComparada;
        return false;
    }

    bool Z11_a(int i){
        if (searchInVariable(lenguaje.getZ5(), vectorNumero.at(i)))
        {
            addPalabra(vectorNumero.at(i));
            if (Z_1_2_7_8 (i+1))
                return true;
        }
        temp=palabraComparada;
        return false;
    }

    bool Z11_b(int i){
        if (Z9(i))
            if (Z_1_2_7_8 (i+2))
                return true;
        temp=palabraComparada;
        return false;
    }

    bool Z13_a(int i){
        if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                if (compararPalabras())
                    return true;
            }
        palabraComparada="";
        temp=palabraComparada;
        if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                if (compararPalabras())
                    return true;
            }
        cleanPalabra ();
        return false;
    }

    bool Z13_a_sinComparar(int i){
        if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        cleanPalabra ();
        if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i)))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+1)))
            {
                addPalabra(vectorNumero.at(i));
                addPalabra(vectorNumero.at(i+1));
                return true;
            }
        cleanPalabra ();
        return false;
    }

    bool Z13_b(int i){
        if (Z2(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+2));
                if (compararPalabras())
                    return true;
            }
        cleanPalabra ();
        if (Z7(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+2));
                if (compararPalabras())
                    return true;
            }
        cleanPalabra ();
        if (Z9(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+2));
                if (compararPalabras())
                    return true;
            }
        cleanPalabra ();
        if (searchInVariable(lenguaje.getZ5(), vectorNumero.at(i)))
        {
            addPalabra(vectorNumero.at(i));
            string temp2=palabraComparada;
            if (Z2(i+1))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
                {
                    addPalabra(vectorNumero.at(i+3));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (Z7(i+1))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
                {
                    addPalabra(vectorNumero.at(i+3));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (Z8(i+1))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+5)))
                {
                    addPalabra(vectorNumero.at(i+5));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i+1)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
                {
                    addPalabra(vectorNumero.at(i+1));
                    addPalabra(vectorNumero.at(i+2));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i+1)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+1));
                addPalabra(vectorNumero.at(i+2));
                if (compararPalabras())
                    return true;
                palabraComparada=temp2;
            }
        }
        cleanPalabra ();
        if (Z9(i))
        {
            string temp2=palabraComparada;
            if (Z2(i+2))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+4)))
                {
                    addPalabra(vectorNumero.at(i+4));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (Z7(i+2))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+4)))
                {
                    addPalabra(vectorNumero.at(i+4));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (Z8(i+2))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+6)))
                {
                    addPalabra(vectorNumero.at(i+6));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i+2)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
                {
                    addPalabra(vectorNumero.at(i+2));
                    addPalabra(vectorNumero.at(i+3));
                    if (compararPalabras())
                        return true;
                    palabraComparada=temp2;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i+2)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
            {
                addPalabra(vectorNumero.at(i+2));
                addPalabra(vectorNumero.at(i+3));
                if (compararPalabras())
                    return true;
                palabraComparada=temp2;
            }
        }
        cleanPalabra ();
        return false;
    }

    int Z13_b_sinComparar(int i){
        if (Z2(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+2));
                return i+3;
            }
        cleanPalabra ();
        if (Z7(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+2));
                return i+3;
            }
        cleanPalabra ();
        if (Z9(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
            {
                addPalabra(vectorNumero.at(i+2));
                return i+3;
            }
        cleanPalabra ();
        if (searchInVariable(lenguaje.getZ5(), vectorNumero.at(i)))
        {
            addPalabra(vectorNumero.at(i));
            string temp2=palabraComparada;
            if (Z2(i+1))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
                {
                    addPalabra(vectorNumero.at(i+3));
                    return i+4;
                }
            temp=palabraComparada;
            if (Z7(i+1))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
                {
                    addPalabra(vectorNumero.at(i+3));
                    return i+4;
                }
            temp=palabraComparada;
            if (Z8(i+1))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+5)))
                {
                    addPalabra(vectorNumero.at(i+5));
                    return i+6;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i+1)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
                {
                    addPalabra(vectorNumero.at(i+1));
                    addPalabra(vectorNumero.at(i+2));
                    return i+3;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i+1)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+2)))
                {
                    addPalabra(vectorNumero.at(i+1));
                    addPalabra(vectorNumero.at(i+2));
                    return i+3;
                }
        }
        cleanPalabra ();
        if (Z9(i))
        {
            string temp2=palabraComparada;
            if (Z2(i+2))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+4)))
                {
                    addPalabra(vectorNumero.at(i+4));
                    return i+5;
                }
            temp=palabraComparada;
            if (Z7(i+2))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+4)))
                {
                    addPalabra(vectorNumero.at(i+4));
                    return i+5;
                }
            temp=palabraComparada;
            if (Z8(i+2))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+6)))
                {
                    addPalabra(vectorNumero.at(i+6));
                    return i+7;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i+2)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
                {
                    addPalabra(vectorNumero.at(i+2));
                    addPalabra(vectorNumero.at(i+3));
                    return i+4;
                }
            temp=palabraComparada;
            if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i+2)))
                if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
                {
                    addPalabra(vectorNumero.at(i+2));
                    addPalabra(vectorNumero.at(i+3));
                    return i+4;
                }
        }
        cleanPalabra ();
        return 0;
    }

    bool Z13_c(int i){
        if (Z11_b(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
            {
                addPalabra(vectorNumero.at(i+3));
                if (compararPalabras())
                    return true;
            }
        cleanPalabra ();
        return false;
    }

    bool Z13_c_sinComparar(int i){
        if (Z11_b(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+3)))
            {
                addPalabra(vectorNumero.at(i+3));
                return true;
            }
        cleanPalabra ();
        return false;
    }

    bool Z13_d(int i){
        if (Z8(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+4)))
            {
                addPalabra(vectorNumero.at(i+4));
                if (compararPalabras())
                    return true;
            }
        cleanPalabra ();
        return false;
    }


    bool Z13_d_sinComparar(int i){
        if (Z8(i))
            if (searchInVariable(lenguaje.getZ6(), vectorNumero.at(i+4)))
            {
                addPalabra(vectorNumero.at(i+4));
                return true;
            }
        cleanPalabra ();
        return false;
    }

    bool Z_1_2_7_8 (int i){
        string temp2 = palabraComparada;
        if (Z2(i))
        {
            if (compararPalabras())
                return true;
            palabraComparada=temp2;
        }
        temp=palabraComparada;
        if (Z7(i))
        {
            if (compararPalabras())
                return true;
            palabraComparada=temp2;
        }
        temp=palabraComparada;
        if (Z8(i))
        {
            if (compararPalabras())
                return true;
            palabraComparada=temp2;
        }
        temp=palabraComparada;
        if (searchInVariable(lenguaje.getZ1(), vectorNumero.at(i)))
        {
            addPalabra(vectorNumero.at(i));
            if (compararPalabras())
                return true;
            palabraComparada = temp2;
        }
        temp=palabraComparada;
        if (searchInVariable(lenguaje.getZ2(), vectorNumero.at(i)))
        {
            addPalabra(vectorNumero.at(i));
            if (compararPalabras())
                return true;
            palabraComparada = temp2;
        }
        temp=palabraComparada;
        return false;
    }

    bool Z_1_2_7_8_9_11(int i){
        string temp2 = palabraComparada;
        if (Z_1_2_7_8 (i))
            return true;
        palabraComparada = temp2;
        temp="";
        if (Z9(i))
            if (compararPalabras())
                return true;
        palabraComparada = temp2;
        temp="";
        if (Z11(i))
            if (compararPalabras())
                return true;
        palabraComparada = temp2;
        temp="";
        return false;
    }
};