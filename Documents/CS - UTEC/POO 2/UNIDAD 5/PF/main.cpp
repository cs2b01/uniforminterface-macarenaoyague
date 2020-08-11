#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

void generatePositions(string nameFile){

}

class Tablero{
private:
    map<string, string> fichas;
    string nombreEquipo;

public:
    Tablero(){
        nombreEquipo = "";
    }

    void setNombreEquipo(const string &nombreEquipo) {
        this->nombreEquipo = nombreEquipo;
    }

    const string &getNombreEquipo() const {
        return nombreEquipo;
    }

    map<string, string> getFichas() const {
        return fichas;
    }
};



class Game{
private:

    Tablero *propio;
    Tablero *contrincante;
    string token;
    string scope;

    void atacar(){

        string posicion;

        while (contrincante->getFichas().size()<20) {
            //remove("FirstPlayer.out");
            remove("HOLAAMIGO2.out");
            cout << "Inserte posición a atacar: ";
            //hacer el llenado implementando lógica
            cin >> posicion;
            fstream *fileIn = new fstream("FirstPlayer.in", ios_base::out);
            *fileIn << "TOKEN=" << token << endl << "ATTACK=" << posicion;

            bool fileOpen = false;
            fstream *fileOut;

            while (!fileOpen) {
                //fileOut = new fstream("FirstPlayer.out", ios_base::in);
                fileOut = new fstream("HOLAAMIGO2.out", ios_base::in);
                if (!fileOut->fail())
                    fileOpen = true;
            }

            string linea;
            string linea2;
            vector<string> argumentos;
            getline(*fileOut, linea); //Para el attack
            //se podría optimizar esto con callables...
            while (getline(*fileOut, linea)) {
                stringstream line(linea);
                while (getline(line, linea2, '='))
                    argumentos.push_back(linea2);
            }

            fileOut->close();

            if (argumentos[3] == "DAMAGED"){
                contrincante->getFichas()[posicion] = "X";
                //chequear para avanzar en horizontal arriba y abajo
                //chequear para avanzar en vertical arriba y abajo
            }

            if (argumentos[3] == "DESTROYED"){
                contrincante->getFichas()[posicion] = "X";
            }
        }
    }

