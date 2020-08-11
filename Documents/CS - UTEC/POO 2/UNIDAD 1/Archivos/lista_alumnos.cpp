//
// Created by estanislao.contreras on 10/5/2019.
//
#include "alumno.cpp"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class ListaAlumnos{
private:
    vector<Alumno *>* alumnos;

public:
    ListaAlumnos(string nombreArchivo){
        alumnos = new vector<Alumno*>();
        string nombreAlumno;
        fstream* archivo  = new fstream(nombreArchivo, ios_base::in);
        if (archivo){
            while (getline(*archivo, nombreAlumno)){
                Alumno* nuevoAlumno = new Alumno(nombreAlumno);
                alumnos->push_back(nuevoAlumno);
            }
            archivo->close();
        }
        delete archivo;
    }

    void imprimir(){
        for(Alumno* alumno: *alumnos)
            cout<<alumno->getNombreCompleto()<<endl;
    }

    void registrar(Alumno* alumno){
        alumnos->push_back(alumno);
    }

    void guardar(string nombreArchivo){
        fstream* archivo = new fstream(nombreArchivo, ios_base::out);
        if (archivo){
            for(auto alumno : *alumnos)
                *archivo<<alumno->getNombreCompleto()<<endl;
            archivo->close();
        }
        delete archivo;
    }

    ~ListaAlumnos(){
        for(auto alumno: *alumnos)
            delete alumno;
        delete alumnos;

    }

};
