#include <iostream>

template <typename T>
class Node{
private:
    T value;
    Node* next;
public:
    Node(T value, Node *next) : value(value), next(next) {}

    T getValue() const {
        return value;
    }

    void setValue(T value) {
        Node::value = value;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }
};

template <typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int _size;
public:
    LinkedList(): head {nullptr}, tail {nullptr}, _size {0} {};
    ~LinkedList() {
        Node<T>* next;
        for (Node<T>* p = head; p != nullptr; p=next){
            next = p->getNext();
            delete p;
        }
    }
    int size() const {return size;}
    void push_back (T value){
        Node<T>* temp = new Node<T>{value, nullptr};
        if (tail != nullptr)
            tail->setNext(temp);
        else
            head = temp;
        tail = temp;
        _size++;
    }
    void print(){
        Node<T>* p = head;
        while (p != nullptr){
            std::cout<<p->getValue()<<std::endl;
            p = p -> getNext();
        }
    }
};

int main() {
    LinkedList <std::string> * stringList = new LinkedList <std::string> ();
    stringList->push_back("Uno");
    stringList->push_back("Dos");
    stringList->push_back("Tres");
    stringList->print();
    return 0;
}