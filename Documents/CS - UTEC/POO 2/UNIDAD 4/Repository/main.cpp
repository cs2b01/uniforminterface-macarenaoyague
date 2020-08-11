#include <iostream>
#include <vector>
using namespace std;

#include "functional"

template <class T>
class Repository{
private:
    vector <T>* items;
public:
    Repository(){
        items = new vector <T>;
    }
    Repository* insert(T item){
        items->push_back(item);
        return this;
    }
    vector <T>* select(function <bool (T)> where){
                    //funcion que recibe un T y regresa un bool
                                            //es el bool
        vector <T>* result = new vector <T>;
        for (auto item: *items)
            if (where(item))
                result->push_back(item);
        return result;
    }

    unsigned int deleteItem (function <bool (T)> where){
        vector <T>* temp = new vector <T>;
        for (auto item: *items)
            if (!where(item))
                temp->push_back(item);
        delete items;
        items = temp;
        return temp->size();
    }

    unsigned int del(function <bool (T)> where){
        auto to_delete = remove_if(items->begin(), items->end(), where);
        items->erase(to_delete, items);
        //https://www.geeksforgeeks.org/stdremove-stdremove_if-c/
        return items->size();
    }

    vector <T>* sortBy (function <bool (T, T)> compare){
        int i, j;
        for (i = 0; i < items->size(); i++)
            for (j = i+1; j < items->size(); j++)
                if (compare((*items)[i], (*items)[j]))
                    swap((*items)[i], (*items)[j]);
        return items;
    }

    vector <T>* sortBy2 (function <bool (T, T)> compare){
        sort(items->begin(), items->end(), compare);
        return items;
    }

    vector<T>* update (function <bool (T)> where, function <T (T)> what){
        for (int a = 0; a<items->size(); a++)
            if (where((*items)[a]))
                (*items)[a] = what((*items)[a]);
        return items;
    }

    vector<T>* update2 (function <bool (T)> where, function <void (vector<T>*, int) > what){
        for (int a = 0; a<items->size(); a++)
            if (where((*items)[a]))
                what(items, a);
        return items;
    }


    vector<T> *getItems() const {
        return items;
    }

};

bool comparar (int a, int b){
    return a>b;
}

int main() {
    Repository<int>* repo = (new Repository<int>())->insert(10)->insert(20)->insert(5)->insert(40)->insert(4);

    auto select = repo->select([](int n){return n>=10;});
                                //parametros  cuerpo
                                //T = n
                                        //retorna un bool
                                //funcion anónima

    for (auto item: *select)
        cout<<item<<" ";
    cout<<endl;

    auto selectAll = repo->select([](int n){return true;});

    for (auto item: *selectAll)
        cout<<item<<" ";

    auto deleteItem = repo->deleteItem([](int n){return n>10;});

    cout<<deleteItem<<endl;

    for (auto item: *repo->getItems())
        cout<<item<<" ";

    for (auto item: *repo->getItems())
        cout<<item<<" ";
    cout<<endl;

    Repository<int>* repo2 = (new Repository<int>())->insert(10)->insert(20)->insert(5)->insert(40)->insert(4);

    //opción 2: pasar función lambda
    auto sortAsc = repo2->sortBy([](int a, int b){return a<b;});
    for (auto item: *sortAsc)
        cout<<item<<" ";
    cout<<endl;

    //opción 2: pasar función por parámetro
    auto sortDesc = repo2->sortBy(comparar);
    for (auto item: *sortDesc)
        cout<<item<<" ";
    cout<<endl;

    Repository<int>* repo3 = (new Repository<int>())->insert(10)->insert(20)->insert(5)->insert(40)->insert(4);

    auto sort3 = repo3->sortBy2([](int a, int b){return a>b;});
    for (auto item: *sort3)
        cout<<item<<" ";
    cout<<endl;

    Repository<int>* repo4 = (new Repository<int>())->insert(10)->insert(20)->insert(5)->insert(40)->insert(4);

    auto update = repo4->update([](int a){return a>1;}, [](int a){return a+1;});
    for (auto item: *update)
        cout<<item<<" ";
    cout<<endl;

    auto update2 = repo4->update2([](int a){return a>1;}, [](vector<int>* vector, int n){(*vector)[n] = (*vector)[n]+1;});
    for (auto item: *update2)
        cout<<item<<" ";
    cout<<endl;

    //      esta logica funcionaria si fuera un vector lleno de punteros a int...
    //auto update = repo4->update([](int a){return a>1;}, [](int *a){(*a)=(*a)+1;});

    return 0;
}


//que pais gano mas
//cuanto tuvo blabla
//functor
//lambda
//punteros a vector