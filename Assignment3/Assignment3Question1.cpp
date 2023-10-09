//
// Created by alex on 27/08/23.
//

#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

class File{
public:
    // A function that will be used to read in the file text and output it


    // let the user input the path of the file they want to open
    std::string fileName;
    File() {
        std::cout << "Please enter the name of the file you would like to open (make sure to include the extension): ";
        std::cin >> fileName;
        if (CheckType()) {
            // append to the path
            std::filesystem::path filePath = std::filesystem::current_path() /"Assignment3" / fileName;

            // Check if the file exists
            if (!std::filesystem::exists(filePath)) {
                std::cout << "Error: The file '" << fileName << "' does not exist." << std::endl;
                return;
            }

            std::ifstream inputFile(filePath); // create the stream object

            if (!inputFile.is_open()) {
                std::cout << "Error. Could not open the file entered." << endl;

            }

            else {
                std::cout << "File opened." << endl;
                selectionMenu(inputFile);
            }
        }
    };

    void selectionMenu(std::ifstream& inputFile) {
        // a menu to select what function you want to execute
        bool running = true;

        while (running) {
            char selection;
            std:: cout << "You have entered the following path or filename: " << fileName << std::endl;
            std:: cout << "What function would you like to execute in regards to this file? Please make a selection from the list below: " << std::endl;
            std:: cout << "\t 1. Count\n";
            std:: cout << "\t 2. Print Line By Line\n";
            std:: cout << "\t 3. Text Reader \n";
            std:: cout << "\t 4. Text Reader Demo\n";
            std:: cout << "\t x. Exit\n";

            std:: cin >> selection;
            std:: cout << "Selected: " << selection << std::endl;

            if (selection == 'x' || selection == 'X') {
                running = false;
                std::cout << "\nThank you. Good bye. \n";
                break;
            } else {
                userTextInput(selection, inputFile);
            }
    }
        }

    void userTextInput(char selection, std::ifstream& inputFile) {
        switch (selection) {
            case '1':
                // Count
                Count(inputFile);
                break;
            case '2':
                // Print Line By Line
                PrintLineByLine(inputFile);
                break;
            case '3':
                // Text reader
                ReadFile(inputFile);
                break;
            case '4':
                // Text reader demo
                ReadFileDemo(inputFile);
                break;
            default:
                std::cout << "Invalid selection. Please select an item from the options listed. \n";
        }
    }
    void ReadFile(std::ifstream& inputFile) {
            // A function that will be used to read the file and then print the new output
        };
    void ReadFileDemo(std::ifstream& inputFile) {
        // A function that will be used to write the file and then print the new output
    };
    void Count(std::ifstream& inputFile) {
        // A function that counts the number of words in a file
        std::string word;
        int num_word = 0;
        while (inputFile >> word) {
            num_word++;
        }
        std::cout << "Word count: " << num_word << std::endl;

    };
    void PrintLineByLine(std::ifstream& inputFile) {
        std::string txt_line;

        while (std::getline(inputFile, txt_line)) {
            // print the line
            char userInput;
            std::cin.get(userInput);

            if (userInput == '\n') {
                std::cout << txt_line << std::endl;
            }
            else if (userInput == 'x' || userInput == 'X') {
                return; // Exit the function
            }
            else {
                std::cout << "Please press enter to continue or enter x to exit." << std::endl;
                std::cin.ignore();
            }
        }
    }



    bool CheckType() {
        // we only want text files so lets check to make sure the suffix of the file path or the file name
        std::filesystem::path temp_path = fileName;
        if (temp_path.extension() != ".txt") {
            std::cout << "Whoops, wrong file format. Please enter a supported text file (.txt). " << std::endl;
            return false;
        };

        return true;

        };

    };




