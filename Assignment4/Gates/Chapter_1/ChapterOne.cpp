//
// Created by asuth on 1/17/2024.
//

/*
 Logic Gates regarding the first chapter, handled in Checkpoint1. Includes modification to inventory and choices matrix
 */

#include <iostream>
#include "../../Inventory/Inventory.h"
#include "../../Character/Character.h"
#include <sstream>

class ChapterOneGates {
private:
    bool bottle;
    bool bottle_inventory;
public:
    bool panic_breaker;
    bool rabbit_breaker;
    // Carry over the originally created character to modify inventory
    bool panicChoice(int panic_choice, const Character& custom_character) {
        switch (panic_choice) {
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
                    if (iss >> bottle_choice) {
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
    bool rabbitChoice(int rabbit_choice, const Character& custom_character) {
        switch (rabbit_choice) {
            case 1:
                std::cout << "You watch as the rabbit goes by, too nervous to say anything...\n"
                             "You're head is killing you. You decide to lay down and close your eyes...\n \n";

                std::cout << "Narrator: The character waits and waits but no one else ever comes by. Eventually, thirst and "
                             "starvation takes over. After a week, the character has moved on. \n"
                             "\n"
                             "** Returning to the previous checkpoint ** \n";
                rabbit_breaker = false;
                break;
            case 2:
                std::cout << "The rabbit slows down and turns to face you, tilting it's head with an inquisitive look \n";
                break;
            case 3:
                std::cout << "The rabbit jumps and lets out a yelp, indicating that you have startled the creature \n";
                break;
        }
        return rabbit_breaker;
    }

};

