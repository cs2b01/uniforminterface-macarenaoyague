//
// Created by Macarena Oyague on 2019-09-28.
//
using namespace std;
#include <exception>

template <class T, unsigned int BUFFER_SIZE>

class DynamicArray{

private:

    unsigned int const CAPACITY = BUFFER_SIZE;
    unsigned int size;
    unsigned int reserved;
    T * items;

    void reserve (){
        reserved += CAPACITY;
        T * temp = new T[reserved];
        for (auto i = 0; i<size; i++)
            temp[i] = items[i];
        delete [] items;
        items = temp;
    }

public:

    DynamicArray(){
        size = 0;
        reserved = BUFFER_SIZE;
        items = new T [CAPACITY];
    }

    DynamicArray* pushBack(T item){
        if (size == reserved){
            reserve();
        }
        items[size] = item;
        size++;
        return this;
    }

    unsigned int getSize() const{
        return size;
    }

    T getItem(unsigned int index){
        return items[index];
    }

    unsigned int getReserved() const{
        return reserved;
    }

    void removeElement(unsigned int index){
        if (size-1<reserved){
            reserved -= CAPACITY;
            T * temp = new T[reserved];
            unsigned int contador=0;
            for (auto i = 0; i<size; i++)
                if (i != index)
                {
                    temp[contador] = items[i];
                    contador++;
                }
            delete [] items;
            items = temp;
        }
        else
        {
            for (int i = index; i < size-1; ++i)
                items[i]=items[i+1];
            items[size-1]=0;
        }
        size--;
    }

    void addElement(unsigned int index, T element){
        if (size++>reserved){
            reserved += CAPACITY;
            T * temp = new T[reserved];
            int contador = 0;
            for (auto i = 0; i<size+1; i++)
                if (i!=index)
                {
                    temp[i] = items[i];
                    contador++;
                }
                else
                    temp[i]=element;
            delete [] items;
            items = temp;
        }
        else {
            for (auto i = size; i<index; i--)
                items[i+1]=items[i];
            items[index]=element;
        }
        size++;
    }

    //if (index<size)
    //{ pushBack(items[size-1]);
    //  for (int i=size-1

    void sort(){
        T* temp = new T[reserved];
        for (int j = 0; j < size; ++j) {
            int positionMayor = 0;
            T mayor = items[positionMayor];
            for (int a = 1; a < size; ++a){
                if(items[a]>mayor){
                    positionMayor=a;
                    mayor=items[positionMayor];
                }
            }
            temp[j]=mayor;
            items[positionMayor]=0;
        }
        items=temp;
    }
};