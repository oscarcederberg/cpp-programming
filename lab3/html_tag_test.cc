#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>

#include "html_tag.h"

void run_test(std::string input, std::string answer);

int main() {
    std::cout << "Running tests..." << std::endl;
    run_test("test/html_tag/tag", "test/html_tag/tag.ans");
    run_test("test/html_tag/char", "test/html_tag/char.ans");
    run_test("test/html_tag/full", "test/html_tag/full.ans");
}

void run_test(std::string input, std::string expected) {
    std::ifstream testFile{input};
    std::ifstream ansFile{expected};
    std::ostringstream testStream{};
    std::ostringstream ansStream{};

    TagRemover tagRemover{testFile};
    tagRemover.print(testStream);
    ansStream << ansFile.rdbuf();

    std::string testString = testStream.str();
    std::string ansString = ansStream.str();
    std::cout << input << ": ";
    if (testString == ansString) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }

    std::ofstream output{input.append(".out")};
    output << testString;
}