//
// Created by Alex Sutherland on 2024-02-10.
//

/* Custom universal input, having a list of functions to help the user. These functions include :
 * List Inventory
 * List Quests
 * List available menu functions
 * Exit the program
*/

#include "../Character/Character.h"
#include "../Inventory/Inventory.h"
#include "../Quests/Quest.h"
#include <vector>
#include <algorithm>

std::string getUserInput(Character custom_character) {
    std::string input;
    std::getline(std::cin, input);

    if (std::cin.fail()) {
        return input;
    }

    std::vector<std::string> validInputs = {"i", "q", "r", "x"};

    if (std::find(validInputs.begin(), validInputs.end(), input) == validInputs.end()) {
        // If the input is not found in the list of valid inputs, throw an exception
        throw std::invalid_argument("Invalid selection. Please select one of the options in the menu above.");
    }


    // Convert input to lowercase
    for (char &c: input) {
        c = std::tolower(c);
    }

    if (input == "i") {
        custom_character.listInventory();
        std::cout << "press enter to return to your previous menu. \n";
        return getUserInput(custom_character); // Recursively ask for input again
    } else if (input == "q") {
        custom_character.getQuests();
        return getUserInput(custom_character); // Recursively ask for input again
    } else if (input == "exit" or input == "x") {
        std::cout << "Exiting program..." << std::endl;
        std::exit(0); // Exit the program with a normal termination status
    } else if (input == "h" or input == "help") {
        std::cout << "Enter one of the following values for more information: \n"
                     "i | inventory : list the characters inventory. \n"
                     "q | quest : list the quests assigned to the character. \n"
                     "r | enter : return to the previous menu\n"
                     "x | exit : to exit the program \n";
        return getUserInput(custom_character); //
    }
        return input;
    }
