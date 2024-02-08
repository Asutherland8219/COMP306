//
// Created by asuth on 2/7/2024.
//

#include "defaultCharacterTest.h"

#include <gtest/gtest.h>
#include "../../../../Character/CharacterBuild.cpp"
#include <iostream>

// Define a fixture class for common setup and teardown
class CharacterBuildTest : public ::testing::Test {
protected:
    // Member variables used in tests
    std::string testName;
    std::string testHairColor;
    std::string testEyeColor;
    int testPronounChoice;

    // Set up function that will be called before each test
    void SetUp() override {
        // Initialize variables with test data
        testName = "John Doe";
        testHairColor = "Brown";
        testEyeColor = "Blue";
        testPronounChoice = 1;  // Assuming 1 corresponds to "He/Him"
    }

    // Tear down function that will be called after each test
    void TearDown() override {
        // Clean up if needed
    }
};

// Test case for CharacterBuild
TEST_F(CharacterBuildTest, CharacterBuildTest) {
    // Call the character_build() function from CharacterBuild
    Character character = CharacterBuild::character_build();

    character.displayCharacter();

    // Assert that the character fields are filled correctly
//    EXPECT_EQ(character.getName(), testName);
//    EXPECT_EQ(character.getHairColor(), testHairColor);
//    EXPECT_EQ(character.getEyeColor(), testEyeColor);
//    EXPECT_EQ(character.getPronounChoice(), testPronounChoice);

    // Add more assertions if needed based on your implementation
}