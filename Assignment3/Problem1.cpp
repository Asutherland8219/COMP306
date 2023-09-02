//
// Created by alex on 27/08/23.
//

#include <iostream>
#include <fstream>
#include <filesystem>

class File{
public:
    // A function that will be used to read in the file text and output it
    std::ifstream txtfile; // create the stream object

    // let the user input the path of the file they want to open
    std::string fileName;
    File() {
        std::cout << "Please enter the name of the file you would like to open (make sure to include the extension): ";
        std::cin >> fileName;
        if (CheckType()) {
            char selection;
            std:: cout << "You have entered the following path or filename: " << fileName << std::endl;
            std:: cin >> selection;
            selectionMenu(selection);





        }
    };

    void selectionMenu(char selection) {
        // a menu to select what function you want to execute
        bool running = true;
        void userInput(char);

        while (running) {
            std:: cout << "What function would you like to execute in regards to this file? Please make a selection from the list below: " << std::endl;
            std:: cout << "\t 1. Count\n";
            std:: cout << "\t 2. Print Line By Line\n";
            std:: cout << "\t 3. Text Reader \n";
            std:: cout << "\t 4. Text Reader Demo\n";
            std:: cout << "\t x. Exit\n";

            std:: cout << "Selected: " << selection << std::endl;

            if (selection == 'x' || selection == 'X') {
                running = false;
                std::cout << "\nThank you. Good bye. \n";
                break;
            } else {
                userTextInput(selection);
            }
    }
        }

    void userTextInput(char selection) {
        switch (selection) {

        }
    }
    void ReadFile() {
            // A function that will be used to read the file and then print the new output
        };
    void WriteFile() {
            // A function that will be used to write the file and then print the new output
        };
    void ReadWriteFile() {
            // A function that will be used to read the file, print the output, then write the file and print the new modified output
        };
    void Count() {
            // A function that counts the number of words in a file

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




