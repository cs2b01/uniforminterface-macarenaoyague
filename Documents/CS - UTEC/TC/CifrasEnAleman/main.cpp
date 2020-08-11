#include <iostream>
using namespace std;
#include <vector>
#include "Gramatica.h"
#include "Parser.h"



int main() {
    Scanner scanner;
    scanner.setPalabraOriginal();
    scanner.doScan();

    Parser parser;
    parser.evaluateNumber(scanner);

    return 0;
}

//zwolf no funciona :(