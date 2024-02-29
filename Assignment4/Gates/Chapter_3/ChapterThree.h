#ifndef CHAPTERTHREEGATES_H
#define CHAPTERTHREEGATES_H

#include <iostream>
#include "../../Character/Character.h"
#include "../../NPC/NPC.h"

class ChapterThreeGates {
private:
public:
    static bool duchess_intro_choice;
    static bool duchess_house_choice;
    Duchess duchess;

    bool duchessIntroChoice(int duchess_intro, Character custom_character);
    bool duchessHouseChoice(int duchess_house, Character custom_character);
};

#endif // CHAPTERTHREEGATES_H
