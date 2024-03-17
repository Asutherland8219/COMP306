//
// Created by asuth on 12/20/2023.
//

/*
 DOCUMENTATION

 Program Purpose:
	Introduce the character to the world of wonderland


 Classes (functions):
	- startAliceInWonderland(Character)
        Function accepts a custom character and returns the character after moving through quests and logic gates.

This section is the first instance of where the user has the option to choose a path. I will describe the paths here and the
 overarching question being asked here. The path options are:
 1. Well breaker -> Do you want to jump down the well?
 2. Hall breaker -> Do you want to go down the hall, trying out the doors?
 3. Drink breaker -> Do you want to drink the potion?
 4. Land breaker -> How do you react after hitting the bottom of the well?
 5. Table breaker -> Do you want to try and climb the table?

*/




#include "Intro.h"
#include "../UniversalFunctions/userInput.h"


bool introChoices::intro_well_breaker;
bool introChoices::intro_hall_breaker;
bool introChoices::intro_drink_breaker;
bool introChoices::intro_table_breaker;
bool introChoices::intro_land_breaker;

bool Intro::table_breaker;
bool Intro::drink_breaker;
bool Intro::hall_breaker;
bool Intro::land_breaker;
bool Intro::well_breaker;


Character Intro::startAliceInWonderland(Character custom_character) {
    introChoices intro_choices{};
    std::cout
            << "The sun was shining on a beautiful summer day. The dew on the ground reflecting the sunlight while the deer and other fauna scamper around the forest. \n";
    std::cout
            << "You lay on your back, staring up at the blue sky noticing the clouds whisping themselves away. Closing your eyes, you take a deep breath, taking in everything around you. \n";
    std::cout
            << "Suddenly, you hear a rabbit  blitzing by your head. It clips the edge of your blanket and tumbles head over heels. \n\n";

    std::cout
            << "You turn to check its okay and you notice it is not a normal colored rabbit, but white one with Pink eyes! That, wasn't the only strange thing though... \n";
    std::cout << "This rabbit, is wearing a waistcoat AND it is speaking. \n";

    WhiteRabbit rabbit;
    rabbit.talk("oh dear!, oh dear! I shall be late!");

    std::cout << "The rabbit kept running as fast as it could. You quickly stood up and scurried after it. \n";
    std::cout << "You caught up with it just in time to see it jump down a well! \n";
    custom_character.talk("Well I do hope that poor rabbit is alright. That looks like a long way down.");

    // What to do with the well

    while (!Intro::well_breaker) {
        std::cout << std::endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1. Jump in\n";
        std::cout << "2. Throw Something in\n";
        std::cout << "3. Walk away\n";

        // input check
        int choice;
        auto input_well = getUserInput(custom_character, false);
        std::istringstream iss(input_well);
        if (iss >> choice) {
            well_breaker = intro_choices.wellChoice(choice);
        }
    }

    std::cout
            << "You fall or at least what feels like falling while seeing the darkness around you. Looking down you see no bottom,\n"
               "But instead you see things around you, seemingly suspended in space. Bookshelves and pictures. Set up like someones home.\n";
    std::cout
            << "You start to get more comfortable in this seemingly suspended time. You close your eyes and then THUMP...\n";
    std::cout << "You land in a pile of leaves and sticks. \n";

    while (!Intro::land_breaker) {

        // Next steps after landing
        std::cout << std::endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1. Check yourself for injuries\n";
        std::cout << "2. Lay down and rest (You don't know what just happened)\n";

        auto input_land = getUserInput(custom_character, false);
        std::istringstream iss(input_land);
        int land_choice;

        if (iss >> land_choice) {
            land_breaker = intro_choices.landChoice(land_choice);
        }
    }

    std::cout
            << "You look around and scan the area. Everything looks relatively normal except you look up at the sky and it is no longer blue...\n"
               "The sky is now dark. Strange, as it was just sunny.\n";
    std::cout << "Out of the corner of your eye, you see something move... It's the rabbit from earlier!\n";
    rabbit.talk("Oh my ears and whiskers, how late it's getting!");

    std::cout
            << "You turn and chase after the rabbit, maybe they have an idea of where you are and how to help you get out. \n";

    // add the quest
    custom_character.addQuest("Follow the rabbit and figure out where you are");

    std::cout
            << "\n As soon as you turn the corner, you see a long hall, filled with doors and lit up with lamps.\n";
    std::cout
            << "At the end of the hall, you see what looks like a small three legged table. You can't make it out from here, but it looks like something is on top of it\n";

    // Hallway choice
    while (!Intro::hall_breaker) {
        std::cout << std::endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1. Check the doors and see if there is anything there \n";
        std::cout << "2. Head towards the table at the end of the hallway \n";
        std::cout << "3. Leave \n";

        int hallway_choice;
        auto input_hall = getUserInput(custom_character, false);
        std::istringstream iss(input_hall);

        if (iss >> hallway_choice)
            hall_breaker = intro_choices.hallwayChoice(hallway_choice);
    }

    std::cout << "You return to the table where you were before but this time something else catches your eye.\n";
    std::cout
            << "There is a new door, tucked away with some drapes in front of it. You are positive that wasn't there before...\n";
    std::cout
            << "You try the key in the door and to your surprise it works! and the door opens. It is too small for you to enter so you peek inside...\n";
    std::cout
            << "From here, there is nothing you can do. You are much too large to enter this door.. You decide to turn around and notice something new on the table \n";
    std::cout << "On the table now is a bottle, with the words written on it, in capital letters, DRINK ME.";

    while (!Intro::drink_breaker) {
        std::cout << std::endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1. Down the whole thing. What's the worst that could happen. \n";
        std::cout << "2. Inspect the bottle, try and see if there's indicating what it is. Open it and smell. \n";
        std::cout << "3. Try and leave \n";

        int drink_choice;;

        auto input_drink = getUserInput(custom_character, false);
        std::istringstream iss(input_drink);
        if (iss >> drink_choice) {
            drink_breaker = intro_choices.drinkChoice(drink_choice);
        }
    }

    std::cout << "You feel different. Not in a bad way but just like things around you are changing.\n";
    std::cout << "As you survey your surroundings, you notice that things around you are HUGE... \n";
    std::cout
            << "This however was not the case, but in fact the opposite! You have shrunk! Perhaps you can get through the small door..\n";
    std::cout
            << "You move towards the door but it is shut again, you look around your pockets and notice you have forgotten the key!\n";
    std::cout
            << "You turn back to the table and you can see the key! But alas you are small and table is large... How on earth are you gonna get that...\n";

    while (!Intro::table_breaker) {
        std::cout << std::endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1. Try and climb the table leg. \n";
        std::cout << "2. Look around for anything else that might be helpful. \n";
        std::cout << "3. Yell for help. \n";
        int table_choice;

        auto input_table = getUserInput(custom_character, false);
        std::istringstream iss(input_table);
        if (iss >> table_choice) {
            table_breaker = intro_choices.tableChoice(table_choice);
        }
    }
    std::cout << "and now your adventure REALLY begins...";

    textFormatter::printBoldItalic("END INTRO");

    return custom_character;
}

