//
// Created by asuth on 12/13/2023.
//
/*
 The Character building function. A walk through where the user is prompted in choices when building their character.
 Final result is a Character model that is passed through subsequent chapters and additional data is added/appended.

 Includes a test character build to run quick test function in character building. This is used to quickly create a
 default character to pass into each chapter and makes for faster testing.
 */
#include "Character.h"
#include "Character.cpp"
#include "../Inventory/Inventory.h"
#include "../Inventory/Inventory.cpp"
#include "../Inventory/Items/Item.h"
#include "../Inventory/Items/Item.cpp"
#include <iostream>
#include <string>


class CharacterBuild {
public:
    static Character character_build() {
        std::cout << "Welcome to the Adventure Game!" << std::endl;
        std::cout << "Let's start by creating your character. Menu functions are not available at this point." << std::endl;

        // Gather information to create the character
        std::string name, hairColor, eyeColor;


        // Get the character's name
        std::cout << "Enter your character's name: ";
        std::getline(std::cin, name);

        // Get the character's hair color
        std::cout << "Enter your character's hair color: ";
        std::getline(std::cin, hairColor);

        // Get the character's eye color
        std::cout << "Enter your character's eye color: ";
        std::getline(std::cin, eyeColor);

        // Set pronouns for the character
        std::cout << "Select Pronouns:\n";
        std::cout << "1. He/Him\n";
        std::cout << "2. She/Her\n";
        std::cout << "3. Other\n";

        int pronounChoice;
        std::cin >> pronounChoice;
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
    static Character test_character_build(){
        std::string name = "John Smith";
        std::string hair_color = "white";
        std::string eye_color = "red";
        int pronouns_choice = 1;
        Quests default_quest;

        Character default_character = Character(name, hair_color, eye_color, pronouns_choice, default_quest);
        default_character.setPronouns(pronouns_choice);
        default_character.addQuest("Create Your Character");
        default_character.completeLastQuestObjective();
    return default_character;
    };
};

