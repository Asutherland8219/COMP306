//
// Created by alex on 27/08/23.
//
#include <iostream>
#include <fstream>
using namespace std;

void wordCount(std::ifstream& inputFile) {
        // A function that counts the number of words in a file
        std::string word;
        int num_word = 0;
        while (inputFile >> word) {
            num_word++;
        }
        std::cout << "Word count: " << num_word << std::endl;

    };









