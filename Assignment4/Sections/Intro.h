// Intro Header

#ifndef INTRO_H
#define INTRO_H

#include <iostream>
#include "../NPC/NPC.h"
#include "../Gates/Intro/intro_choices.cpp"

#include "../Character/Character.h"

class Intro {
private:
    static bool well_breaker;
    static bool hall_breaker;
    static bool drink_breaker;
    static bool table_breaker;
    static bool land_breaker;

public:
    // Function to start the Alice in Wonderland intro
    static void startAliceInWonderland(Character custom_character);
};

#endif //INTRO_H
