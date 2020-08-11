//
// Created by Macarena Oyague on 2019-04-03.
//

#include "LinkedList.h"
#include <cassert>


bool LinkedList::empty(){
    return head==nullptr;
}

int LinkedList::size(){
    int count=0;
    if (empty()) return 0;
    Node* actual=head;
    do{
        count++;
        actual=actual->next;
    } while(actual != nullptr);
}

Node* LinkedList::get_head(){
    return head;
}

Node* LinkedList::get_tail(){
    return tail;
}

void LinkedList::print(){

}

void LinkedList::add_head(int value){
    Node*temp=new Node(value);
    if(empty()){
        tail=temp;
        head=temp;
    } else{
        temp->next=head;
        //(*temp).next
        head=temp;
    }
}

void LinkedList::add_tail(int value){
    Node*temp=new Node(value);
    if (empty()){
        tail=temp;
        head=temp;
    } else {
        temp->next=temp;
        tail=temp;
    }
}

void LinkedList::remove_head(){

}

void LinkedList::remove_tail(){

}