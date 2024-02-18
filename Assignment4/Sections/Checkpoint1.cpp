//
// Created by asuth on 12/13/2023.
//
#include <iostream>
#include <string>
#include "../Character/Character.h"
#include "../NPC/NPC.h"
#include "../Gates/Chapter_1/ChapterOne.cpp"
#include <sstream>
#include "../UniversalFunctions/clearFunctions.cpp"
#include "../UniversalFunctions/checkFunctions.cpp"
#include "../UniversalFunctions/textFormatting.cpp"

class Checkpoint1 {
private:
    bool panic_breaker;
    bool rabbit_breaker;
    bool rabbit_item_breaker;
    bool fan_item_breaker;
    bool embankment_breaker;
    bool glove_breaker;
    bool house_breaker;

public:
    void Chapter1(Character custom_character) {
        ChapterOneGates ch_one_gates;

        // Init the npcs
        NPC rabbit = WhiteRabbit();
        NPC fishman = FishFootman();
        NPC dutchess = Dutchess();
        NPC cheshirecat = CheshireCat();

        // Items
        Item letter("Letter", "A letter addressed to the Dutchess", 1);

        RestartChapter:

        std::cout << "You fell engorged, almost like you are blowing up. You look down and see the world around you changing... \n";
        std::cout << "But wait.. no that's not the case, the world isn't changing.. YOU are changing. You are growing! \n";
        std::cout << "You look around at your hands and feet noticing them both grow in size. Before you even start to think about panicking...\n";
        std::cout << "THUNK. You clunk your head on the ceiling...\n";

        while (!Checkpoint1::panic_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Grab the key, and head for the door.\n";
            std::cout << "2. PANIC!!!\n";
            std::cout << "3. Look around for anything useful...\n";

            auto input1 = getUserInput(custom_character);
            std::istringstream iss(input1);
            int panic;
            if (iss >> panic) { // Attempt to read an integer from the input
                panic_breaker = ch_one_gates.panicChoice(panic, custom_character);
            }
        }

        std::cout << "As you look through the door, just hoping someone is there to help you, you see a familiar face! \n"
                     "The rabbit from earlier! This time he is different though, wearing what looks to be a small tuxedo and carrying something in his hands.";

        rabbit.talk("Oh! The Duchess, the Duchess!, Oh! won't she be savage if I've kept her waiting.");
        std::cout << "The rabbit is coming closer, though not directly towards you, but close enough within earshot (especially with those big rabbit ears) \n";

        while (!Checkpoint1::rabbit_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Watch silently as the rabbit passes you by. \n";
            std::cout << "2. Get it's attention : 'Hello good sir, mr rabbit, can you understand me? I am in need of some assistance.'\n";
            std::cout << "3. Get it's attention : `HEY YOU BUNNY MAN HELP ME' \n";

            auto input2 = getUserInput(custom_character);
            std::istringstream iss(input2);
            int rabbit;
            if (iss >> rabbit) { // Attempt to read an integer from the input
                rabbit_breaker = ch_one_gates.rabbitChoice(rabbit, custom_character);

                if (!rabbit_breaker){
                    panic_breaker = false;
                    goto RestartChapter;
                }
            }
        }
        std::cout << "The rabbit, slowly starts approaching you, though very cautiously, as if it is inspecting you. \n"
                     "You wait a little till its closer and then ask : 'Where are we? \n"
                     "Immediately as the words exit your mouth, the rabbit drops the items it is holding and bolts back behind the rock. \n";

        while (!Checkpoint1::rabbit_item_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Leave the items. \n";
            std::cout << "2. Take just the gloves.'\n";
            std::cout << "3. Take the fan.  \n";
            std::cout << "4. Take everything. \n";

            auto input3 = getUserInput(custom_character);
            std::istringstream iss(input3);
            int rabbit_item;
            if (iss >> rabbit_item) { // Attempt to read an integer from the input
                rabbit_item_breaker = ch_one_gates.rabbitItemChoice(rabbit_item, custom_character);

                // Use the fan and possibly drop and/or keep it
                if (checkInventory("Paper Fan", custom_character)) {
                    std::cout << "You feel quite hot, likely because you are taking up most of the space inside of this building.\n"
                                 "Then you remember you have the fan! You pull it out and start fanning yourself... \n"
                                 "While this is happening, you are talking to yourself trying to stay calm. \n"
                                 "You are getting dizzy again, not really sure why as you are standing still but it feels like the room is moving \n";
                    textFormatter::printItalic(" THE ROOM IS MOVING ");
                    std::cout << "you yell as you come to realization that you are SHRINKING again \n"
                                 "Out of panic, you drop the fan... at the same time though, you stop shrinking. \n";
                    custom_character.dropItem("Paper Fan");
                    std::cout << "The fan is laying in front of you now. A potentially useful tool ...\n";

                    while (!Checkpoint1::fan_item_breaker) {
                        std::cout << "What would you like to do?\n";
                        std::cout << "1. Pick up the fan.\n";
                        std::cout << "2. Leave the fan.'\n";
                        auto input4 = getUserInput(custom_character);
                        std::istringstream iss(input4);
                        int fan;
                        if (iss >> fan) {
                            fan_item_breaker = ch_one_gates.fanChoice(fan, custom_character);
                        }
                    }

                }
            }
                // Here is the first split path route we will take. We will check the users inventory, looking for a specific item.
                // If they have it, then we take path A, if not we take path B. They will converge pretty quickly but it increases
                // Immersion to have story dictation reflect choices made.
            else {
                std::cout << "You think to yourself `what a strange creature that is, awfully timid.'\n"
                             "With no real options left, and nothing particularly of use in your inventory, you decide to lay down. \n";
                textFormatter::printItalic("Maybe if i rest for a bit, i'll be able to figure something out \n");
                textFormatter::printBold("** Some time later ... *** \n");
                std::cout << "You awake feeling refreshed, but also, have shrunk down, potentially big enough to get through the door... \n";
            };

            std::cout << "You look around, noticing the room has changed a bit. Then the small door catches your eye. You bolt to the door, hoping to make it through \n "
                         "but as you get there you notice it's closed AGAIN. Not only that, the key from earlier, is back on the table WAY above where you are able to reach. \n";
                         textFormatter::printItalic("Well DRAT, what am I supposed to do now?");

            std::cout << "As soon as you finish your thought, you feel the air around you change... \n";
            textFormatter::printBold("** SPLASH ** \n");
            std::cout << "You are now neck dep in salt water. \n";
            textFormatter::printItalic("What a strange and magical place this is. \n");

            std::cout << "In the distance, you hear some light splashing. Your first thoughts, are `Oh no, a shark` but then you bring yourself back to reality \n"
                         "or at least as close to reality as this is, and realize you are small it could be anything. Focusing your vision, you see that it was in fact a mouse! \n"
                         "You see the mouse swim over to the nearest peice of land. On the bank, you see many other creatures like a Duck, a Dodo, a Lory and an Eaglet. \n"
                         "You slowly climb on the embankment, as to not startle the animals. \n";

            while (!Checkpoint1::embankment_breaker) {
                std::cout << std::endl;
                std::cout << "What would you like to do?\n";
                std::cout << "1. Try and talk to the animals.\n";
                std::cout << "2. Shoo them away. ";
                std::cout << "3. Ignore them, instead looking for a way out \n";

                auto input5 = getUserInput(custom_character);
                std::istringstream iss(input5);
                int embankment;
                if (iss >> embankment) { // Attempt to read an integer from the input
                    embankment_breaker = ch_one_gates.embankmentChoice(embankment, custom_character);
                }
            }

            std::cout << "While looking over the strange selection of animals, you hear a familiar sound... \n";
            textFormatter::printBoldItalic("** Pitter Patter ** ** Pitter Patter ** \n");
            std::cout << "It is the rabbit from earlier! back again! \n";
            rabbit.talk("The Duchess! The Duchess! Oh my dear paws! Oh my fur and whiskers! She’ll get me executed, as sure as ferrets are ferrets! Where can I have dropped them, I wonder? \n");

            // 2nd divergent path, if you have the gloves you can give them to him, by passing the next sequence, if you dont you have to go the house

            if(checkInventory("Gloves", custom_character)) {
                std::cout << "The rabbit seems to be looking for the gloves, which luckily you have on you! \n";
                while (!Checkpoint1::glove_breaker) {
                    std::cout << std::endl;
                    std::cout << "What would you like to do?\n";
                    std::cout << "1. Give the rabbit the gloves.\n";
                    std::cout << "2. Pretend you don't know what hes talking about. \n";
                    std::cout << "3. Wait to see if the rabbit acknowledges you. \n";

                    auto input6 = getUserInput(custom_character);
                    std::istringstream iss(input6);
                    int gloves;
                    if (iss >> gloves) { // Attempt to read an integer from the input
                        glove_breaker = ch_one_gates.gloveChoice(gloves, custom_character);
                    }
                    if(!glove_breaker) {
                        break;
                    }
                }
            }
            else {
                rabbit.talk(" Why, Mary Ann, what are you doing out here? Run home this moment, and fetch me a pair of gloves \n");
                std::cout << "Startled from him responding, you run towards a house you see in the distance... \n"
                             "Upon arrival, you look around the entrance for the gloves. You think to yourself `If I had gloves ,they would be in my wardrobe \n"
                             "You run upstairs, and find the wardrobe. Opening it up, you find a full set of tuxedos, gloves and fans. \n"
                             "You grab a pair of gloves, and run downstairs to meet the Rabbit in the entry way. You hand him the gloves. \n";
            }

            rabbit.talk("Oh my what a help you have been! Thank you so very much! I am in your debt! \n");
            custom_character.talk("Mr Rabbit, I am glad to have your attention, where am I exactly?");
            std::cout << "Before the rabbit can answer, there is a rap at the door \n";
            textFormatter::printBold("** Knock Knock ** \n");
            std::cout << "At the door appeared a Fish-Footman... \n";
            fishman.talk("Good day, I have a letter for the Dutchess. \n ");
            std::cout << "He extends his arm holding a large letter. \n";
            fishman.talk("It is an invitation from the Queen to play croquet. \n");
            std::cout << "As you are the closest person to him, he hands you the letter and turns away, heading back in whatever direction he came. \n";
            custom_character.addItemToInventory(letter);

            std::cout << "When you turn around to pass the letter to the rabbit, you notice he's gone! \n";
            custom_character.talk("Oh my that rabbit is oh so sly. Always disappearing. \n");


            while (!Checkpoint1::house_breaker) {
                // Multiple paths and rooms exist, but one desired path. If they fail the route, return to this checkpoint.
                RestartHouse:
                std::cout << "In front of you there are a few possible paths : \n";
                std::cout << "1. The stairs up to the bedroom area. \n"
                             "2. A doorway to some sort of living room. \n"
                             "3. A closed door, adjacent to the entryway, with a strong scent wafting from it. Likely the kitchen. \n"
                             "4. Opposite the main door, is a closed door. Possibly a back door or garden entrance. \n";

                auto input7 = getUserInput(custom_character);
                std::istringstream iss(input7);
                int house;
                if (iss >> house) { // Attempt to read an integer from the input
                    house_breaker = ch_one_gates.houseChoice(house, custom_character);
                }
            }












        }



    }
};