#define CATCH_CONFIG_MAIN

#ifdef CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "test_case.cpp"
#else
#include <iostream>
#include <functional>
#include "repository.cpp"
#include "product.cpp"
#include <string>
#include <mutex>
#include <vector>
using namespace std;


std::mutex print_mutex;

template <class T>
void safe_print(T to_print){
    std::lock_guard<std::mutex> lock(print_mutex);
    cout<<to_print<<endl;
}


int main() {

}
#endif



