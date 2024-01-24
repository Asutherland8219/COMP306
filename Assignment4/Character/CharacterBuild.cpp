//
// Created by asuth on 12/13/2023.
//
#include "Character.h"
#include "Character.cpp"
#include "../Inventory/Inventory.h"
#include "../Inventory/Inventory.cpp"
#include "../Inventory/Items/Item.h"
#include "../Inventory/Items/Item.cpp"
#include <iostream>


class CharacterBuild {
public:
    static Character character_build() {


        std::cout << "Welcome to the Adventure Game!" << std::endl;
        std::cout << "Let's start by creating your character." << std::endl;

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
        Character custom_character = Character("", "", "", pronounChoice, quests);
        custom_character.setName(name);
        custom_character.setPronouns(pronounChoice);
        custom_character.setEyeColor(eyeColor);
        custom_character.setHairColor(hairColor);
        custom_character.addQuest("Create Your Character");
        custom_character.completeLastQuestObjective();

        std::cout << "\nGreat! Your character has been created:\n";
        custom_character.displayCharacter();

        std::cout << "Now we can begin the adventure! Onwards and upwards..." << std::endl;

        // Return the created character
        return custom_character;
    }
};
