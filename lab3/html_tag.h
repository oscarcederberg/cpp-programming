#ifndef HTML_TAG_H
#define HTML_TAG_H

#include <string>
#include <iostream>

class TagRemover{
public:
    TagRemover(std::istream& in);
    void print(std::ostream& out) const;
private:
    std::string formatted_string;
};

#endif