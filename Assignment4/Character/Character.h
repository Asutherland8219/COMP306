//
// Created by asuth on 12/14/2023.
//

#ifndef COMP306_CHARACTER_H
#define COMP306_CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
#include "../Inventory/Inventory.h"  // Include the header for the Inventory class
#include "../Quests/Quest.h"

enum Pronouns {
    HE,
    SHE,
    OTHER
};

class Character {
public:
    std::string name;
    std::string hairColor;
    std::string eyeColor;
    std::string customPronouns;
    Pronouns pronouns;
    Inventory inventory;
    Quests quests;
    Character(const std::string &name, const std::string &hairColor, const std::string &eyeColor, int pronounChoice,
              const Quests &quest);

    // Display character details
    void displayCharacter() const;

    // Accessor for the Quest object
    void getQuests() const;

    // Add a completed quest to the list
    void addCompletedQuest(const Quest& completedQuest);

    // Setters
    void setPronouns(int pronoun_choice);  // Setter for pronouns with menu

    // Method to add an item to the character's inventory
    static void addItemToInventory(const Item& newItem);
    void listInventory();

    // Function to get pronouns as a string
    std::string getPronounsString() const;
    void talk(const std::string& dialogue) const;

    // Method to complete a quest objective
    void completeLastQuestObjective();

    void addQuest(const std::string &description);

    void dropItem(const std::string &item_name);

    Item * getItem(const std::string &item_name);
};


#endif //COMP306_CHARACTER_H
