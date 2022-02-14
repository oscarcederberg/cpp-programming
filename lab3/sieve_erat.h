#ifndef SIEVE_ERAT_H
#define SIEVE_ERAT_H

#include <string>
#include <vector>

class SieveOfErat {
public:
    SieveOfErat(int number);
    std::vector<int> get_primes() const;
    int get_larget_prime() const;
private:
    std::vector<int> primes;
};

#endif