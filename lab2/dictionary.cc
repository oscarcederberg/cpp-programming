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
		if (wordLength <= DICTIONARY_MAX_WORD_LENGTH) {
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

std::vector<std::string> process_word_trigrams(const std::string& word) {
    std::vector<std::string> trigrams;
    int count = word.length();

    if (count == 3) {
        trigrams.push_back(word);
    } else if (count > 3) {
        for (size_t i = 0; i < word.length() - 2; i++) {
            trigrams.push_back(word.substr(i, 3));
        }
		std::sort(trigrams.begin(), trigrams.end());
    }

    return trigrams; 
}

void Dictionary::add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word) const {
	size_t wordLength = word.length();
    std::vector<std::string> trigrams = process_word_trigrams(word);

	for (auto wordWithTrigrams : words[wordLength]) {
		if (wordWithTrigrams.get_matches(trigrams) >= trigrams.size() / 2) {
			suggestions.push_back(wordWithTrigrams.get_word());
		}
	}
	if (wordLength > 1) {
		for (auto wordWithTrigrams : words[wordLength - 1]) {
			if (wordWithTrigrams.get_matches(trigrams) >= trigrams.size() / 2) {
				suggestions.push_back(wordWithTrigrams.get_word());
			}
		}
	}
	if (wordLength + 1 <= DICTIONARY_MAX_WORD_LENGTH) {
		for (auto wordWithTrigrams : words[wordLength + 1]) {
			if (wordWithTrigrams.get_matches(trigrams) >= trigrams.size() / 2) {
				suggestions.push_back(wordWithTrigrams.get_word());
			}
		}
	}
}

void Dictionary::rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const {
	std::vector<std::pair<int, std::string>> suggestions_distances{};

	int d[DICTIONARY_MAX_WORD_LENGTH + 1][DICTIONARY_MAX_WORD_LENGTH + 1];
	size_t i, j, m, n;
	for (auto suggestion : suggestions) {
		m = word.length();
		n = suggestion.length();

		for (i = 1; i < m; i++) {
			d[i][0] = i;
		} 
		for (j = 1; j < n; j++) {
			d[0][j] = j;
		}
		for (j = 1; j < n; j++) {
			for (i = 1; i < m; i++) {
				int cost = word.at(i) == suggestion.at(j) ? 0 : 1;

				d[i][j] = std::min({
					d[i-1][j] + 1,
					d[i][j-1] + 1,
					d[i-1][j-1] + cost
				});
			} 
		}

		suggestions_distances.push_back(std::make_pair(d[m][n], suggestion));
	}

	std::sort(suggestions_distances.begin(), suggestions_distances.end());
	std::copy(suggestions_distances.begin(), suggestions_distances.end(), suggestions.begin());
}

void Dictionary::trim_suggestions(std::vector<std::string>& suggestions) const {
	if(suggestions.size() > 5){
		suggestions.resize(5);
	}
}

std::vector<std::string> Dictionary::get_suggestions(const std::string& word) const {
	std::vector<std::string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}
