//
// Created by asuth on 12/20/2023.
//


#include <iostream>
#include <string>
#include "Character.h"
#include "NPC.h"

class Intro {
private:
    bool well_breaker;
    bool hall_breaker;
    bool drink_breaker;
    bool table_breaker;
public:
    void startAliceInWonderland(Character custom_character) {
        std::cout << "The sun was shining on a beautiful summer day. The dew on the ground reflecting the sunlight while the deer and other fauna scamper around the forest. \n";
        std::cout << "You lay on your back, staring up at the blue sky noticing the clouds whisping themselves away. Closing your eyes, you take a deep breath, taking in everything around you. \n";
        std::cout << "Suddenly, you hear a rabbit  blitzing by your head. It clips the edge of your blanket and tumbles head over heels. \n\n";

        std::cout << "You turn to check its okay and you notice it is not a normal colored rabbit, but white one with Pink eyes! That, wasn't the only strange thing though... \n";
        std::cout << "This rabbit, is wearing a waistcoat AND it is speaking. \n";

        NPC rabbit = WhiteRabbit();
        rabbit.talk("oh dear!, oh dear! I shall be late!");

        std::cout << "The rabbit kept running as fast as it could. You quickly stood up and scurried after it. \n";
        std::cout << "You caught up with it just in time to see it jump down a well! \n";
        custom_character.talk("Well I do hope that poor rabbit is alright. That looks like a long way down.");

        // What to do with the well
        while (Intro::well_breaker){
            std::cout << "What would you like to do?\n";
            std::cout << "1. Jump in\n";
            std::cout << "2. Throw Something in\n";
            std::cout << "3. Walk away\n";
            int choice;
            std::cin >> choice;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }
            wellChoice(choice);
        }

        std::cout << "You fall or at least what feels like falling while seeing the darkness around you. Looking down you see no bottom, \n "
                     "But instead you see things around you, seemingly suspended in space. Bookshelves and pictures. Set up like someones home. \n\n";
        std::cout << "As the sun dipped low on the horizon, casting a golden glow across the landscape, a peculiar sight caught Alice's\n";
        std::cout << "You start to get more comformatable in this seemingly suspended time. You close your eyes and then THUMP...\n";
        std::cout << "You land in a pile of leaves and sticks. \n";

