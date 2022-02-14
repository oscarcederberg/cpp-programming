#include <vector>
#include <iostream>

#include "sieve_erat.h"

void run_test(int length, int largest, std::vector<int> primes);

int main() {
    run_test(5, 5, {2, 3, 5});
    run_test(35, 31, {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});
    run_test(100, 97, {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97});
}

void run_test(int length, int largest, std::vector<int> primes) {
    SieveOfErat sieve{length};

    std::cout << "Largest of length " << length << ": ";
    if (sieve.get_larget_prime() == largest) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }

    std::cout << "Primes of length " << length << ": ";
    if (sieve.get_primes() == primes) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
}