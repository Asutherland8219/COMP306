//
// Created by asuth on 12/13/2023.
//

#include "Character/CharacterBuild.cpp"
#include "Sections/Intro.cpp"
#include "Sections/Checkpoint1.cpp"
#include "NPC/NPC.cpp"

int main() {

    // Character creator portion. Walks through the user in creating their own user.
    Character my_character = CharacterBuild::character_build();

    // The intro to the subject material. Same intro regardless of path or choices made.
    Intro intro_instance;
    intro_instance.startAliceInWonderland(my_character);
    my_character.listInventory();

    // The first checkpoint; contains multiple chapters and has unique routes based on choices made.
    // Also where we start adding items to inventory and tracking choices made for possible outcomes.
    Checkpoint1 section1;
    section1.Chapter1(my_character);

    // checkpoint 2

    // checkpoint 3

    // finale




    return 0;
}


