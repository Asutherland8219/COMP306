//
// Created by asuth on 1/17/2024.
//

/*
 Logic Gates regarding the first chapter, handled in Checkpoint1. Includes modification to inventory and choices matrix
 */

#include <iostream>
#include "../../Inventory/Inventory.h"
#include "../../Character/Character.h"
#include "../../UniversalFunctions/user_input.cpp"
#include <sstream>

class ChapterOneGates {
private:
    bool bottle;
    bool bottle_inventory;
public:
    bool panic_breaker;
    // Carry over the originally created character to modify inventory
    bool panicChoice(int choice, const Character& custom_character) {
        switch (choice) {
            case 1:
                std::cout << "You grab the key, without a second thought, and rush towards the door. \n";
                std::cout << "Because of your size, you couldn't possibly fit through it, you bend down and peek through... \n";
                panic_breaker = true;
                break;
            case 2:
                std::cout << "You start to get dizzy. Thinking to yourself `Is this what a panic attack feels like`.\n";
                std::cout << "Because of the dizzyness, you decide to sit down. \n";
                std::cout << "On the way down you lose your balance and drop to the floor...\n";
                std::cout << "THUNK! \n The whole building shakes when you sit on the floor.\n";
                std::cout << "Slowly, you regain your orientation and take a few deep breaths...";
                break;
            case 3:
                std::cout << "Looking around again, trying to find something useful you catch a glimpse of the bottle from earlier. \n";
                std::cout << "You grab it and tip it up into your mouth... unfortunately nothing comes out \n";
                std::cout << "A thought pops into your head, perhaps this bottle could be useful later... \n";
                while (!bottle) {
                    std::cout << "What do you want to do with the bottle? \n";
                    std::cout << "1. Add the bottle to your inventory. \n";
                    std::cout << "2. Discard the bottle. \n";

                    auto input_bottle = getUserInput(custom_character);
                    std::istringstream iss(input_bottle);

                    int bottle_choice;
                    if (iss >> bottle_choice) { // Attempt to read an integer from the input
                        ChapterOneGates::bottle = inventoryBottleChoice(bottle_choice, custom_character);
                        panicChoice(1, custom_character);
                    }

                }
                break;
        }
        return panic_breaker;
    }
    bool inventoryBottleChoice(int bottle_choice, const Character& custom_character) {
        Item empty_bottle("Empty Bottle", "An empty bottle; previously a shrinking potion", 1);
        switch(bottle_choice) {
            case 1:
                std::cout << "You add the bottle to your inventory. \n";
                custom_character.addItemToInventory(empty_bottle);
                break;
            case 2:
                std::cout << "Meh. Just a bottle. You throw it away. \n";
        }
        bottle_inventory = true;
        return bottle_inventory;
    }
};

