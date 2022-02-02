#include<algorithm>
#include<fstream>
#include<vector>
#include<string>

std::vector<std::string> process_word_trigrams(std::string& word) {
    std::vector<std::string> trigrams;
    int count = word.length();

    if (count == 3) {
        trigrams.push_back(word);
    } else if (count > 3) {
        for (size_t i = 0; i < word.length() - 2; i++) {
            trigrams.push_back(word.substr(i, 3));
        }
    }

    return trigrams; 
}

int main() {
    std::ifstream infile{"/usr/share/dict/words"};
    std::ofstream outfile{"./words.txt"};
    std::string word;

    while (infile >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        std::vector<std::string> trigrams;
        trigrams = process_word_trigrams(word);
        sort(trigrams.begin(), trigrams.end());
        
        outfile << word << " " << trigrams.size();
        for (std::string trigram : trigrams) {
            outfile << " " << trigram;
        }
        outfile << std::endl;
    }
}