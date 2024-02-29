// Intro Header

#ifndef INTRO_H
#define INTRO_H

#include <iostream>
#include "../NPC/NPC.h"
#include "../Gates/Intro/intro_choices.cpp"

#include "../Character/Character.h"

class Intro {
private:
    bool well_breaker;
    bool hall_breaker;
    bool drink_breaker;
    bool table_breaker;
    bool land_breaker;

public:
    // Function to start the Alice in Wonderland intro
    void startAliceInWonderland(Character custom_character);
};

#endif //INTRO_H
