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
    static bool duchess_intro_breaker;
    static bool duchess_house_breaker;

public:
    MarchHare march_hare;
    MadHatter mad_hatter;
    Five five;
    Seven seven;
    Two two;
    static Queen queen;
    Soldiers soldiers;
    static King king;
    WhiteRabbit rabbit;
    static CheshireCat cheshirecat;
    static Duchess duchess;

    static Character Chapter3(Character custom_character);
};

#endif //YOURPROJECTNAME_MEETING_THE_QUEEN_H
