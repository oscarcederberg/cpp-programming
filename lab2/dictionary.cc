#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "word.h"
#include "dictionary.h"

Dictionary::Dictionary() {
}

bool Dictionary::contains(const std::string& word) const {
	return true;
}

void add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word){

}

void rank_suggestions(std::vector<std::string>& suggestions, const std::string& word){

}

void trim_suggestions(std::vector<std::string>& suggestions){

}

std::vector<std::string> Dictionary::get_suggestions(const std::string& word) const {
	std::vector<std::string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}
