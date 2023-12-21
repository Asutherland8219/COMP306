//
// Created by asuth on 12/14/2023.
//

#ifndef COMP306_CHARACTER_H
#define COMP306_CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"  // Include the header for the Inventory class
#include "Quest.h"

enum Pronouns {
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
    Quests quests;

public:
    Character(const std::string &name, const std::string &hairColor, const std::string &eyeColor, int pronounChoice,
              const Quests &quest);

    // Display character details
    void displayCharacter() const;

    // Accessor for the Quest object
    void getQuests() const;

    // Add a completed quest to the list
    void addCompletedQuest(const Quest& completedQuest);

    // Setters
    void setName(const std::string& newName);
    void setHairColor(const std::string& newHairColor);
    void setEyeColor(const std::string& newEyeColor);
    void setPronouns(int pronoun_choice);  // Setter for pronouns with menu

    // Method to add an item to the character's inventory
    void addItemToInventory(const Item& newItem);

    // Function to get pronouns as a string
    std::string getPronounsString() const;
    void talk(const std::string& dialogue) const;

    // Method to complete a quest objective
    void completeLastQuestObjective();

    void addQuest(const std::string &description);

};


#endif //COMP306_CHARACTER_H
