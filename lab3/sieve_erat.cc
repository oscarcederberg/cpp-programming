#include <string>
#include <vector>
#include <algorithm>

#include "sieve_erat.h"

SieveOfErat::SieveOfErat(size_t count) {
    if (count < 3) {
        std::string sieve(count, 'C');
    } else {
        std::string sieve(count, 'P');
        sieve.replace(0, 2, "CC");

        size_t current_prime = 2;
        while (current_prime != std::string::npos) {
            primes.push_back(current_prime);

            size_t multiple = 2;
            size_t non_prime = current_prime * multiple;
            while (non_prime < count) {
                sieve.replace(non_prime, 1, "C");
                multiple++;
                non_prime = current_prime * multiple;
            }

            current_prime = sieve.find("P", current_prime + 1);
        } 
    }
}

std::vector<int> SieveOfErat::get_primes() const {
    return primes;
}

int SieveOfErat::get_larget_prime() const {
    if (primes.size() > 0){
        return primes.back();
    } else {
        return 0;
    }
}