//
// Created by asuth on 11/1/2023.
//
#include <utility>

#include "Assignment3Question1.cpp"
#include "Assignment3Question2.cpp"
#include "Assignment3Question3.cpp"
#include "checkType.cpp"


class inputMenu {
private:
    std::filesystem::path main_path;
public:
    // A function that will be used to read in the file text and output it
    // let the user input the path of the file they want to open
    std::string fileName;
    std::ifstream inputFile; // make sure to make the object public so it can be accessed in other functions

    inputMenu() {
        std::cout
                << "Please enter the name of the file you would like to open (make sure to include the extension): ";
        std::cin >> fileName;

        if (checkType(fileName)) {
            // append to the path
            std::filesystem::path filePath = std::filesystem::current_path() / "Assignment3" / fileName;

            // Check if the file exists
            if (!std::filesystem::exists(filePath)) {
                std::cout << "Error: The file '" << fileName << "' does not exist." << std::endl;
                return;
            }
            else {
                setPath(filePath);
                selectionMenu();
            }
        }
    };

    string getFileName() const {
        // get the file name
        return fileName;
    };

    void setPath(std::filesystem::path path) {
        main_path = path;
    }

    std::filesystem::path getPath() {
        return main_path;
    };

    void selectionMenu() {
        bool running = true;

        while (running) {
            char selection;
            std::cout << "You have entered the following path or filename: " << fileName << std::endl;
            std::cout<< "What function would you like to execute in regards to this file? Please make a selection from the list below: " << std::endl;
            std::cout << "\t 1. Count\n";
            std::cout << "\t 2. Print Line By Line\n";
            std::cout << "\t 3. Text Reader Demo\n";
            std::cout << "\t x. Exit\n";

            std::cin >> selection;
            std::cout << "Selected: " << selection << std::endl;

            if (selection == 'x' || selection == 'X') {
                running = false;
                std::cout << "\nThank you. Goodbye.\n";
            } else {
                userTextInput(selection);
            }
        }
    }

    void userTextInput(char selection) {
        try {
            switch (selection) {
                case '1':
                    // reset to the top of the file
                    inputFile.clear();
                    inputFile.seekg(0, std::ios::beg);
                    // Count
                    inputFile.open(getPath()); // open the stream object
                    if (!inputFile.is_open()) {
                        throw std::invalid_argument("Error: File is not open.\n");
                    }
                    wordCount(inputFile);
                    break;
                case '2':
                    // reset to the top of the file
                    inputFile.clear();
                    inputFile.seekg(0, std::ios::beg);
                    // Print Line By Line imported from header
                    inputFile.open(getPath()); // open the stream object
                    if (!inputFile.is_open()) {
                        throw std::invalid_argument("Error: File is not open.\n");
                    }
                    printLineByLine(inputFile);
                    break;
                case '3':
                    // reset to the top of the file
                    inputFile.clear();
                    inputFile.seekg(0, std::ios::beg);
                    inputFile.open(getPath()); // open the stream object
                    TextFileReaderDemo::run(inputFile);
                    break;
                default:
                    std::cout << "Invalid selection. Please select an item from the options listed. \n";
            }
        } catch (const std::exception &except) {
            std::cerr << "Error: " << except.what() << std::endl;
        }

        // reset to the top of the file
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);


    }
};
