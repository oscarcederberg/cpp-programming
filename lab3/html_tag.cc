#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

#include "html_tag.h"

const std::vector<std::pair<std::string, std::string>> HtmlTag::encoded_chars = {{"&lt;", "<"}, {"&gt;", ">"}, {"&nbsp;", " "}, {"&amp;", "&"}};

TagRemover::TagRemover(std::istream& in) {
    formatted_string = std::string{std::istreambuf_iterator<char>(in), {}};
    
    size_t start_pos = formatted_string.find('<');
    size_t end_pos = formatted_string.find('>');
    while (start_pos != std::string::npos && end_pos != std::string::npos) {
        formatted_string.erase(start_pos, end_pos - start_pos + 1); 
        start_pos = formatted_string.find('<');
        end_pos = formatted_string.find('>');
    }

    std::for_each(HtmlTag::encoded_chars.begin(), HtmlTag::encoded_chars.end(),
        [this](std::pair<std::string, std::string> pair){
            std::string encoded = pair.first;
            std::string decoded = pair.second;

            size_t start_pos = formatted_string.find(encoded);
            while (start_pos != std::string::npos) {
                formatted_string.replace(start_pos, encoded.length(), decoded);
                start_pos = formatted_string.find(encoded);
            }
        });
}

void TagRemover::print(std::ostream& out) const {
    out << formatted_string;
}