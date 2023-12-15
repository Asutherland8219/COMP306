//
// Created by asuth on 12/14/2023.
//

// Character.cpp (Implementation file for Character class)

#include "Character.h"
#include <iostream>

// Display character details
void Character::displayCharacter() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hair Color: " << hairColor << std::endl;
    std::cout << "Eye Color: " << eyeColor << std::endl;
    std::cout << "Pronouns: " << getPronounsString() << std::endl;
    std::cout << "Quest Objectives:" << std::endl;
    quest.displayQuest();
}

// Accessor for the Quest object
const Quest& Character::getQuest() const {
    return quest;
}


// Setters
void Character::setName(const std::string& newName) {
    name = newName;
}

void Character::setHairColor(const std::string& newHairColor) {
    hairColor = newHairColor;
}

void Character::setEyeColor(const std::string& newEyeColor) {
    eyeColor = newEyeColor;
}

// Setter for pronouns with menu
void Character::setPronouns() {
    std::cout << "Select Pronouns:\n";
    std::cout << "1. He/Him\n";
    std::cout << "2. She/Her\n";
    std::cout << "3. Other\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            pronouns = Pronouns::HE;
            customPronouns = "He";  // Clear custom pronouns
            break;
        case 2:
            pronouns = Pronouns::SHE;
            customPronouns = "She";  // Clear custom pronouns
            break;
        case 3:
            pronouns = Pronouns::OTHER;
            std::cout << "Enter your pronouns: ";
            std::cin.ignore();  // Clear newline from previous input
            std::getline(std::cin, customPronouns);
            break;
        default:
            std::cout << "Invalid choice. Defaulting to He/Him.\n";
            pronouns = Pronouns::HE;
            customPronouns = "He";  // Clear custom pronouns
            break;
    }
}

// Method to add an item to the character's inventory
void Character::addItemToInventory(const Item& newItem) {
    inventory.addItem(newItem);
}

// Function to get pronouns as a string
std::string Character::getPronounsString() const {
    switch (pronouns) {
        case Pronouns::HE:
            return "He/Him";
        case Pronouns::SHE:
            return "She/Her";
        case Pronouns::OTHER:
            return customPronouns;
    }

    return "";  // Default case (should not happen)
}

// Display quest objectives with completion status
void Quest::displayQuest() const {
    for (size_t i = 0; i < objectives.size(); ++i) {
        std::cout << "[" << completionStatus[i] << "] " << objectives[i] << std::endl;
    }
}

// Mark an objective as completed
void Quest::completeObjective(size_t index) {
    if (index < objectives.size()) {
        completionStatus[index] = 'x';
    }
};