//
// Created by asuth on 12/13/2023.
//
/*

 DOCUMENTATION

 Program Purpose:
	Interact with the Queen, hope to get an answer or a route out of here.


 Classes (functions):
	- Chapter3(Character)
        Accepts the previously edited character in the Chapter 2 function, modifies it and returns it for subsequent chapter calls.

This section is the first instance of where the user has the option to choose a path. I will describe the paths here and the
 overarching question being asked here. The path options are:
 1. duchess_house_breaker -> How do you want to deal with the Duchess at her house.
 2. duchess_intro_breaker -> How do you want to interact with the Duchess immediately after rescuing her.
*/


#include <iostream>
#include "Meeting_the_queen.h"

bool ChapterThreeGates::duchess_house_choice;
bool ChapterThreeGates::duchess_intro_choice;
bool Checkpoint3::duchess_house_breaker;
bool Checkpoint3::duchess_intro_breaker;
Duchess Checkpoint3::duchess;
King Checkpoint3::king;
CheshireCat Checkpoint3::cheshirecat;
Queen Checkpoint3::queen;


Character Checkpoint3::Chapter3(Character custom_character) {
    ChapterThreeGates ch_three_gates;

    // garden quest
    custom_character.addQuest("Find your way out of the garden");

    std::cout << "People began running about in all directions, tumbling up against each other; however, they got settled down in a minute or two, and the game began. \n "
                 "You have never seen such a curious croquet-ground in her life; it was all ridges and furrows; \n"
                 "the balls were live hedgehogs, the mallets live flamingoes, and the soldiers had to double themselves up and to stand on their hands and feet, to make the arches. \n";
    std::cout << "The players all played at once without waiting for turns, quarrelling all the while, and fighting for the hedgehogs;\n"
                 " and in a very short time the Queen was in a furious passion, and went stamping about, and shouting \n";
    queen.talk("Off with his head!");
    queen.talk("Off with her head!");

    // print break
    getUserInput(custom_character, true);

    std::cout << "This was repeated every few minutes. It seems the Queen is very disagreeable. It is a miracle anyone here is left alive!\n"
                 "You start to feel uneasy and nervous. You look around hoping for a way to escape... \n";
    std::cout << "In the corner of your eye, you see a shape forming on a tree branch. As usual the first thing you see is the large toothy grin...\n";
    cheshirecat.talk("Hello dear, how are we getting on?");
    custom_character.talk("I don't think they play fairly. and they all quarrel so dreadfully one can't hear oneself speak-and they don't seem to have any rules in particular; \n"
                          "at least, if there are, nobody attends to them-and you’ve no idea how confusing it is all the things being alive;\n"
                          " for instance, there's the arch I've got to go through next walking about at the other end of the ground-and I should have croqueted the Queen's hedgehog just now, only it ran away when it saw mine coming!");
    // print break
    getUserInput(custom_character, true);

    cheshirecat.talk("Oh well it sounds like you are really enjoying yourself. How do you like the Queen?");
    custom_character.talk("Not at all, she's so extremely --");
    std::cout << "\nAs you are finishing your sentence, the Queen turns and walks towards you\n";
    custom_character.talk("-likely to win, that it's hardly worth while finishing the game.\n");
    std::cout << "The Queen smiled and continued on playing \n"
                 "The King was watching this entire interaction and walked over noticing you were talking to someone... \n";
    king.talk("Who are you talking to?");
    custom_character.talk("It's a friend of mine - a Cheshire Cat - allow me to introduce it.");
    king.talk("I don't like the look of it at all, however, it may kiss my hand if it likes.");
    cheshirecat.talk("I'd rather not.");
    king.talk("Don't be impertinent , and don't look at me like that!");

    // print break
    getUserInput(custom_character, true);

    std::cout << "The cat was eying the king up and down. Almost as if looking at a meal\n";
    custom_character.talk("A cat may look at a king; I've read that in some book, but I don't remember where.");
    king.talk("Well, it must be removed");
    std::cout << "He turned to beckon the queen. \n";
    king.talk("My dear! I wish you would have this cat removed!");
    std::cout << "She resorted to her usual remark. \n";
    queen.talk("Off with his head!");
    king.talk("I'll fetch the executioner myself");
    std::cout << "He hurried off to fetch the executioner\n";

    // print break
    getUserInput(custom_character, true);

    std::cout << "You turn around and head back to the game, as it was your turn, or at least as close as it could be to your turn in this chaos \n";
    std::cout << "After playing your turn and hitting your `hedgehog` ; you turned back around to check on the Cheshire Cat\n"
                 "As soon as you start to approach, you notice a large gathering of people and hear the Queen, the King and the Executioner all arguing. \n"
                 "It seems the executioner didn't want to kill the cat, as he has a fondness of animals, but not people. \n";
    std::cout << "You interject, trying to calm them down. \n";
    custom_character.talk("It belongs to the Duchess, perhaps you should ask her about it.");
    queen.talk("She's in prison");
    std::cout << "She turned to the executioner \n";
    queen.talk("Fetch her here.");
    std::cout << "As he ran away, you notice the Cheshire Cat seems to be getting thinner. As if disappearing into thin air \n"
                 "Once he is gone, everyone is running around frantically trying to find him. \n"
                 "The Executioner returned with the Duchess and joined the madness. \n";

    // talk with the duchess

    while (!duchess_intro_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Talk do the Duchess, ask her some questions. \n";
            std::cout << "2. Grab the Duchess while everyone is freaking out and slip away. \n";
            std::cout << "3. Scorn the Duchess for being captured.  \n";

            auto input1_ch3 = getUserInput(custom_character, false);
            std::istringstream iss(input1_ch3);
            int duchess_intro;
            if (iss >> duchess_intro) { // Attempt to read an integer from the input
                duchess_intro_breaker = ch_three_gates.duchessIntroChoice(duchess_intro, custom_character);
            }
        }

    // print break
    getUserInput(custom_character, true);


    std::cout << "In exchange for your help, the Duchess has offered to let you rest overnight at her house. At this point, you have had a very long day, \n"
                 "Not to mention, the day has been full of adventure. Perhaps a rest is in need. \n\n";

    custom_character.completeLastQuestObjective();

    std::cout << "\nYou rest your eyes, and seem to sleep. No dreams, No nightmares, just wait feels like a tranquil rest. \n";
    std::cout << "You almost feel like you never slept, and are awoken by yelling and panic from the Duchess...\n";
    duchess.talk("Oh dear we need to get going come come lets go lets go!!");

    // print break
    getUserInput(custom_character, true);

    while (!duchess_house_breaker) {
        std::cout << std::endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1. Ask the duchess where we are going? \n";
        std::cout << "2. Grumble, roll over and say you don't want to go.\n";
        std::cout << "3. Jump out of bed and get ready, no questions asked.\n";

        auto input1_ch3 = getUserInput(custom_character, false);
        std::istringstream iss(input1_ch3);
        int duchess_house;
        if (iss >> duchess_house) { // Attempt to read an integer from the input
            duchess_house_breaker = ch_three_gates.duchessHouseChoice(duchess_house, custom_character);
        }
    }

    std::cout << "You set out with your troupe; the Duchess, the Mad Hatter, the March Hare and somewhere in the midst, though not in sight, is the Cheshire Cat. \n";

    std::cout << "You are on your way to the large Castle, finally, with hopes to put an end to this wonderful adventure. \n";

    custom_character.addQuest("Go to the castle... Finally.");

    textFormatter::printBoldItalic("END CHAPTER 3");

    // end meeting the queen.

    return custom_character;


    }
