//
// Created by asuth on 12/13/2023.
//

#ifndef CHECKPOINT1_H
#define CHECKPOINT1_H

#include <iostream>
#include <string>
#include "../NPC/NPC.h"
#include "../Character/Character.h"
#include "../Gates/Chapter_1/ChapterOne.cpp"

class Checkpoint1 {
private:
    static bool panic_breaker{};
    static bool rabbit_breaker{};
    static bool rabbit_item_breaker{};
    static bool fan_item_breaker{};
    static bool embankment_breaker{};
    static bool glove_breaker{};
    static bool house_breaker{};

    // Init the npcs
    static NPC rabbit;          // Assuming NPC is the base class for WhiteRabbit, FishFootman, Duchess, CheshireCat, Cook
    static NPC fishman;
    static NPC duchess;
    static NPC cheshirecat;
    static NPC cook;

public:
    static Character Chapter1(Character custom_character);
};

#endif //CHECKPOINT1_H
