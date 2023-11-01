//
// Created by asuth on 10/31/2023.
//
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

void printLineByLine(std::ifstream& inputFile) {
    std::string txt_line;

    while (std::getline(inputFile, txt_line)) {
        // print the line
        char userInput;
        std::cin.get(userInput);

        if (userInput == '\n') {
            std::cout << txt_line << std::endl;
        }
        else if (userInput == 'x' || userInput == 'X') {
            return; // Exit the function
        }
        else {
            std::cout << "Please press enter to continue or enter x to exit." << std::endl;
            std::cin.ignore();
        }
    }
}