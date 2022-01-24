#include"coding.h"

#include<iostream>
#include<fstream>
#include<string>

using std::string;

int main(int argc, char* argv[]){
    string filename;
    if(argc == 1){
        std::cout << "enter filename." << std::endl;
        std::cin >> filename;
    }else{
        filename = static_cast<string>(argv[1]);
    }

    std::ifstream ifile(filename);
    std::ofstream ofile(filename.substr(0, filename.find_last_of(".")) + ".dec");

    char c;
    while(ifile.get(c)){
        ofile.put(decode(c));
    }

    ifile.close();
    ofile.close();
}