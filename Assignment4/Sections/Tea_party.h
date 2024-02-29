#ifndef CHECKPOINT2_H
#define CHECKPOINT2_H

#include <iostream>
#include <string>
#include "../Gates/Chapter_2/ChapterTwo.cpp"
#include "../Character/Character.h"
#include "../NPC/NPC.h"
#include <unordered_map>
#include "../UniversalFunctions/userInput.h"
#include "../UniversalFunctions/textFormatting.h"

class Checkpoint2 {
private:
    // gate breakers
    bool cook_breaker;
    bool cat_breaker;
    bool small_door_breaker;
    bool gardener_breaker;
    bool queen_breaker;
    bool gardener_save_breaker;

public:
    Character Chapter2(Character custom_character);
};

#endif //CHECKPOINT2_H
