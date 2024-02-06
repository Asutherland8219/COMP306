//
// Created by asuth on 1/8/2024.
//
// Setter for pronouns with menu
#include <iostream>

class introChoices {
public:
    static bool intro_well_breaker;
    static bool intro_hall_breaker;
    static bool intro_drink_breaker;
    static bool intro_table_breaker;
    static bool intro_land_breaker;


    static bool wellChoice(int choice) {
        switch (choice) {
            case 1:
                std::cout << "You vault over the edge and jump without a fear or care in the world!";
                intro_well_breaker = true;
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
                intro_well_breaker = true;
                break;
        }
        return intro_well_breaker;
    }

    static bool landChoice(int land_choice) {
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
                intro_land_breaker = true;
                break;
        }
        return intro_land_breaker;
    }

    static bool drinkChoice(int drink_choice) {
        switch (drink_choice) {
            case 1:
                std::cout << "You taste a savory flavor, one reminiscent of roast turkey, cherry-tart, custard, toffee and hot buttered toast\n";
                intro_drink_breaker = true;
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
        return intro_drink_breaker;
    }

    static bool hallwayChoice(int hallway_choice) {
        switch (hallway_choice) {
            case 1:
                std::cout << "You run up and down both sides of the hall, trying all the doors but they are all locked.";
                break;
            case 2:
                std::cout << "You head down the hall, and see a key on the table as you get closer...\n";
                std::cout << "a thought pops in your head, maybe the key will work in one of the locked doors!\n";
                std::cout << "You grab the key and start running up and down trying to unlock the doors.\n";
                std::cout << "But to no avail, they are all still locked.\n";
                intro_hall_breaker = true;
                break;
            case 3:
                std::cout << "You've had enough and turn around to go back where you came. \n"
                             "As you turn, you notice the area behind you is dark now... with seemingly no end.\n";
                std::cout << "It seems you can only move forward from here. \n";
                break;
        }
        return intro_hall_breaker;
    }

    static bool tableChoice(int table_choice) {
        switch (table_choice) {
            case 1:
                std::cout << "You try and muster up all your might and climb the leg... You get a bit up and then slip.\n";
                std::cout << "It seems near impossible to climb without anything to grab on to.\n";
                break;
            case 2:
                std::cout << "You take in a few deep breaths and look around for something useful. You notice a small glass box you missed before.\n";
                std::cout << "At this point, you have nothing to lose and it likely isn't poison *since the drink wasn't* \n";
                std::cout << "You open it up, and see a cake with the words `EAT ME` on the top. \n";
                std::cout << "You start eating small pieces to see what would happen... after a while nothing happens \n";
                std::cout << "You keep eating until the entire cake is finished, perhaps then something will happen...";
                intro_table_breaker = true;
                break;
            case 3:
                std::cout << "You scream at the top of your lungs `HELLO IS ANYONE THERE? I NEED SOME HELP`\n";
                std::cout << "You hear nothing but an echo of your own voice... Crickets \n";

                break;
        }
        return intro_table_breaker;
    }



};

