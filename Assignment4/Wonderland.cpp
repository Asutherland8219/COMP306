//
// Created by asuth on 12/13/2023.
//

#include "Character/CharacterBuild.cpp"
#include "Sections/Intro.cpp"
#include "NPC/NPC.cpp"

int main() {

    // character creator
    Character my_character = CharacterBuild::character_build();

    // intro
    Intro intro;
    intro.startAliceInWonderland(my_character);

    // checkpoint 1

    // checkpoint 2

    // checkpoint 3

    // finale




    return 0;
}


