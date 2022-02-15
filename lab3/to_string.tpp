#ifndef TO_STRING_T
#define TO_STRING_T

#include <string>
#include <sstream>

template <class T>
std::string to_string(T object) {
    std::ostringstream oss{};
    oss << object;
    return oss.str();
}

#endif