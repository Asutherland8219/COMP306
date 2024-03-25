//
// Created by asuth on 12/13/2023.
//
/*
 The Character building function. A walk through where the user is prompted in choices when building their character.
 Final result is a Character model that is passed through subsequent chapters and additional data is added/appended.

 Includes a test character build to run quick test function in character building. This is used to quickly create a
 default character to pass into each chapter and makes for faster testing.

 Allows for customizable traits like name, hair color, eye color and pronouns.

 */
#include "Character.h"
#include <string>
#include <limits>
#include <algorithm>
#include "CharacterBuild.h"




Character CharacterBuild::character_build() {
        std::cout << "Welcome to the Adventure Game!" << std::endl;
        std::cout << "Let's start by creating your character. Menu functions are not available at this point." << std::endl;

        // Gather information to create the character
        std::string name, hairColor, eyeColor;


    // Get the character's name
    while (true) {
        std::cout << "Enter your character's name: ";
        std::getline(std::cin, name);
        if (!name.empty() && std::all_of(name.begin(), name.end(), [](char c) { return std::isalpha(c) || std::isspace(c); })) {
            break; // Exit the loop if the input is not empty and contains only alphabetic characters
        }
        std::cout << "Invalid input. Please enter a valid character name.\n";
    }

    // Get the character's hair color
    while (true) {
        std::cout << "Enter your character's hair color: ";
        std::getline(std::cin, hairColor);
        if (!hairColor.empty() && std::all_of(hairColor.begin(), hairColor.end(), [](char c) { return std::isalpha(c) || std::isspace(c); })) {
            break; // Exit the loop if the input is not empty and contains only alphabetic characters
        }
        std::cout << "Invalid input. Please enter a valid hair color.\n";
    }

    // Get the character's eye color
    while (true) {
        std::cout << "Enter your character's eye color: ";
        std::getline(std::cin, eyeColor);
        if (!eyeColor.empty() &&
            std::all_of(eyeColor.begin(), eyeColor.end(), [](char c) { return std::isalpha(c) || std::isspace(c); })) {
            break; // Exit the loop if the input is not empty and contains only alphabetic characters
        }
        std::cout << "Invalid input. Please enter a valid eye color.\n";
    }

        // Set pronouns for the character
        std::cout << "Select Pronouns:\n";
        std::cout << "1. He/Him\n";
        std::cout << "2. She/Her\n";
        std::cout << "3. Other\n";

        int pronounChoice;
        while (true) {
        if (std::cin >> pronounChoice) {
            // Check if the input is within the valid range
            if (pronounChoice >= 1 && pronounChoice <= 3) {
                // Input is valid, exit the loop
                break;
            } else {
                std::cout << "Invalid input. Please enter a valid pronoun choice (1, 2, or 3).\n";
            }
        } else {
            // Clear the error flag and ignore the invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid pronoun choice (1, 2, or 3).\n";
        }
    }
    // Clear the input buffer to ensure there's no remaining input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Objectives for the quests
        std::vector<std::string> escapeObjectives;
        std::vector<std::string> keyObjectives;

        // Create character with quests
        Quests quests;
        Character custom_character = Character(name, hairColor, eyeColor, pronounChoice, quests);
        custom_character.setPronouns(pronounChoice);
        custom_character.addQuest("Create Your Character");
        custom_character.completeLastQuestObjective();

        std::cout << "\nGreat! Your character has been created:\n";
        custom_character.displayCharacter();

        std::cout << "Now we can begin the adventure! Onwards and upwards..." << std::endl;

        // Return the created character
        return custom_character;
    }

    // test character build
     Character CharacterBuild::test_character_build(){
        std::string name = "John Smith";
        std::string hair_color = "white";
        std::string eye_color = "red";
        int pronouns_choice = 1;
        Quests default_quest;

        Character default_character = Character(name, hair_color, eye_color, pronouns_choice, default_quest);
        default_character.setPronouns(pronouns_choice);
        default_character.addQuest("Create Your Character");
        default_character.completeLastQuestObjective();
        default_character.inventory.items = {};
        default_character.quests = {};
    return default_character;
    };


