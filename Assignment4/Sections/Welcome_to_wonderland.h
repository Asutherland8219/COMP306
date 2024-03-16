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
    static bool panic_breaker;
    static bool rabbit_breaker;
    static bool rabbit_item_breaker;
    static bool fan_item_breaker;
    static bool embankment_breaker;
    static bool glove_breaker;
    static bool house_breaker;

    // Init the npcs
    static WhiteRabbit rabbit;          // Assuming NPC is the base class for WhiteRabbit, FishFootman, Duchess, CheshireCat, Cook
    static FishFootman fishman;
    static Duchess duchess;
    static CheshireCat cheshirecat;
    static Cook cook;

public:
    static Character Chapter1(Character custom_character);
};

#endif //CHECKPOINT1_H
