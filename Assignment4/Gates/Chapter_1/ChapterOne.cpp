//
// Created by asuth on 1/17/2024.
//

/*
 Logic Gates regarding the first chapter, handled in Checkpoint1. Includes modification to inventory and choices matrix
 */

#include "ChapterOne.h"
bool ChapterOneGates::bottle;
bool ChapterOneGates::panic_breaker;
bool ChapterOneGates::house_breaker;
bool ChapterOneGates::glove_breaker;
bool ChapterOneGates::embankment_breaker;
bool ChapterOneGates::fan_breaker;
bool ChapterOneGates::rabbit_breaker;
bool ChapterOneGates::bottle_inventory;

    // Carry over the originally created character to modify inventory
    ;
    bool ChapterOneGates::panicChoice(int panic_choice, const Character& custom_character) {
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
                std::cout << "THUNK! \nThe whole building shakes when you sit on the floor.\n";
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

                    auto input_bottle = getUserInput(custom_character, false);
                    std::istringstream iss(input_bottle);

                    int bottle_choice;
                    if (iss >> bottle_choice) {
                        bottle = inventoryBottleChoice(bottle_choice, custom_character);
                        std::cout << "After looking around, you decide nothing else of use is around and go for the key. \n";
                        panicChoice(1, custom_character);
                    }

                }
                break;
        }
        return panic_breaker;
    }
    bool ChapterOneGates::inventoryBottleChoice(int bottle_choice, const Character& custom_character) {
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
    bool ChapterOneGates::rabbitChoice(int rabbit_choice, const Character& custom_character) {
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
                rabbit_breaker = true;
                break;
            case 3:
                std::cout << "The rabbit jumps and lets out a yelp, indicating that you have startled the creature, and scurries behind a rock."
                             "After a while, he slowly peeks out his head. \n";
                rabbit_breaker = true;
                break;
        }
        return rabbit_breaker;
    }

    bool ChapterOneGates::rabbitItemChoice(int rabbit_item_choice, const Character& custom_character) {
        Item fan("Paper Fan" , "A basic paper fan, used to stay cool during hot weather.", 2);
        Item gloves("Gloves", "White gloves. Meant for formal attire.", 3);

        switch (rabbit_item_choice) {
            case 1:
                std::cout << "You leave all the items as they don't seem to be of use \n";
                rabbit_breaker = false;
                break;
            case 2:
                std::cout << "You grab the gloves but they are too large to put on. \n";
                Character::addItemToInventory(gloves);
                break;
            case 3:
                std::cout << "You grab the fan, as it could come of use later. \n";
                Character::addItemToInventory(fan);
                break;
            case 4:
                std::cout << "You grab both items, adding them to your inventory. \n";
                Character::addItemToInventory(fan);
                Character::addItemToInventory(gloves);
                break;
        }
        return rabbit_breaker;
    }

    bool ChapterOneGates::fanChoice(int fan_choice, const Character& custom_character) {
        Item fan(" Shrinking Paper Fan" , "A fan, that seemingly shrinks the user.", 1);

        switch (fan_choice) {
            case 1:
                std::cout << "You pickup the fan, and add it to your inventory. It could be of use later \n";
                Character::addItemToInventory(fan);
                fan_breaker = true;
                break;
            case 2:
                std::cout << "You ignore the fan, thinking it could only be trouble later on. \n";
                fan_breaker = true;
                break;
        }
        return fan_breaker;
    }

    bool ChapterOneGates::embankmentChoice(int embankment_choice, const Character& custom_character) {
        switch (embankment_choice) {
            case 1:
                std::cout << "You try and speak to the animals... \n";
                custom_character.talk("Hello little animals, do you perhaps speak like the rabbit? \n");
                std::cout << "They all just stare at you, probably thinking what is wrong with this person. \n";
                embankment_breaker = true;
                break;
            case 2:
                custom_character.talk("Shoo animals! Get out of here! Shoo! Shoo! \n");
                std::cout << " They all stare at you, then slowly decide to go there separate ways \n";
                embankment_breaker = true;
                break;
            case 3:
                custom_character.talk("Oh these animals seem harmless, perhaps they themselves are also stuck. \n");
                std::cout << "You leave them be, instead looking for something useful. \n";
                embankment_breaker = true;
                break;
        }
        return embankment_breaker;
    }

    bool ChapterOneGates::gloveChoice(int glove_choice, Character custom_character) {
        Item glove = custom_character.inventory.getInventoryItem("Gloves");
        switch (glove_choice) {
            case 1:
                textFormatter::printItalic("Hello Mr Rabbit, are these the gloves you are looking for? \n");
                custom_character.dropItem(glove.name);
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

    bool ChapterOneGates::houseChoice(int house_choice, Character custom_character) {
        bool bookshelf_breaker;
        WhiteRabbit rabbit;
        switch (house_choice) {
            case 1:
                std::cout << "You walk up the stairs, seeing one door open and many others closed. You wander into the open door \n"
                             "and see a beautiful four post bed, and very lage wardrobe... \n"
                             "This must be the Duchess's room \n";
                std::cout << "You probably shouldn't be in here. You turn and leave. \n";
                break;
            case 2:
                std::cout << "You walk through the doorway, into a beautiful room with a lit fireplace. Above the fireplace is a stuffed bears head \n"
                             "All around the fire you see some small chairs with a coffee table in the middle. \n"
                             "Tucked away to the side, is a massive red throne style chair sitting in front of the biggest bookshelves you have ever seen \n";

                while (!bookshelf_breaker) {
                    std::cout << "You walk over to the shelves and peruse the titles:\n"
                                 "- The history of Wonderland.\n"
                                 "- Family Tree of the Queen of Hearts.\n"
                                 "- The rat, the bat, and the fat old Cheshire Cat.\n";

                    std::cout << "Would you like to grab one and read it? (y/n)\n";
                    std::string userChoice;

                    // Get the user's input for reading books
                    std::getline(std::cin, userChoice);

                    // Convert the user's input to lowercase
                    std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

                    // Check if the user wants to read a book
                    if (userChoice == "y" || userChoice == "yes") {
                        std::cout << "Which title would you like to read?\n"
                                     "1. The history of Wonderland.\n"
                                     "2. Family Tree of the Queen of Hearts.\n"
                                     "3. The rat, the bat, and the fat old Cheshire Cat.\n";

                        auto book_input = getUserInput(custom_character,false);
                        std::istringstream iss(book_input);
                        int book;
                        if (iss >> book) { // Attempt to read an integer from the input
                            bookshelf_breaker = bookChoice(book, custom_character);
                        }
                    } else if (userChoice == "n" || userChoice == "no") {
                        // If the user doesn't want to read a book, break out of the loop
                        break;
                    } else {
                        // Handle invalid input
                        std::cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                    }
                    house_breaker = false;
                }

// Continue with the rest of your code...

            case 3:
                std::cout << "You slowly approach the door, and gently open it... \n"
                             "Inside, you smell a pot boiling, likely some sort of soup \n"
                             "You see a man wearing a chefs hat, the cook, and another woman dressed in very gaudy attire... \n"
                             "She is also quite raucous; directing some crass comments towards the cook.";
                house_breaker = true;
                break;
            case 4:
                std::cout << "You walk towards the door, and slowly open it. Looking out into a beautiful large garden, with a small table and chairs set up. \n"
                             "Every chair is empty, but food is on the table and tea looks to be served. \n"
                             "As you take a step out the door to investigate further, the rabbit jumps out in front of you! \n";
                rabbit.talk("Hold on hold on hold on! You can't be out here no not yet what are you doing please turn around \n");
                custom_character.talk("I have a letter addressed to the Duchess, I am looking for her.\n");
                rabbit.talk("Oh my she is in the kitchen, please deliver it to her \n");
                std::cout << "You turn and head back towards the kitchen. \n";
                house_breaker = false;
                break;
        }
        return house_breaker;
    }

    bool ChapterOneGates::bookChoice(int book, Character custom_character) {
        bool book_choice_breaker;
        Item history_book("The history of Wonderland", "A book explaining the history of wonderland", 1);
        switch (book) {
            case 1:
                std::cout << "You pull out the book which is covered in dust. Clearly it has not been read in a long time. You slowly open the book \n"
                             "the book binding cracks, and the pages smell slightly of must . \n ";
                textFormatter::printItalic("I don't think anyone would miss this, just going to borrow it so I can figure out where I am.\n");
                Character::addItemToInventory(history_book);
                break;
            case 2:
                std::cout << "You pull this one from the shelves, but it has very little dust on it, it seems to be looked at quite frequently. \n"
                             "You open it up, and see that it's all pages and pages about each member of the Queen of Hearts family tree. \n"
                             "Nothing of value in this book so you return it to the shelf... \n";
                book_choice_breaker = false;
                break;
            case 3:
                std::cout << "You pull the book from the shelf, with no real dust, and open it up. This book is full of rhymes and limericks as well as vivid pictures on every page. \n"
                             "This must be a children's book of some sort. \n"
                             "After skimming it with a smile, you close the book and return it to the shelf. \n";
                book_choice_breaker = false;
                break;
        }
        return book_choice_breaker;
    }

    bool ChapterOneGates::kitchenChoice(int kitchen, Character custom_character) {
        bool kitchen_choice_breaker;
        Item Soup("Soup", "Bowl of soup, heavy on the pepper", 0);
        Item Soup_bread("Soup and Bread", "Bowl of soup and bread, good for later", 1);

        switch (kitchen) {
            case 1:
                custom_character.talk("Thank you very much! I would love some food. I'll have a bit now and same some for later. \n");
                Character::addItemToInventory(Soup);
                kitchen_choice_breaker = true;
                break;
            case 2:
                custom_character.talk("Thank you very much for the offer, but I am not overly hungry.\n");
                kitchen_choice_breaker = true;
                break;
            case 3:
                custom_character.talk(" Oh yes please thank you so much, I am ever so starved. May I have seconds and thirds as well? \n");
                std::cout << "The cook nods. \n";
                Character::addItemToInventory(Soup_bread);
                kitchen_choice_breaker = true;
                break;
        }
        return kitchen_choice_breaker;
    }