    void posicionarNaves(){

        //chequear los limites del scope
        //haciendo como si fuera la preestablecida
        string nave, coordenadas, orientacion;
        int aCont = 0, bCont = 0, sCont = 0, tCont = 0;
        while (propio->getFichas().size()<20)
        {
            //remove("FirstPlayer.out");
            remove("HOLAAMIGO.out");
            cout << "Inserte nave-coordenadas-orientacion: ";
            //hacer el llenado implementando lógica
            cin >> nave >> coordenadas >> orientacion;
            fstream *fileIn = new fstream("FirstPlayer.in", ios_base::out);
            *fileIn << "TOKEN=" << token << endl << "PLACEFLEET=" <<
                        nave << "-" << coordenadas << "-" << orientacion;

            bool fileOpen = false;
            fstream *fileOut;

            while (!fileOpen){
                //fileOut = new fstream("FirstPlayer.out", ios_base::in);
                fileOut = new fstream("HOLAAMIGO.out", ios_base::in);
                if (!fileOut->fail())
                    fileOpen = true;
            }

            string linea;
            string linea2;
            vector<string> argumentos;
            getline(*fileOut, linea); //Para el placefleet
            //se podría optimizar esto con callables...
            while (getline(*fileOut, linea)){
                stringstream line(linea);
                while (getline(line, linea2, '='))
                    argumentos.push_back(linea2);
            }

            fileOut->close();

            if (argumentos[3] == "CONTINUE") {
                if (nave == "T" and tCont != 4)
                {
                    tCont ++;
                    propio->getFichas()[coordenadas] = nave;
                }
                if (nave == "S" and sCont != 3)
                {
                    if (orientacion == "H")
                    {
                        sCont++;
                        propio->getFichas()[coordenadas] = nave;
                        string key;
                        key.push_back(char(coordenadas[0]+1));
                        if (coordenadas[2] == '\0')
                            key.push_back(coordenadas[1]);
                        else
                        {
                            key.push_back(coordenadas[1]);
                            key.push_back(coordenadas[2]);
                        }
                        propio->getFichas()[key] = nave;
                    }
                    else if (orientacion == "V")
                    {
                        sCont++;
                        propio->getFichas()[coordenadas] = nave;
                        string key;
                        key.push_back(coordenadas[0]);
                        if (coordenadas[1] != '9')
                            key.push_back(char(coordenadas[1]+1));
                        else if (coordenadas[1] == '9')
                        {
                            key.push_back('1');
                            key.push_back('0');
                        }
                        propio->getFichas()[key] = nave;
                    }
                }
                if (nave == "B" and bCont != 2)
                {
                    if (orientacion == "H")
                    {
                        bCont ++;
                        propio->getFichas()[coordenadas] = nave;
                        string key;
                        key.push_back(char(coordenadas[0]+1));
                        if (coordenadas[2] == '\0')
                            key.push_back(coordenadas[1]);
                        else
                        {
                            key.push_back(coordenadas[1]);
                            key.push_back(coordenadas[2]);
                        }
                        propio->getFichas()[key] = nave;
                        string key2;
                        key2.push_back(char(coordenadas[0]+2));
                        if (coordenadas[2] == '\0')
                            key2.push_back(coordenadas[1]);
                        else
                        {
                            key2.push_back(coordenadas[1]);
                            key2.push_back(coordenadas[2]);
                        }
                        propio->getFichas()[key2] = nave;
                    }
                    else if (orientacion == "V")
                    {
                        bCont++;
                        propio->getFichas()[coordenadas] = nave;
                        string key;
                        key.push_back(coordenadas[0]);
                        key.push_back(char(coordenadas[1]+1));
                        propio->getFichas()[key] = nave;
                        string key2;
                        key2.push_back(coordenadas[0]);
                        if (char(coordenadas[1]+1) != '9')
                            key2.push_back(char(coordenadas[1]+2));
                        else if (char(coordenadas[1]+1) == '9')
                        {
                            key2.push_back('1');
                            key2.push_back('0');
                        }
                        propio->getFichas()[key2] = nave;
                    }
                }
                if (nave == "A" and aCont != 1)
                {
                    if (orientacion == "H")
                    {
                        aCont++;
                        propio->getFichas()[coordenadas] = nave;
                        string key;
                        key.push_back(char(coordenadas[0]+1));
                        if (coordenadas[2] == '\0')
                            key.push_back(coordenadas[1]);
                        else
                        {
                            key.push_back(coordenadas[1]);
                            key.push_back(coordenadas[2]);
                        }
                        propio->getFichas()[key] = nave;
                        string key2;
                        key2.push_back(char(coordenadas[0]+2));
                        if (coordenadas[2] == '\0')
                            key2.push_back(coordenadas[1]);
                        else
                        {
                            key2.push_back(coordenadas[1]);
                            key2.push_back(coordenadas[2]);
                        }
                        propio->getFichas()[key2] = nave;
                        string key3;
                        key3.push_back(char(coordenadas[0]+3));
                        if (coordenadas[2] == '\0')
                            key3.push_back(coordenadas[1]);
                        else
                        {
                            key3.push_back(coordenadas[1]);
                            key3.push_back(coordenadas[2]);
                        }
                        propio->getFichas()[key3] = nave;
                    }
                    else if (orientacion == "V")
                    {
                        aCont++;
                        propio->getFichas()[coordenadas] = nave;
                        string key;
                        key.push_back(coordenadas[0]);
                        key.push_back(char(coordenadas[1]+1));
                        propio->getFichas()[key] = nave;
                        string key2;
                        key2.push_back(coordenadas[0]);
                        if (char(coordenadas[1]+1) != '9')
                        key2.push_back(char(coordenadas[1]+2));
                        else if (char(coordenadas[1]+1) == '9')
                        {
                            key2.push_back('1');
                            key2.push_back('0');
                        }
                        propio->getFichas()[key2] = nave;
                        string key3;
                        key3.push_back(coordenadas[0]);
                        if (char(coordenadas[1]+2) != '9')
                            key3.push_back(char(coordenadas[1]+3));
                        else if (char(coordenadas[1]+2) == '9')
                        {
                            key3.push_back('1');
                            key3.push_back('0');
                        }
                        propio->getFichas()[key3] = nave;
                    }
                }
            }
            if (argumentos[3] == "FULL")
                atacar();
        }
    }

    void saludo() {

        string nombreEquipo;

        while (propio->getNombreEquipo() == "") {
            remove("FirstPlayer.out");
            cout << "Inserte nombre del equipo: ";
            cin >> nombreEquipo;
            fstream *fileIn = new fstream("FirstPlayer.in", ios_base::out);
            *fileIn << "HANDSHAKE=" << nombreEquipo;
            fileIn->close();

            bool fileOpen = false;
            fstream *fileOut;

            while (!fileOpen){
                fileOut = new fstream("FirstPlayer.out", ios_base::in);
                if (!fileOut->fail())
                    fileOpen = true;
            }

            string linea;
            string linea2;
            vector<string> argumentos;
            getline(*fileOut, linea); //Para el handshake
            while (getline(*fileOut, linea)){
                stringstream line(linea);
                while (getline(line, linea2, '='))
                    argumentos.push_back(linea2);
            }
            fileOut->close();

            if (argumentos[1] == "ACCEPTED") {
                propio->setNombreEquipo(nombreEquipo);
                token = argumentos[3];
                scope = argumentos[5];
                posicionarNaves();
            }

        }
    }

public:
    Game() {
        propio = new Tablero();
        contrincante = new Tablero();
        saludo();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Game game;
    return 0;
}



