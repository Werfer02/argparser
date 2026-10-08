#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include "argparser.hpp"

int main(int argc, char** argv){
    argparser::Args args = argparser::parseArgv(argc, argv);

    std::cout << "single dash (key, value) args: \n";
    for(auto entry : args.singleDashArgs){
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    std::cout << "double dash args: \n";
    for(auto s : args.doubleDashArgs){
        std::cout << s << "\n";
    }

    std::cout << "no dash args: \n";
    for(auto s : args.noDashArgs){
        std::cout << s << "\n";
    }
}