#ifndef HTML_TAG_H
#define HTML_TAG_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>

namespace HtmlTag {
    extern const std::vector<std::pair<std::string, std::string>> encoded_chars;
}

class TagRemover{
public:
    TagRemover(std::istream& in);
    void print(std::ostream& out) const;
private:
    std::string formatted_string;
};

#endif