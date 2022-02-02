#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "word.h"
#include "dictionary.h"

Dictionary::Dictionary() {
	std::ifstream infile{"./words.txt"};
	std::string word;
	std::string trigram;
	size_t trigramsCount;

	while (infile >> word) {
		words.insert(word);

		infile >> trigramsCount;
		for (size_t i = 0; i < trigramsCount; i++) {
			infile >> trigram;
			// TODO: Add trigrams to dictionary.
		}
	}
}

bool Dictionary::contains(const std::string& word) const {
	return words.find(word) != words.end();
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
