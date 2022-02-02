#include <string>
#include <algorithm>
#include <vector>

#include "word.h"

Word::Word(const std::string& w, const std::vector<std::string>& t) : word{w}, trigrams{t} {}

std::string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const std::vector<std::string>& t) const {
	unsigned int matches = 0;
	auto iter_trigrams = trigrams.begin();
	auto end_trigrams = trigrams.end();
	auto iter_t = t.begin();
	auto end_t = t.end();
	
	while (iter_trigrams != end_trigrams && 
		  iter_t != end_t) {
		int comparison = (*iter_trigrams).compare(*iter_t);

		if (comparison == 0) {
			matches++;
			iter_trigrams++;
			iter_t++;
		} else if (comparison < 0) {
			iter_trigrams++;
		} else {
			iter_t++;
		}
	}
	
	return matches; 
}
