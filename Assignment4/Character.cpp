//
// Created by asuth on 12/14/2023.
//

// Character.cpp (Implementation file for Character class)

#include "Character.h"
#include "Quest.h"
#include "Quest.cpp"
#include <iostream>

// Display character details
void Character::displayCharacter() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hair Color: " << hairColor << std::endl;
    std::cout << "Eye Color: " << eyeColor << std::endl;
    std::cout << "Pronouns: " << customPronouns << std::endl;

    // Display completed quests
    std::cout << "Quests:" << std::endl;
    quests.displayQuests();  // Display quests
}

void Character::getQuests() const {
    quests.displayQuests();
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
void Character::setPronouns(int pronoun_choice) {
    switch (pronoun_choice) {
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


Character::Character(const std::string& name, const std::string& hairColor, const std::string& eyeColor,
          int pronounChoice, const Quests& quest)
{
    // Initialize the character's pronouns
    setPronouns(pronounChoice);
}


void Character::addQuest(const std::string &description) {
    quests.addQuest(description);
}


// Method to complete the last objective of the last quest
void Character::completeLastQuestObjective() {
    quests.completeLastQuestObjective();
}

void Character::talk(const std::string& dialogue) const {
    std::cout << name << ": `" << dialogue << "`" << std::endl;
}





