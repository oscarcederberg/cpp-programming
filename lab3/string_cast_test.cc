#include <string>
#include <iostream>

#include "string_cast.h"

template <class T>
void run_test(std::string string, T expected, bool shouldFail);

int main() {
    run_test("123", 123, false);
    run_test("1.23", 1.23, false);
    run_test("1ab23", 123, true);
    run_test("1.23", 123, true);
}

template<class T>
void run_test(std::string string, T expected, bool shouldFail) {
    bool passed = true;
    T actual;
    try {
        actual = string_cast<T>(string);
    } catch(const std::invalid_argument& e) {
        passed = false;
    }
    
    std::cout << string << ": ";
    if (passed && !shouldFail && actual == expected) {
        std::cout << "passed" << std::endl;
    } else if (!passed && shouldFail){
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
}