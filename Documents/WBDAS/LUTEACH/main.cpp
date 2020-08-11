#include <iostream>
using namespace std;

struct profesorUTEC{
    string nombre;
    string apellido;
    int edad;
    int nCursosDictados;
    bool TC;
};

enum carrera{
    industrial,
    quimica,
    electronica
};

int main() {

    int numero = 5;
    int casas = 6;
    int regalos = 2;
    float nota = 15.5;
    char letraNombre = 'C';
    string nombre = "Macarena";
    bool verdad = true;

    profesorUTEC Jaime;
    Jaime.nombre = "Jaime";
    Jaime.apellido = "Farfan";
    Jaime.edad = 37;
    Jaime.nCursosDictados = 3;
    Jaime.TC = false;

    profesorUTEC Laura;
    Laura.nombre = "Laura";

    carrera Claudia = quimica;

    switch (Claudia){
        case electronica:
            cout<<"Llevará el curso de señales digitales"; break;
        case industrial:
            cout<<"Llevará cursos en logística"; break;
        case quimica:
            cout<<"Llevará cursos en los laboratorios"; break;
    }

    cout<<endl;

    cout<< sizeof(int);

    return 0;
}
