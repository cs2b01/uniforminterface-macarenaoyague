//
// Created by Macarena Oyague on 2019-04-03.
//

#ifndef S2_LINKEDLIST_H
#define S2_LINKEDLIST_H



struct Node{
    int value; //el valor
    Node* next; //lo que apunta al siguiente
    Node(int value): value{value}, next{nullptr}{}
};


class LinkedList {
    Node*head;
    Node*tail;
public:
    LinkedList(): head {nullptr}, tail{nullptr}{}
    bool empty();
    int size();
    Node* get_head();
    Node*get_tail();
    void print();
    void add_head(int);
    void add_tail(int);
    void remove_head();
    void remove_tail();

};


#endif //S2_LINKEDLIST_H




class LinkedList{

    Node* temp=new Node (10); //value
    if (empty())    //tail==head==null
    {
        tail = temp; //si es vacio, apuntara a ese nodo siendo el ultimo
        head = temp; //si es vacio, apuntara a ese nodo siendo el primero
    }else
    {
        temp->next=head; // next será el nodo anterior, el ultimo
        head=temp; //el primer nodo sera temp, osea el ultimo que se añadio
    }

private:
    Node*head;
    Node*tail;
};
