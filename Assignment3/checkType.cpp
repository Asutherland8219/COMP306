//
// Created by asuth on 11/1/2023.
//

#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;



bool checkType(std::string fileName) {
    // we only want text files so lets check to make sure the suffix of the file path or the file name
    std::filesystem::path temp_path = fileName;
    if (temp_path.extension() != ".txt") {
        std::cout << "Whoops, wrong file format. \n Please enter a supported text file (.txt). " << std::endl;
        std::cout << "Alternatively, press x to exit. \n";
        return false;
    };

    return true;

};
