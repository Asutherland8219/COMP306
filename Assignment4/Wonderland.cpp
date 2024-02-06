//
// Created by asuth on 12/13/2023.
//

#include "Character/CharacterBuild.cpp"
#include "Sections/Intro.cpp"
#include "Sections/Checkpoint1.cpp"
#include "NPC/NPC.cpp"

int main() {

    // character creator
    Character my_character = CharacterBuild::character_build();

    // intro
    Intro::startAliceInWonderland(my_character);
    my_character.listInventory();

    // checkpoint 1
    Checkpoint1::Chapter1(my_character);



    // checkpoint 2

    // checkpoint 3

    // finale




    return 0;
}


