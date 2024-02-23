//
// Created by asuth on 12/13/2023.
//

#include "Character/CharacterBuild.cpp"
#include "Sections/Intro.cpp"
#include "Sections/Welcome_to_wonderland.cpp"
#include "Sections/Tea_party.cpp"
#include "NPC/NPC.cpp"

int main() {
    Character test_character = CharacterBuild::test_character_build();
    // Character creator portion. Walks through the user in creating their own user.
    // Character my_character = CharacterBuild::character_build();

//    // The intro to the subject material. Same intro regardless of path or choices made.
//    Intro intro_instance;
//    intro_instance.startAliceInWonderland(test_character);

    // The first checkpoint; contains multiple chapters and has unique routes based on choices made.
    // Also where we start adding items to inventory and tracking choices made for possible outcomes.


    test_character.listInventory();
    Checkpoint1 section1;
    section1.Chapter1(test_character);
    test_character.listInventory();
    Checkpoint2 section2;
    section2.Chapter2(test_character);

    // checkpoint 2

    // checkpoint 3

    // finale




    return 0;
}


