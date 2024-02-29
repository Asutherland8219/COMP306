// Intro Choices Header

#ifndef INTRO_CHOICES_H
#define INTRO_CHOICES_H

#include <iostream>

class introChoices {
public:
    static bool intro_well_breaker;
    static bool intro_hall_breaker;
    static bool intro_drink_breaker;
    static bool intro_table_breaker;
    static bool intro_land_breaker;

    static bool wellChoice(int choice);

    static bool landChoice(int land_choice);

    static bool drinkChoice(int drink_choice);

    static bool hallwayChoice(int hallway_choice);

    static bool tableChoice(int table_choice);
};

#endif //INTRO_CHOICES_H
