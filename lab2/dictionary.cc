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
	std::string parsedWord;
	size_t wordLength;
	std::string parsedTrigram;
	size_t trigramsCount;

	while (infile >> parsedWord) {
		wordLength = parsedWord.length();
		if(wordLength < DICTIONARY_MAX_WORD_LENGTH){
			std::vector<std::string> parsedTrigrams{};
			
			infile >> trigramsCount;
			for (size_t i = 0; i < trigramsCount; i++) {
				infile >> parsedTrigram;
				
				parsedTrigrams.push_back(parsedTrigram);
			}

			Word word{parsedWord, parsedTrigrams};
			words[wordLength].push_back(word);
			s_words.insert(parsedWord);
		}
	}
}

bool Dictionary::contains(const std::string& word) const {
	return s_words.count(word);	
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
