//
// Created by alex on 27/08/23.
//

#include <iostream>
#include <fstream>

void ReadFile() {
// A function that will be used to read in the file text and output it
    std::ifstream txtfile; // create the stream object

    // let the user input the path of the file they want to open
    std::string fileName;
    std::cout << "Please enter the name of the file you would like to open (make sure to include the extension): "
    std::cin >> fileName;
    if ( CheckType(fileName) == true) {

    }
};


void WriteFile() {
// A function that will be used to write the file and then print the new output
};

void ReadWriteFile() {
// A function that will be used to read the file, print the output, then write the file and print the new modified output
};


bool CheckType(fileName) {
    // we only want text files so lets check to make sure the suffix of the file path or the file name

     if (fileName.rfind(".") == fileName.size() - 1 != True) {
         std::cout << "Whoops, wrong file format. Please enter a supported text file (.txt). " << endl;
         return false;
     };

     return true;


};



