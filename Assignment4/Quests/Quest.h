//
// Created by asuth on 12/19/2023.
//

#ifndef COMP306_QUEST_H
#define COMP306_QUEST_H

// Quest.h

#include <iostream>
#include <vector>
#include <string>

class Quest {
private:
    std::string description;
    std::vector<char> completionStatus;

public:
    // Constructor
    Quest(const std::string& description);

    // Display quest details
    void displayQuest() const;

    // Mark an objective as completed
    void completeObjective();

    std::string getDescription() const;
};

class Quests {
private:
    std::vector<Quest> quests;

public:
    // Add a new quest to the list
    void addQuest(const std::string& description);

    // Display all quests
    void displayQuests() const;

    // Complete the last objective of the last quest
    void completeLastQuestObjective();

    void addCompletedQuest(const Quest &completedQuest);
};

#endif //COMP306_QUEST_H
