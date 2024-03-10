//
// Created by asuth on 3/9/2024.
//

#ifndef YOURPROJECTNAME_FINALECHOICES_H
#define YOURPROJECTNAME_FINALECHOICES_H

#include <vector>
#include <iostream>
#include "../Character/Character.h"
#include "../NPC/NPC.h"
#include "../UniversalFunctions/userInput.h"

class FinaleChoice {
private:
    std::vector<std::vector<int>> matrix;

public:
    static int calculateInventorySum(const Character& custom_character);
    static void determineEnding(Character custom_character);
};

class PossibleEndings {
public:
    Mother mother;
    Nurse nurse;

    void getEnding(int sumOfValues, Character custom_character);
    void ExplorersEnding(Character custom_character);
    void NeutralEnding(Character custom_character);
    void BadEnding(Character custom_character);
};


#endif //YOURPROJECTNAME_FINALECHOICES_H
