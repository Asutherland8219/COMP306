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
    TextFileReader(const std::string& filename) : count(0) {
        std::ifstream inputFile(filename);

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
    static void run(const std::string& filename) {
        TextFileReader reader(filename);

        // Display contents
        std::cout << "File Contents:\n" << reader.contents() << std::endl;

        // Display with line numbers
        std::cout << "File Contents with Line Numbers:\n";
        reader.display();
    }
};
