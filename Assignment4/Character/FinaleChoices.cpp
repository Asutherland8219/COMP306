//
// Created by asuth on 1/17/2024.
//

/* This is where the matrix assigned to the character will be created. It will also house any functions that modify
    the matrix. The purpose of the matrix, is that it will be used to gauge outcomes of the story. The overarching
    quest and progression is linear and will not change, but choices the character makes will change the final outcome.
    For example, a matrix of all 0's is default, while a matrix of 1 or 2's would result in a normal/optimal outcome etc..
*/

#include "FinaleChoices.h"

    // Function to calculate the sum of values of items in the inventory
    int FinaleChoice::calculateInventorySum(const Character& custom_character) {
        int sum = 0;
        for (const auto& item : custom_character.getInventory()) {
            sum += item.getValue();
        }
        return sum;
    }

    // Function to determine the ending based on the inventory sum
    void FinaleChoice::determineEnding(Character custom_character) {
        int sumOfValues = calculateInventorySum(custom_character);
        std::cout << sumOfValues;
        PossibleEndings possibleEndings;
        possibleEndings.getEnding(sumOfValues, custom_character);
    }


    void PossibleEndings::getEnding(int sumOfValues, Character custom_character) {
        // Determine the ending based on the sumOfValues
        if (sumOfValues >= 200) {
            // Call the function for the Explorer's Ending
            ExplorersEnding(custom_character);
        } else if (sumOfValues >= 100) {
            // Call the function for the Neutral Ending
            NeutralEnding(custom_character);
        } else {
            // Call the function for the Bad Ending
            BadEnding(custom_character);
        }
    }

    // Explorers ending (containing multiple items)
    /*
     * You wake from the dream, at the end of the trial, and thus realize it was only a dream. That being said, you check your pockets and pull out an item
     * This item was one of the items in the dream. Leading you to believe this place, Wonderland, may have been more than a dream afterall.
     *
     */

    void PossibleEndings::ExplorersEnding(Character custom_character) {
        std::cout << "You wake from the dream as soon as you yell out at the trial. Your surroundings have changed immensely and now you lie next to a tree, with the sun setting on the horizon.\n"
                     "Off to your right in the distance, you see a small shack. Outside of the shack, you see someone. Then you hear them yelling. \n";

        std::string response = custom_character.name + "time for dinner! Hurry up now!";
        mother.talk(response);
        std::cout << "You realize it is your mother beckoning you for supper. You jump to your feet, thinking about the strange and wonderful dream you just had \n"
                     "As you jump up, you feel something in your pocket.";
        custom_character.talk("What in the world is this?");
        std::string response2 = "Reaching into your pocket, you pull out: " + custom_character.inventory.getInventoryItem("Fan")->name;
        std::cout << "You look it over as you walk towards the house, thinking to yourself, perhaps this wasn't a dream after all... \n";
        std::cout << "The End.";
    }


    // Neutral ending (some items, but not all or greater than x value)
    /*
     * Standard ending from the book:
     * “Oh, I’ve had such a curious dream!” said Alice, and she told her sister, as well as she could remember them,
     * all these strange Adventures of hers that you have just been reading about;
     * and when she had finished, her sister kissed her, and said, “It was a curious dream, dear, certainly: but now run in to your tea; it’s getting late.”
     * So Alice got up and ran off, thinking while she ran, as well she might, what a wonderful dream it had been.
     */

    void PossibleEndings::NeutralEnding(Character custom_character) {
        std::cout << "You wake from the dream as soon as you yell out at the trial. Your surroundings have changed immensely and now you lie next to a tree, with the sun setting on the horizon.\n"
                     "Off to your right in the distance, you see a small shack. Outside of the shack, you see someone. Then you hear them yelling. \n";

        std::string response = custom_character.name + "time for dinner! Hurry up now!";
        mother.talk(response);
        std::cout << "You realize it is your mother beckoning you for supper. You jump to your feet, thinking about the strange and wonderful dream you just had... \n";
        std::cout << "With a smile on your face, and quite a few memories, you walk towards the house ready to have dinner and tell your parents all about the vivid dream you just had.\n";
        std::cout << "The End.";

    }

    // Bad ending (No items, or very few. Indicates poor decisions made.)
    /*
     * You wake up from the dream, or what felt like a dream. But then look around and realize you are in a prison cell. You pinch your arm to see if you are dreaming.
     * Turns out you aren't, at least for this test. You look around and see the executioner near you. He calls to you "It is time" and unlocks your cell. He grabs you and carries
     * you out to be executed. All the while you are begging for your life, pleading and crying for help.
     * He sets your head on the chopping block and pulls his axe up, as he swings down you let out a loud scream.
     *
     * You awake, in a bed, covered in sweat. Not only that, you are strapped down to the bed and restrained. You squirm and try and wrench yourself free but no luck.
     * Shortly after finishing screaming, a nurse enters your room. She calms you down, and then explains the last few days you were restrained because you kept yelling and swinging in your sleep.
     * Apparently you were found under a tree passed out, so they brought you here.
     *
     * As shes explaining, you feel something in your pocket. You pull it out and it is a deck of cards. You start laughing maniacally.... Because of this the nurse recommends you stay here for a while...
     *
     */

    void PossibleEndings::BadEnding(Character custom_character) {
        std::cout << "You wake up from the dream, or what felt like a dream. But then look around and realize you are in a prison cell. You pinch your arm to see if you are dreaming.\n";
        custom_character.talk("OW");
        std::cout << "Turns out you aren't, at least for this test. You look around and see the executioner near you. He calls to you \"It is time\" and unlocks your cell.\n"
                     " He grabs you and carries you out to be executed. All the while you are begging for your life, pleading and crying for help.";
        custom_character.talk("Please sir, please there must be a misunderstanding, I don't belong here I am far from home. Please let me go! \n");
        std::cout << "He sets your head on the chopping block and pulls his axe up, as he swings down you let out a loud scream. \n";
        custom_character.talk("AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");

        // print break for styling
        getUserInput(custom_character, true);

        std::cout << "You awake, in a bed, covered in sweat. Not only that, you are strapped down to the bed and restrained. You squirm and try and wrench yourself free but no luck. \n"
                     "Shortly after finishing screaming, a nurse enters your room. She calms you down, and then explains the last few days you were restrained because you kept yelling and swinging in your sleep. \n"
                     "Apparently you were found under a tree passed out, so they brought you here. \n"
                     "As shes explaining, you feel something in your pocket... \n"
                     " You pull it out and it is a deck of cards. You start laughing maniacally... \n";


        getUserInput(custom_character, true);

        std::cout << "The nurse jumps scared when you start laughing, she turns to fetch the doctor who is standing outside the door. \n"
                     "Between your laughs,you here her say something to the doctor... \n";
        nurse.talk(" I think we better keep them for a while... something weird going on here.");
        std::cout << "You keep laughing, starting to crescendo. At this point you can't stop. Just laugh and laugh and laugh and laugh... \n";
        custom_character.talk("HAHAHAhahaHAHAhahahHAAAHaHAHAH");
        std::cout << "The end.\n";

    }







