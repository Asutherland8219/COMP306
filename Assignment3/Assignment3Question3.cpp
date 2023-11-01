//
// Created by asuth on 10/31/2023.
//
#include <fstream>
#include <string>
#include <sstream>
using  namespace std;

class TextFileReader {
private:
    std::string lines[100];
    int count;

public:
    // Default constructor
    TextFileReader() : count(0) {}

    // Constructor that takes a filename
    TextFileReader(std::string filename) : count(0) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line) && count < 100) {
            lines[count++] = line;
        }
    }

    // string array to string array buffer
    std::string contents() {
        std::stringstream str_stream;
        for (int i = 0; i < count; ++i) {
            str_stream << lines[i] << "\n";
        }
        return str_stream.str();
    }

    // Function to print the array to standard output
    void display() {
        for (int i = 0; i < count; ++i) {
            std::cout << "line " << (i+1) << ": " << lines[i] << std::endl;
        }
    }
};
