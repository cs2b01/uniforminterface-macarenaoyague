//
// Created by Macarena Oyague on 2019-04-01.
//

#include "Vector.h"

namespace UTEC {

    vector::vector() : _arr{nullptr}, _size(0) {}

    vector::~vector() {delete [] _arr;}

    void vector::push_back(const int &val) {
        _size++;
        if (_arr==nullptr){
            _arr=new int [_size];
            _arr[_size-1]=val;
        } else {
            int* temp=new int [_size];
            for (int x=0; x<=_size-2;x++)    {
                temp[x]=_arr[x];
            }
            temp[_size-1]=val;
            _arr=temp;
        }
        _arr[_size-1]=val;
    }

    void vector::pop_back() {
        int* temp=new int [_size-1];
        for (int x=0; x<_size-1; ++x)
        {
            temp[x]=_arr[x];
        }
        _size--;
        delete [] _arr;
        _arr=temp;
    }

    void vector::insert(int pos, const int& value){
        int *temp=new int[_size];
        for (int x=0; x<pos; x++){
            temp[x]=_arr[x];
        }
        _arr[pos]=value;
        _size++;
        for (int x=pos+1; x<=_size; x++)
        {
            _arr[x]=temp[x-1];
        }
    }

    int vector::size() {return _size;}

    int vector::get_item(int i) {return _arr[i];}
}
