//
// Created by asuth on 2/18/2024.
//

#ifndef CHAPTERTWOGATES_H
#define CHAPTERTWOGATES_H

#include <iostream>
#include <unordered_map>
#include "../../Character/Character.h"
#include "../../NPC/NPC.h"

class ChapterTwoGates {
private:
public:
    static bool cook_breaker;
    static bool cat_breaker;
    static bool fan_breaker;
    static bool gardener_breaker;
    static bool gardener_save_breaker;

    static bool cookChoice(int cook_choice, const Character& custom_character);

    static bool catChoice(int cat_choice, const Character& custom_character);

    static bool fanChoice(int fan_choice, const Character& custom_character, std::unordered_map<int, std::string> inventory_map);

    static bool gardenerIntroChoice(int gardener_choice, Character custom_character);

    static bool gardenerSaveChoice(int gardener_save_choice, Character custom_character);

};

#endif // CHAPTERTWOGATES_H
