//
// Created by asuth on 3/9/2024.
//

#ifndef YOURPROJECTNAME_MEETING_THE_QUEEN_H
#define YOURPROJECTNAME_MEETING_THE_QUEEN_H

#include <iostream>
#include "../Gates/Chapter_3/ChapterThree.cpp"
#include "../Character/Character.h"
#include "../NPC/NPC.h"

class Checkpoint3 {
private:
    // gate breakers
    bool cook_breaker;
    bool cat_breaker;
    bool small_door_breaker;
    bool gardener_breaker;
    bool queen_breaker;
    bool gardener_save_breaker;
    bool duchess_intro_breaker;
    bool duchess_house_breaker;

public:
    MarchHare march_hare;
    MadHatter mad_hatter;
    Five five;
    Seven seven;
    Two two;
    Queen queen;
    Soldiers soldiers;
    King king;
    WhiteRabbit rabbit;
    CheshireCat cheshirecat;
    Duchess duchess;

    static Character Chapter3(Character custom_character);
};

#endif //YOURPROJECTNAME_MEETING_THE_QUEEN_H
