//
// Created by estanislao.contreras on 6/7/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <thread>
#include <sstream>
#include <future>

using namespace std;



template <class T>
class Repository{
private:
    vector<T*>* items;
    string fileName;



public:
    Repository(string fileName, function<T* (string)> lineToObject) : fileName(fileName){
        fstream * archivo;
        string line;

        items = new vector<T*>();

        this -> fileName = fileName;
        archivo = new fstream();
        archivo -> open(fileName, ios::in);

        while(getline(*archivo, line)) {
            items -> push_back(lineToObject(line));
        }

    }

    Repository<T>* add(T* item){
        items -> push_back(item);
        return nullptr;
    }

    T* findFirst(function<bool (T*)> condition){
        for(T *item: *items){
            if(condition(item))
                return item;
        }
        return nullptr;
    }

    T* findLast(function<bool (T*)> condition){
        auto result = new vector<T*>();

        for(T *item: *items){
            if(condition(item))
                result->push_back(item);
        }
        return result->back();
    }


    vector<T*>* find(function<bool (T*)> condition){
        return nullptr;
    }

    unsigned int countCondition(unsigned int from, unsigned int to,function<bool (T*)> condition){
        unsigned int con = 0;
        for (unsigned int i=from; i<to; i++)
        {
            if(condition((*items)[i]))
                con++;
        }
        return con;
    }

    unsigned int count(function<bool (T*)> condition){
        unsigned int MAX = items->size();

        future<unsigned int> s1 = async(&Repository::countCondition,this,0,MAX/2,condition);
        future<unsigned int> s2 = async(&Repository::countCondition,this,MAX/2,MAX,condition);

        return s1.get() + s2.get();
    }


    unsigned int evaluateCondition(unsigned int from, unsigned int to,function<bool (T*)> condition, function<void (T*)> do_action){
        unsigned int con = 0;
        for (unsigned int i=from; i<to; i++)
        {
            if(condition((*items)[i])) {
                do_action((*items)[i]);
                con++;
            }
        }
        return con;
    }


    void forAll(function<void (T*)> do_action){
    }
    unsigned int forEach(function<bool (T*)> condition, function<void (T*)> do_action ){

        unsigned int MAX = items->size();

        future<unsigned int> s1 = async(&Repository::evaluateCondition,this,0,MAX/2,condition,do_action);
        future<unsigned int> s2 = async(&Repository::evaluateCondition,this,MAX/2,MAX,condition,do_action);

        return s1.get() + s2.get();
    }


    void updateChanges(function<string (T*)> objectToLine){
    }

    vector<T *> *getItems() const {
        return items;
    }

    const string &getFileName() const {
        return fileName;
    }

    ~Repository(){
        items->clear();
        delete items;
    }

};
