#include <iostream>
#include "linked_list.cpp"

int main() {
    auto * stringLinkedList = new LinkedList<string>();
    stringLinkedList->pushBack("Juan");
    stringLinkedList->pushBack("Carlos");
    stringLinkedList->pushBack("Ximena");
    stringLinkedList->pushBack("Elizabeth");
    stringLinkedList->printItems();
    return 0;
}