//
// Created by asuth on 2/28/2024.
//

/*

 DOCUMENTATION

 Program Purpose:
	Test the three possible paths the user can take.

    Also has a silence function so that the total output is not printed.

*/

#include "../../Gates/Finale/TheEnd.h"
#include "../../Character/FinaleChoices.h"
#include <cassert>
#include <fstream>

bool silentMode = true;

// Null output stream
//std::ofstream devnull("/dev/null"); // For Unix-like systems
std::ofstream devnull("nul"); // For Windows

void mockUserInput(int input) {
    std::cin.rdbuf(nullptr);
    std::cin.clear();

    std::istringstream userInput(std::to_string(input));
    std::cin.rdbuf(userInput.rdbuf());
}

void mockEnter(const std::string& input) {
    // Redirect cin to a stringstream containing the provided input
    std::istringstream mockInput(input);
    std::cin.rdbuf(mockInput.rdbuf());
}

void silenceOutput() {
    if (silentMode) {
        std::cout.rdbuf(devnull.rdbuf()); // Redirect cout to null stream
    }
    else {
        std::cout.rdbuf(std::cout.rdbuf());\
    }
}

void enableOutput() {
    silentMode = false;
    silenceOutput(); // Re-enable output
}


Character runExplorerPathTest(bool silent) {
    if (silent) {
        silenceOutput();
    }

    std::cout << "Running Explorer Ending Test...\n";

    // Create test model character
    Character test_character = CharacterBuild::test_character_build();

    //    *** Intro Test ***

    // jump in the well
    introChoices::wellChoice(1);

    // test your body after fall
    introChoices::landChoice(1);

    // potion drink
    introChoices::drinkChoice(1);

    // inspect hallway
    introChoices::hallwayChoice(2);

    // inspect table
    introChoices::tableChoice(2);


//    *** Chapter 1 Welcome to Wonderland Test ***

    // Panic Choice, look around for useful items
    /*
     * Using mock, we first select the 3rd prompt to look for the bottle, then mock the 2nd input of 1 to pick it up
     */
    mockUserInput(1);
    ChapterOneGates::panicChoice(3, test_character);

//    Skipped as it is handled above.
//    ChapterOneGates::inventoryBottleChoice(1, test_character);

    // Talk to rabbit
    ChapterOneGates::rabbitChoice(2, test_character);

    // take gloves and fan
    ChapterOneGates::rabbitItemChoice(4, test_character);

    // add fan back to inventory
    ChapterOneGates::fanChoice(1, test_character);

    // talk to animals
    ChapterOneGates::embankmentChoice(1, test_character);

    // give rabbit gloves
    ChapterOneGates::gloveChoice(1,test_character);

    // Skip this as it expects a string input, after an int, harder to test.
//    ChapterOneGates::houseChoice(2, test_character);

    // pickup book here instead
    ChapterOneGates::bookChoice(1, test_character);

    // accept soup and bread
    ChapterOneGates::kitchenChoice(3, test_character);

    //    *** Chapter 2 Tea Party Test ***

    // talk to the cook
    ChapterTwoGates::cookChoice(2,test_character);

    // talk to cat
    ChapterTwoGates::catChoice(1, test_character);

    // select the fan
    std::unordered_map<int, std::string> inventoryMap;
    ChapterTwoGates::fanChoice(1, test_character, inventoryMap);

    // intro gardeners
    ChapterTwoGates::gardenerIntroChoice(1, test_character);

    // save gardeners
    ChapterTwoGates::gardenerSaveChoice(1, test_character);

    // talk to duchess after saving
    ChapterThreeGates::duchessIntroChoice(1, test_character);

    // talk to duchess in house
    ChapterThreeGates::duchessHouseChoice(1, test_character);

    // Attention choice
    ChapterFourGates::attentionChoice(3, test_character);

    // Court choice (final choice)
    ChapterFourGates::courtChoice(2, test_character);

    // Test the ending
    int end_value = FinaleChoice::determineEnding(test_character);
    assert(end_value == 3);

    std::cout << "\n\nFinished running Explorer Ending Test\n"
                 "All Tests Successful!";

    return test_character;
}

