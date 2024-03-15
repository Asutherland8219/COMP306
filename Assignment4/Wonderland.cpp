//
// Created by asuth on 12/13/2023.
//

#include "Character/CharacterBuild.cpp"
#include "Sections/Intro.cpp"
#include "Sections/Welcome_to_wonderland.cpp"
#include "Sections/Tea_party.cpp"
#include "Sections/Meeting_the_queen.cpp"
#include "NPC/NPC.cpp"
#include "Tests/LocalTests/IntroTest.cpp"
#include "UniversalFunctions/userInput.cpp"
#include "Sections/Finale.cpp"
#include "Character/FinaleChoices.cpp"



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





    /*
     * Test Function. Comment out any tests you want to run. Each test runs based on the path.
     * If desired, run the full sequence test to run tests on all paths one after the other.
     * Additionally, if you want to run the tests silent, simply change the bool param.
     */
    //    Wonderland_test();





    return 0;
}

void Wonderland_test() {
    // Explorer path test (best path)
    //runExplorerPathTest(false);

    // Neutral Path test (average path, not good or bad)
    //runNeutralPathTest(false);

    // Bad Path Test
    //runBadPathTest(false);

    // Full Sequence Test
    // FullSequenceTest();


}



