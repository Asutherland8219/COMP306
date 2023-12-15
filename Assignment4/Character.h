//
// Created by asuth on 12/14/2023.
//

#ifndef COMP306_CHARACTER_H
#define COMP306_CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"  // Include the header for the Inventory class

class Quest {
private:
    std::vector<std::string> objectives;
    std::vector<char> completionStatus;

public:
    // Constructor
    Quest(const std::vector<std::string>& objectives);

    // Display quest objectives with completion status
    void displayQuest() const;

    // Mark an objective as completed
    void completeObjective(size_t index);
};

enum class Pronouns {
    HE,
    SHE,
    OTHER
};

class Character {
private:
    std::string name;
    std::string hairColor;
    std::string eyeColor;
    std::string customPronouns;
    Pronouns pronouns;
    Inventory inventory;
    Quest quest;

public:
    // Constructor with Quest initialization
    Character(const std::string& name, const std::string& hairColor, const std::string& eyeColor, const std::string& pronouns,
              const std::vector<std::string>& questObjectives);

    // Display character details
    void displayCharacter() const;

    // Accessor for the Quest object
    const Quest& getQuest() const;

    // Method to complete a quest objective
    void completeQuestObjective(size_t index);
    // Setters
    void setName(const std::string& newName);
    void setHairColor(const std::string& newHairColor);
    void setEyeColor(const std::string& newEyeColor);
    void setPronouns();  // Setter for pronouns with menu

    // Method to add an item to the character's inventory
    void addItemToInventory(const Item& newItem);

    // Function to get pronouns as a string
    std::string getPronounsString() const;
};


#endif //COMP306_CHARACTER_H
