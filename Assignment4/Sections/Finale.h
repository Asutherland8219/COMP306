//
// Created by asuth on 12/13/2023.
//

#ifndef FINALE_H
#define FINALE_H

#include <iostream>
#include "../NPC/NPC.h"
#include "../Character/Character.h"
#include "../Gates/Finale/TheEnd.cpp"

class Finale {
private:
public:
    static bool attention_breaker;
    static bool court_breaker;

    static MarchHare march_hare;
    static MadHatter mad_hatter;
    Five five;
    Seven seven;
    Two two;
    static Queen queen;
    Soldiers soldiers;
    static King king;
    static WhiteRabbit rabbit;
    CheshireCat cheshirecat;
    static Duchess duchess;
    static Cook cook;
    static Mouse mouse;

    static Character TheEnd(Character custom_character);
};

#endif // FINALE_H
