//
// Created by asuth on 1/17/2024.
//

#include <iostream>
#include "../../Inventory/Inventory.h"
#include "../../Character/Character.h"

class ChapterOneGates {
private:
    static bool bottle;
public:
    static bool panic_breaker;
    // Carry over the originally created character to modify inventory
    static bool panicChoice(int choice, const Character& custom_character) {
        switch (choice) {
            case 1:
                std::cout << "You grab the key, without a second thought, and rush towards the door. \n";
                std::cout << "Because of your size, you couldn't possibly fit through it, you bend down and peek through...";
                panic_breaker = true;
                break;
            case 2:
                std::cout << "You start to get dizzy. Thinking to yourself `Is this what a panic attack feels like`.\n";
                std::cout << "Because of the dizzyness, you sit down. \n";
                std::cout << "Losing your balance, you drop to the floor...\n";
                std::cout << "THUNK! The whole building shakes when you sit on the floor.\n";
                std::cout << "Slowly, you regain your orientation and take a few deep breaths...";
                break;
            case 3:
                std::cout << "Looking around again, trying to find something useful you catch a glimpse of the bottle from earlier. \n";
                std::cout << "You grab it and tip it up into your mouth... unfortunately nothing comes out \n";
                std::cout << "A thought pops into your head, perhaps this bottle could be useful later... \n";
                while (!bottle) {
                    std::cout << "What do you want to do with the bottle? \n";
                    int bottle_choice;
                    std::cin >> bottle_choice;
                    if (std::cin.fail()) {
                        throw std::invalid_argument("Invalid input. Please enter a number.");
                    }
                    else {
                        bottle = inventoryBottleChoice(bottle_choice, custom_character);
                    }

                }
                break;
        }
        return panic_breaker;
    }
    static bool inventoryBottleChoice(int bottle_choice, const Character& custom_character) {
        Item empty_bottle("Empty Bottle", "An empty bottle; previously a shrinking potion", 1);
        switch(bottle_choice) {
            case 1:
                std::cout << "You add the bottle to your inventory.";
                custom_character.addItemToInventory(empty_bottle);
                break;
            case 2:
                std::cout << "Meh. Just a bottle. You throw it away.";
                break;
        }
    }





};

