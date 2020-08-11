#include <iostream>
#include "list.cpp"
using namespace std;
int main() {
    // Test con String
    auto * stringList = new List<string,5>();
    stringList->pushBack("Ximena");
    stringList->pushBack("Mateo");
    stringList->pushBack("Josefina");
    stringList->pushBack("Carlos");
    stringList->pushBack("Jose");
    stringList->pushBack("Mateo");
    stringList->printItems();
    stringList->remove(stringList->find("Josefina"));
    stringList->insertAt("Juan",2);
    stringList->printItems();
    return 0;
}