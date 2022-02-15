#include <string>
#include <sstream>
#include <stdexcept>

template <class T>
T string_cast(std::string string) {
    std::istringstream iss{string};
    T object;
    if (iss >> object) {
        return object;
    } else {
        throw std::invalid_argument("Could not cast to type");
    }
}