        // Next steps after landing
        std::cout << "What would you like to do?\n";
        std::cout << "1. Check yourself for injuries\n";
        std::cout << "2. Lay down and rest (You don't know what just happened)\n";
        int land_choice;
        std::cin >> land_choice;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input. Please enter a number.\n");
        }
        landChoice(land_choice);

        std::cout << "You look around and scan the area. Everything looks relatively normal except you look up at the sky and it is no longer blue...\n"
                     "The sky is now dark. Strange, as it was just sunny.\n";
        std::cout << "Out of the corner of your eye, you see something move... It's the rabbit from earlier!\n";
        rabbit.talk("Oh my ears and whiskers, how late it's getting!");

        std::cout << "You turn and chase after the rabbit, maybe they have an idea of where you are and how to help you get out. \n";

        // add the quest
        custom_character.addQuest("Follow the rabbit and figure out where you are");

        // List the quests created
        std::cout << "Objectives: \n";
        custom_character.getQuests();

        std::cout << "As soon as you turn the corner, you see a long hall, filled with doors and lit up with lamps.\n";
        std::cout << "At the end of the hall, you see what looks like a small three legged table. You can't make it out from here, but it looks like something is on top of it\n";

        // Hallway choice
        while (Intro::hall_breaker) {
            std::cout << "What would you like to do?\n";
            std::cout << "1. Check the doors and see if there is anything there \n";
            std::cout << "2. Head towards the table at the end of the hallway \n";
            std::cout << "3. Leave \n";
            int hallway_choice;
            std::cin >> hallway_choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.\n");
            }
            hallwayChoice(hallway_choice);
        }

        std::cout << "You return to the table where you were before but this time something else catches your eye.\n";
        std::cout << "There is a new door, tucked away with some drapes in front of it. You are positive that wasn't there before...\n";
        std::cout << "You try the key in the door and to your surprise it works! and the door opens. It is too small for you to enter so you peek inside...\n";
        std::cout << "From here, there is nothing you can do. You are much too large to enter this door.. You decide to turn around and notice something new on the table \n";
        std::cout << "On the table now is a bottle, with the words written on it, in capital letters, DRINK ME.";

        while (Intro::drink_breaker) {
            std::cout << "What would you like to do?\n";
            std::cout << "1. Down the whole thing. What's the worst that could happen. \n";
            std::cout << "2. Inspect the bottle, try and see if there's indicating what it is. Open it and smell. \n";
            std::cout << "3. Try and leave \n";
            int drink_choice;
            std::cin >> drink_choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.\n");
            }
            drinkChoice(drink_choice);

        }

        std::cout << "You feel different. Not in a bad way but just like things around you are changing.\n";
        std::cout << "As you survey your surroundings, you notice that things around you are HUGE... \n";
        std::cout << "This however was not the case, but in fact the opposite! You have shrunk! Perhaps you can get through the small door..\n";
        std::cout << "You move towards the door but it is shut again, you look around your pockets and notice you have forgotten the key!\n";
        std::cout << "You turn back to the table and you can see the key! But alas you are small and table is large... How on earth are you gonna get that...\n";

        while (Intro::table_breaker) {
            std::cout << "What would you like to do?\n";
            std::cout << "1. Try and climb the table leg. \n";
            std::cout << "2. Look around for anything else that might be helpful. \n";
            std::cout << "3. Yell for help. \n";
            int table_choice;
            std::cin >> table_choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.\n");
            }
            tableChoice(table_choice);

        }
    }

    // Setter for pronouns with menu
    void wellChoice(int choice) {
        switch (choice) {
            case 1:
                std::cout << "You vault over the edge and jump without a fear or care in the world!";
                well_breaker = false;
                break;
            case 2:
                std::cout << "You reach into your pocket, and find a small bronze coin, you throw it in to the well...\n";
                std::cout << "and you wait...\n";
                std::cout << "and you wait...\n";
                std::cout << "and you wait...\n";
                std::cout << "But you never hear it hit the bottom.";
                break;
            case 3:
                std::cout << "You turn around to walk away thinking nothing of what just happened. Just as you start to walk away, a bird swoops down in front of your face. \n"
                             "Out of panic, you take a step back towards the well, losing your footing in the process and tumbling backwards while yelling: \n";
                std::cout << "ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh...\n";
                well_breaker = false;
                break;
        }
    }

    void landChoice(int land_choice) {
        switch (land_choice) {
            case 1:
                std::cout << "You wiggle your toes, move your arms and legs making sure everything is good.\n"
                             "You stand up, seemingly unharmed, though still confused.";
                break;
            case 2:
                std::cout << "You close your eyes and try and sleep or at least gather your bearings. \n";
                std::cout << "...\n";
                std::cout << "...\n";
                std::cout << "...\n";
                std::cout << "After about 10 minutes of trying to rest and figure out what happened, you get restless and stand up.";
                break;
        }

    }

    void drinkChoice(int drink_choice) {
        switch (drink_choice) {
            case 1:
                std::cout << "You taste a savory flavor, one reminiscent of roast turkey, cherry-tart, custard, toffee and hot buttered toast\n";
                drink_breaker = false;
                break;


            case 2:
                std::cout << "You pick up the bottle, turn it over in your hands trying to find anything identifiable.. \n";
                std::cout << "Nothing seems to stand out. You pop the top off and waft in the smells...\n";
                std::cout << "It has a warm, soothing savory sent, reminding you of a christmas dinner.\n";
                std::cout << "It could be poison but it is quite enticing to try it out. \n";
                break;
            case 3:
                std::cout << "You think to yourself `maybe the way back is changed now too. \n When you turn around you see the same dark void as before \n";
                break;
        }
    }

    void hallwayChoice(int hallway_choice) {
        switch (hallway_choice) {
            case 1:
                std::cout << "You run up and down both sides of the hall, trying all the doors but they are all locked.";
                break;
            case 2:
                std::cout << "You head down the hall, and see a key on the table as you get closer...\n";
                std::cout << "a thought pops in your head, maybe the key will work in one of the locked doors!\n";
                std::cout << "You grab the key and start running up and down trying to unlock the doors.\n";
                std::cout << "But to no avail, they are all still locked.\n";
                hall_breaker = false;
                break;
            case 3:
                std::cout << "You've had enough and turn around to go back where you came. \n"
                             "As you turn, you notice the area behind you is dark now... with seemingly no end.\n";
                std::cout << "It seems you can only move forward from here. \n";
                break;
        }
    }

    void tableChoice(int table_choice) {
        switch (table_choice) {
            case 1:
                std::cout << "You try and muster up all your might and climb the leg... You get a bit up and then slip.\n";
                std::cout << "It seems near impossible to climb without anything to grab on to.\n";
                break;
            case 2:
                std::cout << "You take in a few deep breaths and look around for something useful. You notice a small glass box you missed before.\n";
                std::cout << "At this point, you have nothing to lose and it likely isn't poison *since the drink wasn't* \n";
                std::cout << "You open it up, and see a cake with the words `EAT ME` on the top. \n";
                std::cout << "You start eating small peices to see what would happen... after a while nothing happens \n";
                std::cout << "You keep eating until the entire cake is finished, perhaps then something will happen...";
                table_breaker = false;
                break;
            case 3:
                std::cout << "You scream at the top of your lungs `HELLO IS ANYONE THERE? I NEED SOME HELP`\n";
                std::cout << "You hear nothing but an echo of your own voice... Crickets \n";

                break;
        }
    }

};