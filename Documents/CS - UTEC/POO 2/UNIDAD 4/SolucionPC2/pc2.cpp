//
// Created by estanislao.contreras on 10/12/2019.
//

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

template <class T>
class Deserializador{
public:
    virtual T* deserializar (string cadena, char S)=0;
};

template <class T>
class Serializador{
public:
    virtual string serializar(T* objeto, char S) = 0;
};


class Postulante{
protected:
    string facultad;
    string dni;
    string nombreCompleto;
    unsigned int lectura;
    unsigned int redaccion;
    unsigned int matematica;
public:
    Postulante(const string &facultad, const string &dni, const string &nombreCompleto, unsigned int lectura,
               unsigned int redaccion, unsigned int matematica) : facultad(facultad), dni(dni),
                                                                  nombreCompleto(nombreCompleto), lectura(lectura),
                                                                  redaccion(redaccion), matematica(matematica) {}
    virtual double calificacion()=0;

    const string &getFacultad() const {
        return facultad;
    }

    const string &getDni() const {
        return dni;
    }

    const string &getNombreCompleto() const {
        return nombreCompleto;
    }

    unsigned int getLectura() const {
        return lectura;
    }

    unsigned int getRedaccion() const {
        return redaccion;
    }

    unsigned int getMatematica() const {
        return matematica;
    }
};

class PostulanteCiencias : public Postulante{
public:
    PostulanteCiencias(const string &facultad, const string &dni, const string &nombreCompleto, unsigned int lectura,
                       unsigned int redaccion, unsigned int matematica) : Postulante(facultad, dni, nombreCompleto,
                                                                                     lectura, redaccion, matematica) {}

    double calificacion() override {
        return 10*redaccion+
               10*lectura+
               7.5*matematica;
    }
};

class PostulanteLetras : public Postulante{
public:
    PostulanteLetras(const string &facultad, const string &dni, const string &nombreCompleto, unsigned int lectura,
                     unsigned int redaccion, unsigned int matematica) : Postulante(facultad, dni, nombreCompleto,
                                                                                   lectura, redaccion, matematica) {}


    double calificacion() override {
        return 7.5*redaccion+
                7.5*lectura+
                10*matematica;
    }
};


class DeserializadorPostulante: public Deserializador <Postulante>{
public:
    Postulante* deserializar (string cadena, char S) override{
        vector<string> campos;
        stringstream stream(cadena);
        string campo;
        while(getline(stream,campo,S)){
            campos.push_back(campo);
        }
        if (campos.size() ==6){
            string facultad = campos[0];
            string dni = campos[1];
            string nombreCompleto = campos[2];
            unsigned int lectura = stoi(campos[3]);
            unsigned int redaccion = stoi(campos[4]);
            unsigned int matematica = stoi(campos[5]);
            if (facultad=="C")
                return new PostulanteCiencias(facultad,dni,nombreCompleto,lectura,redaccion,matematica);
            else
                return new PostulanteLetras(facultad,dni,nombreCompleto,lectura,redaccion,matematica);
        }
        throw logic_error("NO se puede crear a Postulante");
    }
};


class SerializadorPostulante: public Serializador<Postulante>{
public:
    string serializar(Postulante *objeto, char S) override{
        return objeto->getFacultad() + S +
               objeto->getDni() + S +
               objeto->getNombreCompleto() + S +
               to_string(objeto->calificacion());
    };
};

class Examen{
private:
    vector<Postulante*>* postulantes;
    DeserializadorPostulante deserializador;
    SerializadorPostulante serializador;

    void ordenar(){
        for (int i=0;i<postulantes->size()-1;i++)
            for (int j=i+1;j<postulantes->size();j++)
                if ((*postulantes)[i]->calificacion()>(*postulantes)[j]->calificacion())
                    swap((*postulantes)[i],(*postulantes)[j]);
    }

    void listar(const string &facultad, string nombreArchivo, char separador){
        ordenar();
        fstream* archivo = new fstream(nombreArchivo, ios_base::out);
        if (archivo) {
            for(Postulante* postulante: *postulantes)
                if (postulante->calificacion()>=750)
                    if (postulante->getFacultad()==facultad)
                        *archivo << serializador.serializar(postulante, separador)<<endl;
            archivo->close();
        }
        delete archivo;
    }

    public:
    Examen(string nombreArhivoPostulantes){
        postulantes = new vector<Postulante*>();
        fstream* archivo = new fstream(nombreArhivoPostulantes, ios_base::in);
        string linea;
        if (archivo){
            while (getline(*archivo,linea)){
                Postulante* postulante = deserializador.deserializar(linea, ',');
                postulantes->push_back(postulante);
            }
            archivo->close();
        }
        delete archivo;
    }

    void listarPostulantesCiencias(){
        listar("C","ciencias.csv", ',');
    }

    void listarPostulantesLetras(){
        listar("L","letras.csv", ',');
    }
};