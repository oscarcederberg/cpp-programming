template <class T>
std::string to_string(T object) {
    std::ostringstream oss{};
    oss << object;
    return oss.str();
}