//
// Created by asuth on 12/13/2023.
//
#include "Character.h"
#include "Character.cpp"
#include "Inventory.h"
#include "Inventory.cpp"
#include "Item.h"
#include "Item.cpp"
#include <iostream>


class Intro {
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

        // Objectives for the quests
        std::vector<std::string> escapeObjectives = {};
        std::vector<std::string> keyObjectives = {};

        // Create character with quests

        Character custom_character = Character("", "", "", 0, {});
        custom_character.setName(name);
        custom_character.setPronouns(pronounChoice);
        custom_character.setEyeColor(eyeColor);
        custom_character.setHairColor(hairColor);

        std::cout << "\nGreat! Your character has been created:\n";
//        custom_character.displayCharacter();

//        custom_character.getQuests();

        custom_character.addQuest("Talk to the cat");
        custom_character.completeLastQuestObjective();
        std::cout << "\nCompleted:\n";
        custom_character.getQuests();

        custom_character.addQuest("Figure out where you are");

        std::cout << "\nCompleted new:\n";
        custom_character.completeLastQuestObjective();
        custom_character.getQuests();

        // Return the created character
        return custom_character;
    }
};
