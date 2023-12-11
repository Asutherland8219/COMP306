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
