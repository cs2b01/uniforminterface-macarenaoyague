#include <iostream>
#include <cmath>
//para el sqrt
using namespace std;

int suma (int a, int b){
    //debo retornar si es que no es void SE TIENE QUE
    int t=a+b;
    return t;
}

int sumal (int a, int b){
    //mas simple
    return a+b;
}

const double get_pi(){
    //puede retornar numeros
    return 3.1416;
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

void ejemplo1(){
    int mx=max(10,20);
    //si la funcion tiene un return tiene que ser guardada en una variable
    cout<<"el valor maximo es "<<max(10,20)<<endl;
    //o imprimirlo defrente
    cout<<max(30,40)<<endl;
    //depende de si es que quiero mostrarlo inmediatamente o si es que quiero almacener ese dato
}

void swap(int a, int b) {
    //interchange (swap between two variables)
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void swap2(int &a, int &b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void ejemplo2(){
    int x=11;
    int y=12;
    swap(x,y);
    cout<<"x: "<<x<<" and y: "<<y<<endl;
    //lo que ocurre aca es que el valor cambia dentro de la funcion pero ese cambio no es almacenado en la variable
    swap2(x,y);
    cout<<"x: "<<x<<" and y: "<<y<<endl;
    //con el uso del & es posible variar el contenido del tipo (int,char, etc) que vario dentro de la funcion
}

void raices_cuadraticas(double a, double b, double c, double& r1, double& r2){
    r1=(-b+sqrt(b*b-4*a*c))/(2*a);
    r2=(-b+sqrt(b*b-4*a*c))/(2*a);
}

void ejemplo3(){
    double a=1;
    double b=2;
    double c=1;
    double r1=0;
    double r2=0;
    raices_cuadraticas(a,b,c,r1,r2);
    cout<<"las raices son"<<r1<<" y "<<r2<<endl;
}

void ppt1(){
    int a;
    do{
        cout<<"introduzca un numero entero: ";
        cin>>a;
    }while(a!=0);
}

void ppt2(){
    int a;
    do{
        cout<<"Numero: ";
        cin>>a;
    }while(a<100);
    int temp;
    int contador=0;
    while (a!=0){
        temp=a/10;
        a=temp;
        contador++;
    }
    cout<<"Numero de digitos: "<<contador<<endl;
}

void ppt3(){
    double pi_incrementando=3;
    int contador=1;
    double temp;
    cout<<endl<<"Valor de pi numero "<<contador<<pi_incrementando;
    while(contador<=60){
        temp=pi_incrementando+4.0/((contador+1)*(contador+2)*(contador+3));
        pi_incrementando=temp;
        contador++;
        cout<<"Valor de pi numero "<<contador<<": "<<pi_incrementando<<endl;
    }
};

void ppt4(){
    int cantidad_personas;
    do{
        cout<<"Introduzca la cantidad de personas a encuestar: ";
        cin>>cantidad_personas;
    }
    while (cantidad_personas<5 || cantidad_personas>30);
    char bebida;
    for(int x=1; x<=cantidad_personas;x++){
        do{
            cout<<"Usuario #"<<1<<" introduzca su bebida favorita :";
            cin>>bebida;
        }while(bebida!="M&& bebida!="m" )
        //COMILLAS SIMPLES
    }
}
int main() {
    ejemplo1();
    ejemplo2();
    ejemplo3();
    ppt1();
    ppt2();
    ppt3();
    return 0;
}