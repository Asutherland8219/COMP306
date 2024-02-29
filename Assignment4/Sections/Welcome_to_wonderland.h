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
    bool panic_breaker{};
    bool rabbit_breaker{};
    bool rabbit_item_breaker{};
    bool fan_item_breaker{};
    bool embankment_breaker{};
    bool glove_breaker{};
    bool house_breaker{};

    // Init the npcs
    NPC rabbit;          // Assuming NPC is the base class for WhiteRabbit, FishFootman, Duchess, CheshireCat, Cook
    NPC fishman;
    NPC duchess;
    NPC cheshirecat;
    NPC cook;

public:
    Character Chapter1(Character custom_character);
};

#endif //CHECKPOINT1_H
