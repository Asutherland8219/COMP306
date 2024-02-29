//
// Created by asuth on 12/13/2023.
//

#ifndef FINALE_H
#define FINALE_H

#include <iostream>
#include "../NPC/NPC.h"
#include "../Character/Character.h"

class Finale {
private:
public:
    static bool attention_breaker;
    static bool court_breaker;

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
    Cook cook;
    Mouse mouse;

    Character TheEnd(Character custom_character);
};

#endif // FINALE_H
