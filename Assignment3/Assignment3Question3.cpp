#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class textFileReader {
private:
    string lines[100];
    int count;

public:
    // Default constructor
    textFileReader() : count(0) {}

    // Constructor that takes an ifstream object
    explicit textFileReader(ifstream& file) : count(0) {
        string line;
        while (getline(file, line) && count < 100) {
            lines[count++] = line;
        }
    }

    // Function to convert the array of Strings into a single StringBuffer
    string contents() {
        stringstream str_stream;
        for (int i = 0; i < count; ++i) {
            str_stream << lines[i] << "\n";
        }
        return str_stream.str();
    }

    // Function to print the array to standard output
    void display() {
        for (int i = 0; i < count; ++i) {
            cout << "line " << (i+1) << ": " << lines[i] << endl;
        }
    }
};
