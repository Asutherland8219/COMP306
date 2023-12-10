//
// Created by asuth on 10/31/2023.
//
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

void printLineByLine(std::ifstream& inputFile) {
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);
    std::string txt_line;

    while (std::getline(inputFile, txt_line)) {
        // print the line
        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput.empty() || userInput == "x" || userInput == "X") {
            std::cout << txt_line << std::endl;
        } else {
            std::cout << "Please press Enter to continue or enter x to exit." << std::endl;
        }
    }

}