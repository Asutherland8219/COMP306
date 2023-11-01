//
// Created by asuth on 11/1/2023.
//
#include "Assignment3Question1.cpp"
#include "Assignment3Question2.cpp"
#include "Assignment3Question3.cpp"
#include "checkType.cpp"


class inputMenu {
public:
    // A function that will be used to read in the file text and output it


    // let the user input the path of the file they want to open
    std::string fileName;

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

            std::ifstream inputFile(filePath); // create the stream object

            if (!inputFile.is_open()) {
                std::cout << "Error. Could not open the file entered." << endl;

            } else {
                std::cout << "File opened." << endl;
                selectionMenu(inputFile);
            }
        }
    };

    void selectionMenu(std::ifstream &inputFile) {
        // a menu to select what function you want to execute
        bool running = true;

        while (running) {
            char selection;
            std::cout << "You have entered the following path or filename: " << fileName << std::endl;
            std::cout
                    << "What function would you like to execute in regards to this file? Please make a selection from the list below: "
                    << std::endl;
            std::cout << "\t 1. Count\n";
            std::cout << "\t 2. Print Line By Line\n";
            std::cout << "\t 3. Text Reader \n";
            std::cout << "\t 4. Text Reader Demo\n";
            std::cout << "\t x. Exit\n";

            std::cin >> selection;
            std::cout << "Selected: " << selection << std::endl;

            if (selection == 'x' || selection == 'X') {
                running = false;
                std::cout << "\nThank you. Good bye. \n";
                break;
            } else {
                running = false;
                userTextInput(selection, inputFile);
                running = true;
            }
        }
    }

    void userTextInput(char selection, std::ifstream &inputFile) {
        switch (selection) {
            case '1':
                // Count
                wordCount(inputFile);
                break;
            case '2':
                // Print Line By Line imported from header
                printLineByLine(inputFile);
                break;
            case '3':
                // Text reader
                textFileReader();
                break;
//                case '4':
//                    // Text reader demo
////                    ReadFileDemo(inputFile);
//                    break;
            default:
                std::cout << "Invalid selection. Please select an item from the options listed. \n";
        }
    }
};

