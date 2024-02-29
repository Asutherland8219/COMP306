//
// Created by asuth on 12/13/2023.
//

#include "Character/CharacterBuild.cpp"
#include "Sections/Intro.cpp"
#include "Sections/Welcome_to_wonderland.cpp"
#include "Sections/Tea_party.cpp"
#include "Sections/Meeting_the_queen.cpp"
#include "Sections/Finale.cpp"
#include "NPC/NPC.cpp"
#include "Tests/LocalTests/IntroTest.cpp"
#include "UniversalFunctions/userInput.cpp"


void Wonderland_test();

int main() {
     //Character creator portion. Walks through the user in creating their own user.
//     Character my_character = CharacterBuild::character_build();
//
////     The intro to the subject material. Same intro regardless of path or choices made.
////    Intro intro_instance{};
////    intro_instance.startAliceInWonderland(my_character);
//
//     //The first checkpoint; contains multiple chapters and has unique routes based on choices made.
//    //Also where we start adding items to inventory and tracking choices made for possible outcomes.
//
//
//    my_character.listInventory();
//    section1.Chapter1(my_character);
//    my_character.listInventory();
//    Checkpoint2 section2{};
//    section2.Chapter2(my_character);

    // checkpoint 2

    // checkpoint 3

    // finale


    // tests
    Wonderland_test();





    return 0;
}

void Wonderland_test() {
//    runFullSequenceTest();
//    runNeutralPathTest();
    runExplorerPathTest();

}



