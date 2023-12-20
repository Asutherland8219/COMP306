//
// Created by asuth on 12/19/2023.
//

// Quest.cpp

#include "Quest.h"
#include <algorithm>

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
    quests.push_back(newQuest);
}

void Quests::completeLastQuestObjective() {
    if (!quests.empty()) {
        quests.back().completeObjective();  // Complete the last objective of the last quest
    }
}

void Quest::displayQuest() const {
    std::cout << "{" << description << ": [";
    for (const char& status : completionStatus) {
        std::cout << status;
    }
    std::cout << "]}" << std::endl;
}

