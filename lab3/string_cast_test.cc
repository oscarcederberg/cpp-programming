#include <string>
#include <iostream>

#include "string_cast.h"

template <class T>
void run_test(std::string string, T expected);

int main() {
    run_test("123", 123);
    run_test("1.23", 1.23);
}

template<class T>
void run_test(std::string string, T expected) {
    bool passed = true;
    T actual;
    try {
        actual = string_cast<T>(string);
    } catch(const std::invalid_argument& e) {
        passed = false;
    }
    
    std::cout << string << ": ";
    if (passed && actual == expected) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
}