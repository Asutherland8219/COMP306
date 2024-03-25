//
// Created by Alex Sutherland on 2024-02-10.
//

/* Custom universal input, having a list of functions to help the user. These functions include :
 * List Inventory
 * List Quests
 * List available menu functions
 * Exit the program
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "../Character/Character.h"
#include "userInput.h"

bool isInt(const std::string &str) {
    std::istringstream iss(str);
    int temp;
    return iss >> temp && iss.eof();
}

std::string getUserInput(Character custom_character, bool input_break) {
    std::string input;

    while (true) {
        if (input_break) {
            std::cout << "Please press enter to continue...\n";
        }

        std::string line;
        std::getline(std::cin, line);

        if (!line.empty()) {
            input = line;

            if (isInt(input)) {
                int numericValue = std::stoi(input);
                return std::to_string(numericValue);
            }

            // Convert input to lowercase
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);

            // Remove newline character from the input
            input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());

            std::vector<std::string> validInputs = {"i", "q", "r", "x", "h", "help", "exit"};

            if (std::find(validInputs.begin(), validInputs.end(), input) == validInputs.end() and !input.empty()) {
                // If the input is not found in the list of valid inputs, handle the error
                std::cout << "Invalid selection. Please select one of the options in the menu above.\n";
                continue; // Skip to the next iteration of the loop
            }

            if (input == "i") {
                custom_character.listInventory();
                std::cout << "Press enter to return to your previous menu. \n";
            } else if (input == "q") {
                custom_character.getQuests();
                std::cout << "Press enter to return to your previous menu. \n";
            } else if (input == "exit" || input == "x") {
                std::cout << "Exiting program...\n";
                std::exit(0);
            } else if (input == "h" || input == "help") {
                std::cout << "Enter one of the following values for more information: \n"
                             "i | inventory : list the character's inventory. \n"
                             "q | quest : list the quests assigned to the character. \n"
                             "r | enter : return to the previous menu\n"
                             "x | exit : to exit the program \n";
            } else if (input == "r" or input.empty()) {
                // Return to the previous menu
                break;
            }
        } else {
            // If the input is empty (user pressed Enter), break out of the loop
            break;
        }
    }
    return input;
}
