/*
 Title: Assignment3Question3.cpp
 Description: Text File Reader and Text File Reader Demo; reads the file and outputs each line with a line number
 Date: January 28th, 2024
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Output the previously entered input file, all at once while printing each line with the line number beside it.

 Compile (assuming Cygwin is running): g++ -o Assignment3 Assignment3Question3.cpp
 Execution (assuming Cygwin is running): ./Assignment3Question3.exe

 Classes (functions):
	- Classes
        TextFileReader(inputFile) - The main constructor, reads in the ifstream input file,
        inits a counter to count lines

        TextFileReaderDemo() - Uses TextFileReader object to output the data read in

    - Function
        contents() - For loop that streams the string line, output the standard contents without line number

        display() - For loop that displays the lines in the format of line number

        run(inputFile) - Run's the contents and the display function. Demonstrating functionality.

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
#include <sstream>
#include <string>

class TextFileReader {
private:
    std::string lines[100];
    int count;

public:
    // Default constructor
    TextFileReader() : count(0) {}

    // Constructor with a filename argument
    TextFileReader(std::ifstream& inputFile) : count(0) {
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        std::string line;
        while (getline(inputFile, line) && count < 100) {
            lines[count++] = line;
        }

        inputFile.close();
    }

    std::string contents() const {
        std::stringstream str_stream;
        for (int i = 0; i < count; ++i) {
            str_stream << lines[i] << "\n";
        }
        return str_stream.str();
    }

    void display() const {
        for (int i = 0; i < count; ++i) {
            std::cout << "line " << (i + 1) << ": " << lines[i] << std::endl;
        }
    }
};

class TextFileReaderDemo {
public:
    static void run(std::ifstream& inputFile) {
        TextFileReader reader(inputFile);

        // Display contents
        std::cout << "File Contents:\n" << reader.contents() << std::endl;

        // Display with line numbers
        std::cout << "File Contents with Line Numbers:\n";
        reader.display();
        std::cout << std::endl;
    }
};
