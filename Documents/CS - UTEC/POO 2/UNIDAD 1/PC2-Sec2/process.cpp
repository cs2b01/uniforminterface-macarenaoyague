//
// Created by User on 25/09/2019.
//
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Process{
protected:
    string name;
    int duration;
public:

    Process(const string &name) : name(name) {}

    virtual bool run()=0;

    virtual ~Process() {}
};

using namespace std;

class SynProcess: public Process{
public:

    SynProcess(const string &name) : Process(name) {}

    bool run() override{
        srand (time(nullptr));

        do{
            duration = rand()%100;
        }while(duration < 10 or duration >90);

        cout << "Ejemplo 1 \nSync Process " << name << endl;
        cout << "-\t Duration: " << duration << endl;

        if(duration < 80){
            cout<<"-\t Result: Success";
            return true;
        }
        cout << "-\t Result: Failed";
        return false;
    }

};

class AsyncProcess: public Process{
private:
    string callbackClient;
public:

    AsyncProcess(const string &name, const string &callbackClient) : Process(name), callbackClient(callbackClient) {}

    bool run() override{
        srand (time(nullptr));
        cout << "Ejemplo 1 \nAsync Process " << name << endl;
        for(int i = 0; i<10; i++) {

            do {
                duration = rand() % 1000;
            } while (duration < 100);

            cout << "Attempt " << i +1<< endl;
            cout << "-\t Duration: " << duration << endl;

            if (duration % 2 != 0) {
                cout << "-\t Result: Success\n";
                cout << "-\t Client: " << callbackClient << endl;
                return true;
            }
            else {
                cout << "-\t Result: Fail\n";
                cout << "-\t Client: " << callbackClient << endl;
            }
        }
        return false;

    }
};

template <class T, int N>
class Queue{
private:
    T** cola;
public:

    Queue() {
        cola=new T*[N];
    }

    Queue(T **cola) : cola(cola) {}

    void enqueue(T *elemento){
        T *temp = cola[0];
        T *temp2;
        cola[0]=&elemento;
        for(int i=1; i<N; i++)
        {
            if(i % 2 != 0) {
                temp2 = cola[i];
                cola[i] = temp;
            }

            if(i % 2 == 0){
                temp = cola[i];
                cola[i] = temp2;
            }
        }
    }

    T *dequeue(){
        T *elemento=cola[0];
        cola[0]=0;
        return elemento;
    }

    bool isEmpty(){
        for (int i=0; i<N; i++)
            if (cola[i]!=0)
                return false;
        return true;
    }

    bool isFull(){
        if (isEmpty()==false)
            return true;
        else
            return false;
    }
};
