#include <iostream>
#include <vector>
using namespace std;

template <class T>
T Absolute(T element){
    if (element<0)
        return element*(-1);
    return element;
}

template <class T>
T AbsoluteOperadorTernario(T element){
    return (element<0) ? element*-1 : element;
                        //verdad        falso
}

template <class T>
T** split_range (vector <T> vector, int n){
    T ** contenedor = new T*[n];
    int sizeContenedor = vector.size()/n;
    for (int a = 0; a < n; a++)
        contenedor[a]= new T[sizeContenedor];
    int contadorFila=0;
    int contadorColumna=0;
    int indice=0;
    while (contadorFila<n)
    {
        contenedor[contadorFila][contadorColumna]=vector[indice];
        if ((contadorColumna!=0) && (contadorColumna%n==0))
        {
            contadorColumna=0;
            contadorFila++;
        }
        contadorColumna++;
        indice++;
    }
    return contenedor;
}


template <class T>
void print(T* contenedor ){
    T* temp = contenedor;
    do{
        cout<<*temp<<endl;
        temp++;
    } while (temp!=NULL);
}


template <class T>
void print2(T** contenedor ){
    T** temp = contenedor;
    do{
       print(*temp);
       temp++;
    } while (temp!=NULL);
}

template <class T>
vector <T>  sumar_rango(vector <T> v1, vector  <T> v2){
    vector  <T> contenedor;
    int mayorSize;
    if (v1.size()>v2.size())
        mayorSize=v1.size();
    else
        mayorSize=v2.size();
    int contador = 0, contadorV1=0, contadorV2=0;
    while (contador<mayorSize)
    {
        contenedor.push_back(v1[contadorV1]+v2[contadorV2]);
        contador++;
        contadorV2++;
        contadorV1++;
        if (contadorV1==v1.size())
            contadorV1=0;
        if (contadorV2==v2.size())
            contadorV2=0;
    }
    return contenedor;
}

template <class T>
vector <T>  delete_items(vector <T> v, T elemento){
    vector <T> temp;
    for (int i = 0; i<v.size(); i++)
        if (v[i]!=elemento)
            temp.push_back(v[i]);
    return temp;
}


template <class T>
bool isThere(vector <T> vector, T element){
    for (int a=0; a<vector.size(); a++)
        if (vector[a]==element)
            return true;
    return false;
}

template <class T>
vector <T>  delete_items_by_vector(vector <T> v, vector <T> elementsToDelete){
    for (int a= 0; a<elementsToDelete.size(); a++)
        for (int i = 0; i<v.size(); i++)
            if (v[i]==elementsToDelete[a])
                v.erase(v.begin()+i);
    return v;
}

template <class T>
vector <T> delete_duplicated(vector <T> v){
    vector <T> temp;
    for (int a= 0; a<v.size(); a++)
        if (isThere(temp, v[a])==false)
            temp.push_back(v[a]);
    return temp;
}

int main() {

    vector <int> vector = {1,2,3,4,4,6,7,1,4};
    std::vector <int> vector2 = delete_duplicated(vector);
    std::cout<<vector2[8]<<endl;

    return 0;
}

