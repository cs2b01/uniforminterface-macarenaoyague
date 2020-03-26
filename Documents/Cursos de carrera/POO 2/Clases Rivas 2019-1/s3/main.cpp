#include <iostream>

#define SPANISH
#define DEBUG
#define UNIT_TEST
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#ifndef CATCH_CONFIG_MAIN
int main() {
#ifdef UNIT_TEST
    #include "Pruebas.h"
#endif

#ifdef SPANISH
    std::cout << "Hola Mundo!" << std::endl;
#elif
    std::cout << "Hello, World!" << std::endl;
#endif

    assert(factorial(1)==1);

    return 0;
}
#endif