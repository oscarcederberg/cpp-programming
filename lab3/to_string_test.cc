#include <string>
#include <iostream>

#include "to_string.h"

template<class T>
void run_test(T object, std::string expected);

int main() {
    double d = 1.234;
    run_test(d, "1.234");
}

template<class T>
void run_test(T object, std::string expected) {
    std::string actual = to_string(object);

    std::cout << object << ": ";
    if (actual == expected) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
}