Character runNeutralPathTest(bool silent) {
    if (silent) {
        silenceOutput();
    }

    std::cout << "Running Neutral Ending Test...\n";

    // Create test model character
    Character test_character = CharacterBuild::test_character_build();

    //    *** Intro Test ***

    // jump in the well
    introChoices::wellChoice(1);

    // test your body after fall
    introChoices::landChoice(1);

    // potion drink
    introChoices::drinkChoice(1);

    // inspect hallway
    introChoices::hallwayChoice(2);

    // inspect table
    introChoices::tableChoice(2);


//    *** Chapter 1 Welcome to Wonderland Test ***

    // Panic Choice, look around for useful items
    /*
     * Using mock, we first select the 3rd prompt to look for the bottle, then mock the 2nd input of 1 to pick it up
     */
    mockUserInput(1);
    ChapterOneGates::panicChoice(1, test_character);

//    Skipped as it is handled above.
//    ChapterOneGates::inventoryBottleChoice(1, test_character);

    // Talk to rabbit
    ChapterOneGates::rabbitChoice(2, test_character);

    // take gloves and fan
    ChapterOneGates::rabbitItemChoice(4, test_character);

    // add fan back to inventory
    ChapterOneGates::fanChoice(1, test_character);

    // talk to animals
    ChapterOneGates::embankmentChoice(1, test_character);

    // give rabbit gloves
    ChapterOneGates::gloveChoice(1,test_character);

    // Skip this as it expects a string input, after an int, harder to test.
//    ChapterOneGates::houseChoice(2, test_character);

    // skip picking up book
    ChapterOneGates::bookChoice(2, test_character);

    // accept soup
    ChapterOneGates::kitchenChoice(1, test_character);

    //    *** Chapter 2 Tea Party Test ***

    // talk to the cook
    ChapterTwoGates::cookChoice(2,test_character);

    // talk to cat
    ChapterTwoGates::catChoice(1, test_character);

    // select the fan
    std::unordered_map<int, std::string> inventoryMap;
    ChapterTwoGates::fanChoice(1, test_character, inventoryMap);

    // intro gardeners
    ChapterTwoGates::gardenerIntroChoice(1, test_character);

    // save gardeners
    ChapterTwoGates::gardenerSaveChoice(1, test_character);

    // talk to duchess after saving
    ChapterThreeGates::duchessIntroChoice(1, test_character);

    // talk to duchess in house
    ChapterThreeGates::duchessHouseChoice(2, test_character);

    // Attention choice
    ChapterFourGates::attentionChoice(3, test_character);

    // Court choice (final choice)
    ChapterFourGates::courtChoice(2, test_character);

    // Test the ending
    int end_value = FinaleChoice::determineEnding(test_character);
    mockEnter("\n");
    assert(end_value == 2);

    std::cout << "\n\nFinished running Neutral Ending Test\n"
                 "All Tests Successful!";

    return test_character;

}

Character runBadPathTest(bool silent) {
    std::cout << "Running Bad Ending Test...\n";
    if (silent) {
        silenceOutput();

    }


    // Create test model character
    Character test_character = CharacterBuild::test_character_build();

    //    *** Intro Test ***

    // jump in the well
    introChoices::wellChoice(1);

    // test your body after fall
    introChoices::landChoice(1);

    // potion drink
    introChoices::drinkChoice(1);

    // inspect hallway
    introChoices::hallwayChoice(2);

    // inspect table
    introChoices::tableChoice(2);


//    *** Chapter 1 Welcome to Wonderland Test ***

    // Panic Choice, look around for useful items
    /*
     * Using mock, we first select the 3rd prompt to look for the bottle, then mock the 2nd input of 1 to pick it up
     */
    mockUserInput(1);
    ChapterOneGates::panicChoice(1, test_character);

//    Skipped as it is handled above.
//    ChapterOneGates::inventoryBottleChoice(1, test_character);

    // Talk to rabbit
    ChapterOneGates::rabbitChoice(2, test_character);

    // take nothing
    ChapterOneGates::rabbitItemChoice(1, test_character);

    // add fan back to inventory
    ChapterOneGates::fanChoice(1, test_character);

    // talk to animals
    ChapterOneGates::embankmentChoice(1, test_character);

    // give rabbit gloves
    ChapterOneGates::gloveChoice(1,test_character);

    // Skip this as it expects a string input, after an int, harder to test.
//    ChapterOneGates::houseChoice(2, test_character);

    // skip picking up book
    ChapterOneGates::bookChoice(2, test_character);

    // accept soup
    ChapterOneGates::kitchenChoice(1, test_character);

    //    *** Chapter 2 Tea Party Test ***

    // talk to the cook
    ChapterTwoGates::cookChoice(2,test_character);

    // talk to cat
    ChapterTwoGates::catChoice(1, test_character);

    // select the fan
    std::unordered_map<int, std::string> inventoryMap;
    ChapterTwoGates::fanChoice(1, test_character, inventoryMap);

    // intro gardeners
    ChapterTwoGates::gardenerIntroChoice(1, test_character);

    // save gardeners
    ChapterTwoGates::gardenerSaveChoice(1, test_character);

    // talk to duchess after saving
    ChapterThreeGates::duchessIntroChoice(1, test_character);

    // talk to duchess in house
    ChapterThreeGates::duchessHouseChoice(2, test_character);

    // Attention choice
    ChapterFourGates::attentionChoice(3, test_character);

    // Court choice (final choice)
    ChapterFourGates::courtChoice(2, test_character);

    // Test the ending
    mockEnter("\n\n");
    int end_value = FinaleChoice::determineEnding(test_character);

    assert(end_value == 1);

    std::cout << "\n\nFinished running Bad Ending Test\n"
                 "All Tests Successful!";

    return test_character;
}

void FullSequenceTest() {
    bool sequent_silent;
    std::cout << "Running all possible paths.";
    while (sequent_silent) {
        runExplorerPathTest(true);
        runNeutralPathTest(true);
        runBadPathTest(true);
        sequent_silent = false;
    }
    std::cout << "\nAll paths executed successfully.";
}









