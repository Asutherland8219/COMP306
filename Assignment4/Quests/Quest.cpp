//
// Created by asuth on 12/19/2023.
//

// Quest.cpp

/*
 Quest and Quests class. A quest is a single quest, presented in a dict format {"example quest" : []}.
 The brackets, will be filled with an x once completed. Active quests will remain blank.

 Quests is a list of Quest items. Contains functionality for Adding Quests, completing quests and
 listing all quests.
 */

#include "Quest.h"

// Quest class implementation

Quest::Quest(const std::string& description) : description(description) {
    // Initialize completion status with an empty box
    completionStatus.push_back(' ');
}

void Quest::completeObjective() {
    completionStatus.back() = 'x';  // Complete the last objective
}


void Quests::displayQuests() const {
    for (const Quest& quest : quests) {
        quest.displayQuest();
    }
}

void Quests::addQuest(const std::string& description) {
    Quest newQuest(description);
    std::cout << std::endl;
    std::cout << "A new quest has been added: " << "{ " << description << "}";
    std::cout << std::endl;

    quests.push_back(newQuest);
}

void Quests::completeLastQuestObjective() {
    if (!quests.empty()) {
        quests.back().completeObjective();
        // Complete the last objective of the last quest
    }
}


void Quest::displayQuest() const {
    std::cout << "{" << description << ": [";
    for (const char& status : completionStatus) {
        std::cout << status;
    }
    std::cout << "]}" << std::endl;
}

