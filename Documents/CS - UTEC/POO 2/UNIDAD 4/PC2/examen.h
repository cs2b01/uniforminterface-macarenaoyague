//
// Created by Macarena Oyague on 2019-10-09.
//

#include <vector>
#include <iostream>
using namespace std;
#include <fstream>
#include <iostream>
#include "postulanteLetras.h"
#include "postulanteCiencias.h"
#include <sstream>


class Examen{
private:
    vector <Postulante*> * postulantes;
    vector <Postulante*> * ingresantesCiencias;
    vector <Postulante*> * ingresantesLetras;
public:
    Examen(const string  &nombreArchivoPostulantes) {
        postulantes = new vector <Postulante*>;
        ingresantesCiencias = new vector <Postulante*>;
        ingresantesLetras = new  vector <Postulante*>;
        std::string atributo;
        fstream* archivo  = new fstream(nombreArchivoPostulantes, ios_base::in);
        if (archivo){
            string string;
            int contador=1;
            std::string facultad, dni, nombreCompleto;
            std::string stringLectura, stringRedaccion, stringMatematica;
            while (getline(*archivo, string)){
                stringstream stringSS(string);
                Postulante * postulante;
                while (getline(stringSS, atributo, ','))
                {
                    if (contador==1)
                        facultad=atributo;
                    else if (contador==2)
                        dni=atributo;
                    else if (contador==3)
                        nombreCompleto=atributo;
                    else if(contador==4)
                        stringLectura=atributo;
                    else if (contador==5)
                        stringRedaccion=atributo;
                    else if (contador==6)
                    {
                        stringMatematica=atributo;
                        contador=0;
                    }
                    contador++;
                }
                stringstream stringSSLectura(stringLectura);
                stringstream stringSSRedaccion(stringRedaccion);
                stringstream stringSSMatematica(stringMatematica);
                int lectura;
                int redaccion;
                int matematica;
                stringSSLectura>>lectura;
                stringSSRedaccion>>redaccion;
                stringSSMatematica>>matematica;
                if (facultad=="L")
                {
                    postulante=new PostulanteLetras(facultad,dni,nombreCompleto,lectura,redaccion,matematica);
                    if (postulante->calificacion()>=750)
                        ingresantesLetras->push_back(postulante);
                }
                if (facultad=="C")
                {
                    postulante=new PostulanteCiencias(facultad,dni,nombreCompleto,lectura,redaccion,matematica);
                    if (postulante->calificacion()>=750)
                        ingresantesCiencias->push_back(postulante);
                }
                postulantes->push_back(postulante);
            }
            archivo->close();
        }
        delete archivo;
    }

    void leer(){
        cout<<(*postulantes).size();
    }

    void listarIngresantesCiencias(const string  &nombreArchivoIngresantes){
        fstream* archivo = new fstream(nombreArchivoIngresantes, ios_base::out);
        if (archivo) {
            for (Postulante *ingresanteCiencias: *ingresantesCiencias)
                *archivo << ingresanteCiencias->getFacultad() << "," << ingresanteCiencias->getDni() << ","
                         << ingresanteCiencias->getNombreCompleto() << "," << ingresanteCiencias->calificacion()
                         << endl;
            archivo->close();
        }
        delete archivo;
    }

    void listarIngresantesLetras(const string  &nombreArchivoIngresantes ){
        fstream* archivo = new fstream(nombreArchivoIngresantes, ios_base::out);
        if (archivo) {
            for (Postulante *ingresanteLetras: *ingresantesLetras)
                *archivo << ingresanteLetras->getFacultad() << "," << ingresanteLetras->getDni() << ","
                         << ingresanteLetras->getNombreCompleto() << "," << ingresanteLetras->calificacion()
                         << endl;
            archivo->close();
        }
        delete archivo;
    }

    virtual ~Examen() {
        for(Postulante * postulante: * postulantes)
            delete postulante;
        delete postulantes;
    }

};