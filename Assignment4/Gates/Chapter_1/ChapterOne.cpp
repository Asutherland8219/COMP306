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
#include "../../UniversalFunctions/textFormatting.cpp"

class ChapterOneGates {
private:
    bool bottle;
    bool bottle_inventory;
public:
    bool panic_breaker;
    bool rabbit_breaker;
    bool fan_breaker;
    bool embankment_breaker;
    bool glove_breaker;
    bool house_breaker;
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
                std::cout << "The rabbit jumps and lets out a yelp, indicating that you have startled the creature, and scurries behind a rock."
                             "After a while, he slowly peeks out his head. \n";
                break;
        }
        return rabbit_breaker;
    }

    bool rabbitItemChoice(int rabbit_item_choice, const Character& custom_character) {
        Item fan("Paper Fan" , "A basic paper fan, used to stay cool during hot weather.", 2);
        Item gloves("Gloves", "White gloves. Meant for formal attire.", 3);

        switch (rabbit_item_choice) {
            case 1:
                std::cout << "You leave all the items as they don't seem to be of use";
                rabbit_breaker = false;
                break;
            case 2:
                std::cout << "You grab the gloves but they are too large to put on. \n";
                custom_character.addItemToInventory(gloves);
                break;
            case 3:
                std::cout << "You grab the fan, as it could come of use later. \n";
                custom_character.addItemToInventory(fan);
                break;
            case 4:
                std::cout << "You grab both items, adding them to your inventory. \n";
                custom_character.addItemToInventory(fan);
                custom_character.addItemToInventory(gloves);
                break;
        }
        return rabbit_breaker;
    }

    bool fanChoice(int fan_choice, const Character& custom_character) {
        Item fan(" Shrinking Paper Fan" , "A fan, that seemingly shrinks the user.", 1);

        switch (fan_choice) {
            case 1:
                std::cout << "You pickup the fan, and add it to your inventory. It could be of use later";
                custom_character.addItemToInventory(fan);
                break;
            case 2:
                std::cout << "You ignore the fan, thinking it could only be trouble later on. \n";
                break;
        }
        return fan_breaker;
    }

    bool embankmentChoice(int embankment_choice, const Character& custom_character) {
        switch (embankment_choice) {
            case 1:
                std::cout << "You try and speak to the animals... \n";
                textFormatter::printItalic("Hello little animals, do you prehaps speak like the rabbit? \n");
                std::cout << "They all just stare at you, probably thinking what is wrong with this person. \n";
                break;
            case 2:
                textFormatter::printItalic("Shoo animals! Get out of here! Shoo! Shoo! \n");
                std::cout << " They all stare at you, then slowly decide to go there separate ways \n";
                break;
            case 3:
                textFormatter::printItalic("Oh these animals seem harmless, perhaps they themselves are also stuck. \n");
                std::cout << "You leave them be, instead looking for something useful. \n";
                break;
        }
        return embankment_breaker;
    }

    bool gloveChoice(int glove_choice, Character custom_character) {
        Item* glove = custom_character.getItem("Gloves");
        switch (glove_choice) {
            case 1:
                textFormatter::printItalic("Hello Mr Rabbit, are these the gloves you are looking for? \n");
                custom_character.dropItem(glove->name);
                break;
            case 2:
                textFormatter::printItalic("I am sorry Mr. Rabbit! I have not seen your gloves! \n");
                glove_breaker = false;
                break;
            case 3:
                std::cout << "You wait to see if he even sees you; unlike your last encounter this time he sees you! \n";
                glove_breaker = false;
                break;
        }
        return glove_breaker;
    }

    bool houseChoice(int house_choice, Character custom_character) {
        switch (house_choice) {
            case 1:
                std::cout << "You walk up the stairs, seeing one door open and many others closed. You wander into the open door \n"
                             "and see a beautiful four post bed, and very lage wardrobe... \n"
                             "This must be the Duchess's room";
                break;
            case 2:
                std::cout << "You walk through the doorway, into a beautiful room with a lit fireplace. Above the fireplace is a stuffed bears head \n"
                             "All around the fire you see some small chairs with a coffee table in the middle. \n"
                             "Tucked away to the side, is a massive red throne style chair sitting in front of the biggest bookshelves you have ever seen \n";
                // add an option to peruse the bookshelves and take a book
                house_breaker = false;
                break;
            case 3:
                std::cout << "You slowly approach the door, and gently open it... \n"
                             "Inside, you smell a pot boiling, likely some sort of soup \n"
                             "You see a man wearing a chefs hat, the cook, and another woman dressed in very gaudy attire... \n"
                             "She is also quite raucous; directing some crass comments towards the cook.";
                house_breaker = false;
                break;
            case 4:
                std::cout << "You walk towards the door, and slowly open it. Looking out into a beautiful large garden, with a small table and chairs set up. \n"
                             "Every chair is empty, but food is on the table and tea looks to be served. \n"
                             "As you take a step out the door to investigate further, the rabbit jumps out in front of you!";
                break;
        }
        return house_breaker;
    }




};

