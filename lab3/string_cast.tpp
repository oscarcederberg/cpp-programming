#ifndef STRING_CAST_T
#define STRING_CAST_T

#include <string>
#include <sstream>
#include <stdexcept>

template <class T>
T string_cast(std::string string) {
    std::istringstream iss{string};
    T object;
    if (iss >> object && iss.rdbuf()->in_avail() == 0) {
        return object;
    } else {
        throw std::invalid_argument("Could not cast to type");
    }
}

#endif