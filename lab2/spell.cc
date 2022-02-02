#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include "dictionary.h"

void check_word(const std::string& word, const Dictionary& dict)
{
    if (dict.contains(word)) {
        std::cout << "Correct." << std::endl;
    } else {
        std::vector<std::string> suggestions = dict.get_suggestions(word);
        
        if (suggestions.empty()) {
            std::cout << "Wrong, no suggestions." << std::endl;
        } else {
            std::cout << "Wrong. Suggestions:" << std::endl;
            for (const auto& w : suggestions) {
                std::cout << "    " << w << std::endl;
            }
        }
    }
}
int main() {
	Dictionary dict{};
	std::string word;
	while (std::cin >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
        check_word(word, dict);
	}
    return 0;
}
