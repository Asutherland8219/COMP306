/*
 Title: Assignment3Question2.cpp
 Description: Print line by line of user input file.
 Date: January 28th, 2024
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Output each line of the txt file, one at a time with a user input (enter)

 Compile (assuming Cygwin is running): g++ -o Assignment3 Assignment3Question2.cpp
 Execution (assuming Cygwin is running): ./Assignment3Question2.exe

 Classes (functions):

    - Functions:
        - printLineByLine(inputFile)
            - prints line by line based on user input, pressing enter to move on to the next line
            - Operates via a while loop, waiting for either enter or x to exit
            - Uses the std::getline() to loop through the file and get each line to output

 Variables:
 	- std::ifstream inputFile - the ifstream object to be read
 	- string txt_line - the single line that will be output
 	- string userInput - optional string, only read if the user inputs x to exit

*/

/*
 TEST PLAN

 Normal case:
    ifstream inputFile = "excerpt.txt"

    selectionMenu()
 	    Output:
            You have entered the following path or filename: excerpt.txt
            What function would you like to execute in regards to this file? Please make a selection from the list below:
                     1. Count
                     2. Print Line By Line
                     3. Text Reader Demo
                     x. Exit
        Input: 2
        Output:
            Selected: 2
            There was nothing so VERY remarkable in that; nor did Alice ...


 Bad Case
    Because this is a user input, there are a lot of potential issues for bad cases. If it reaches this far into the program,
    that is to hit the output line by line function, there is only one bad case.

    That is, the user presses something other than enter to continue or enter to exit.

    Output:
        f
        Please press Enter to continue or enter x to exit.


 Discussion:
    The print line by line function, handles an input previously given, then waits for the user to either hit enter to continue or x to
    exit the while loop.

*/

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