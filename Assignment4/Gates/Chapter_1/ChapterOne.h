//
// Created by asuth on 1/17/2024.
//

#ifndef CHAPTER_ONE_GATES_H
#define CHAPTER_ONE_GATES_H

/*
 Logic Gates regarding the first chapter, handled in Checkpoint1. Includes modification to inventory and choices matrix
 */

#include "../../NPC/NPC.h"
#include "../../Character/Character.h"

class ChapterOneGates {
public:
    static bool bottle;
    static bool bottle_inventory;
    static bool panic_breaker;
    static bool rabbit_breaker;
    static bool fan_breaker;
    static bool embankment_breaker;
    static bool glove_breaker;
    static bool house_breaker;
    // Carry over the originally created character to modify inventory

    static bool panicChoice(int panic_choice, const Character& custom_character);
    static bool inventoryBottleChoice(int bottle_choice, const Character& custom_character);
    static bool rabbitChoice(int rabbit_choice, const Character& custom_character);
    static bool rabbitItemChoice(int rabbit_item_choice, const Character& custom_character);
    static bool fanChoice(int fan_choice, const Character& custom_character);
    static bool embankmentChoice(int embankment_choice, const Character& custom_character);
    static bool gloveChoice(int glove_choice, Character custom_character);
    static bool houseChoice(int house_choice, Character custom_character);
    static bool bookChoice(int book, Character custom_character);
    static bool kitchenChoice(int kitchen, Character custom_character);
};

#endif //CHAPTER_ONE_GATES_H
