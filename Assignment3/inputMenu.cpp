/*
 Title: inputMenu.cpp
 Description: Input menu. Used to handle logic for Questions 1 through 3.
 Date: January 28th, 2024
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Cleaner and better handling of user inputs in Questions 1 through 3

 Compile (assuming Cygwin is running): g++ -o Assignment3 inputMenu.cpp
 Execution (assuming Cygwin is running): ./inputMenu.exe

 Classes (functions):
	- Class inputMenu()

    - Functions:
        - setPath(path)
            - Sets the main path for where the file is located
        - getPath()
            - Getter for the path
        - selectionMenu()
            - The main menu function, outputs what the options are and reads the user input.
            - Accepts 1 through 3 and the x input to exit
        - userTextInput(selection)
            - Takes the users input value, feeds into a switch statement that runs the matching function

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
        while (true) {
            std::cout
                    << "Please enter the name of the file you would like to open (make sure to include the extension): ";
            std::cin >> fileName;

            // break pattern
            if(std::tolower(fileName[0]) == 'x') {
                break;
            }

            if (checkType(fileName)) {
                // append to the path
                std::filesystem::path filePath = std::filesystem::current_path() / "Assignment3" / fileName;

                // Check if the file exists
                if (!std::filesystem::exists(filePath)) {
                    std::cout << "Error: The file '" << fileName << "' does not exist." << std::endl;
                } else {
                    setPath(filePath);
                    selectionMenu();
                }
            }
        }
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
                    std::cout << "Alternatively, press x to exit the program. \n";
            }
        } catch (const std::exception &except) {
            std::cerr << "Error: " << except.what() << std::endl;
        }

        // reset to the top of the file
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);


    }
};
