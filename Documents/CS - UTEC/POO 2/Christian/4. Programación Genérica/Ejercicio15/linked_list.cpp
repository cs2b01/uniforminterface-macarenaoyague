//
// Created by econtreras on 11/05/2019.
//
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node{
private:
    T data;
    Node* next;
public:
    Node(T data):data(data){
        next = nullptr;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        Node::data = data;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

};

template <class T>
class LinkedList{
private:
    Node<T>* header;
public:
    LinkedList(){
        header = nullptr;
    }

    void pushBack(T data){
        Node<T>* newNode = new Node(data);
        if (header == nullptr)
            header = newNode;
        else
        {
            auto* temp = header;
            while(temp->getNext() != nullptr)
                temp = temp->getNext();
            temp->setNext(newNode);
        }
    }

    void printItems(){
        Node<T>* temp = header;
        while (temp != nullptr){
            cout<<temp->getData()<<endl;
            temp = temp->getNext();
        }
    }
};
