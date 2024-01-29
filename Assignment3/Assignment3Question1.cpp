/*
 Title: Assignment3Question1.cpp
 Description: Counter number of words in a user input file. Must be txt.
 Date: January 28th, 2024
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Count number of words in a user entered file.

 Compile (assuming Cygwin is running): g++ -o Assignment3 Assignment3Question1.cpp
 Execution (assuming Cygwin is running): ./Assignment3Question1.exe

 Classes (functions):
	- No actual classes, just one function
        - wordCount(inputFile)
            - accepts an ifstream inputfile

 Variables:
 	- string word : The word index
 	- int num_word : The word counter, incremented by each word counted
 	- std::ifstream inputFile : The ifstream object that is read in and counted

*/

/*
 TEST PLAN

 Normal case:
    ifstream inputFile = "excerpt.txt"
 	> wordCount(inputFile)
 	    Output: "Word Count: xxx"


 Bad Case
    Because this is a user input, there are a lot of potential issues for bad cases. However, this is handled externally, before this function is hit.
 	> Bad input will not reach the function.


 Discussion:
 	Program that counts words in an entered file. Must be a .txt file. No error handling as the function is called in a separate inputMenu function.
 	Program will not be run unless makes it through necessary checks.

*/

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









