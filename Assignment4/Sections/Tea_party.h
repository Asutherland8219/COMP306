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
    static bool cook_breaker;
    static bool cat_breaker;
    static bool small_door_breaker;
    static bool gardener_breaker;
    static bool queen_breaker;
    static bool gardener_save_breaker;

public:
    static Character Chapter2(Character custom_character);
};

#endif //CHECKPOINT2_H
