#define CATCH_CONFIG_MAIN

#ifdef CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "test_case.cpp"

#else
#include <iostream>
#include <functional>
#include <string>
#include <mutex>
#include "calc.cpp"

using namespace std;

int main() {
    Calc<float> * calc = new Calc<float>("Input.txt",4,0.5);
    delete calc;

}
#endif



