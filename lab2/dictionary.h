#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <unordered_set>
#include <vector>

#include "word.h"

#define DICTIONARY_MAX_WORD_LENGTH 25

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	std::unordered_set<std::string> s_words{};
	std::vector<Word> words[DICTIONARY_MAX_WORD_LENGTH]{};
};

#endif
