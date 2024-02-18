//
// Created by asuth on 12/14/2023.
//

// Character.cpp (Implementation file for Character class)
/*
 Functions for the character class. Includes the default constructor. By default the character starts with hair color,
 eye color, name and pronouns. Additional linked classes include Quests and Inventory.

 Contains addQuest function to add a quest to the character, as well as setters and getters.
 Displaycharacter outputs a summary of the character and the details associated.
*/

#include "Character.h"
#include "../Quests/Quest.h"
#include "../Quests/Quest.cpp"
#include <iostream>
#include <limits>
#include "../UniversalFunctions/textFormatting.cpp"
// Display character details

void Character::displayCharacter() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hair Color: " << hairColor << std::endl;
    std::cout << "Eye Color: " << eyeColor << std::endl;
    std::cout << "Pronouns: " << customPronouns << std::endl;

    // Display completed quests
    std::cout << "Quests:" << std::endl;
    quests.displayQuests();
    std::cout << std::endl;// Display quests
}

void Character::getQuests() const {
    quests.displayQuests();
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
    Inventory::addItem(newItem);
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
          int pronounChoice, const Quests& quest) : name(name), hairColor(hairColor), eyeColor(eyeColor),quests(quest)
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
    std::cout << std::endl;
    std::cout << name << ": ";
    textFormatter::printItalic(dialogue);
    std::cout << std::endl;
}

void Character::listInventory() {
    return Character::inventory.displayInventory();
}

void Character::dropItem(const std::string &item_name) {
    Character::inventory.dropItem(item_name);
}

Item * Character::getItem(const std::string &item_name) {
     return const_cast<Item *>(Character::inventory.getInventoryItem(item_name));
}











