//
// Created by asuth on 12/13/2023.
//

/*
 DOCUMENTATION

 Program Purpose:
	Continue your journey in wonderland, still trying to find a way out.


 Classes (functions):
	- Chapter1(Character)
        Accepts the previously edited character in the intro function, modifies it and returns it for subsequent chapter calls.

This section is the first instance of where the user has the option to choose a path. I will describe the paths here and the
 overarching question being asked here. The path options are:
 1. House breaker -> Where do you want to go in the house?
 2. Glove breaker -> What do you want to do with the gloves?
 3. Panic breaker -> How do you react to growing in size?
 4. Rabbit breaker -> How do you plan on getting the rabbits attention?
 5. Rabbit item breaker -> What items do you or do you not want to take?
 6. Fan item breaker -> What do you want to do with the fan?
 7. Embankment breaker -> How do you want to talk to the animals?
*/

#include <iostream>
#include <string>

#include <sstream>
#include "../UniversalFunctions/clearFunctions.cpp"
#include "../UniversalFunctions/checkFunctions.h"
#include "Welcome_to_wonderland.h"

CheshireCat Checkpoint1::cheshirecat;
Cook Checkpoint1::cook;
Duchess Checkpoint1::duchess;
FishFootman Checkpoint1::fishman;
WhiteRabbit Checkpoint1::rabbit;

// Checkpoints
bool Checkpoint1::house_breaker;
bool Checkpoint1::glove_breaker;
bool Checkpoint1::embankment_breaker;
bool Checkpoint1::fan_item_breaker;
bool Checkpoint1::rabbit_breaker;
bool Checkpoint1::rabbit_item_breaker;
bool Checkpoint1::panic_breaker;


Character Checkpoint1::Chapter1(Character custom_character) {
        ChapterOneGates ch_one_gates;
        // Items
        Item letter("Letter", "A letter addressed to the Duchess", 1);

        RestartChapter:

        std::cout
                << "\nYou feel engorged, almost like you are blowing up. You look down and see the world around you changing... \n";
        std::cout
                << "But wait.. no that's not the case, the world isn't changing.. YOU are changing. You are growing! \n";
        std::cout
                << "You look around at your hands and feet noticing them both grow in size. Before you even start to think about panicking...\n";
        std::cout << "THUNK. You clunk your head on the ceiling...\n";

        // print break
        getUserInput(custom_character, true);

        while (!Checkpoint1::panic_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Grab the key, and head for the door.\n";
            std::cout << "2. PANIC!!!\n";
            std::cout << "3. Look around for anything useful...\n";

            auto input1 = getUserInput(custom_character, false);
            std::istringstream iss(input1);
            int panic;
            if (iss >> panic) { // Attempt to read an integer from the input
                panic_breaker = ch_one_gates.panicChoice(panic, custom_character);
            }
        }

        std::cout
                << "As you look through the door, just hoping someone is there to help you, you see a familiar face! \n"
                   "The rabbit from earlier! This time he is different though, wearing what looks to be a small tuxedo and carrying something in his hands. \n";

        rabbit.talk("Oh! The Duchess, the Duchess!, Oh! won't she be savage if I've kept her waiting.");
        std::cout
                << "The rabbit is coming closer, though not directly towards you, but close enough within earshot (especially with those big rabbit ears) \n";

        while (!Checkpoint1::rabbit_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Watch silently as the rabbit passes you by. \n";
            std::cout<< "2. Get it's attention : 'Hello good sir, mr rabbit, can you understand me? I am in need of some assistance.'\n";
            std::cout << "3. Get it's attention : `HEY YOU BUNNY MAN HELP ME' \n";

            auto input2 = getUserInput(custom_character, false);
            std::istringstream iss(input2);
            int rabbit_choice;
            if (iss >> rabbit_choice) { // Attempt to read an integer from the input
                rabbit_breaker = ch_one_gates.rabbitChoice(rabbit_choice, custom_character);

                if (!rabbit_breaker) {
                    panic_breaker = false;
                    std::cout << "\n";
                    goto RestartChapter;
                }
            }
        }
        std::cout << "The rabbit, slowly starts approaching you, though very cautiously, as if it is inspecting you. \n"
                     "You wait a little till its closer and then ask :\n";
        custom_character.talk("Where are we? \n");
        std::cout
                << "Immediately as the words exit your mouth, the rabbit drops the items it is holding and bolts back behind the rock. \n";
        std::cout << "The rabbit dropped a pair of gloves and a fan which slides through the door and lands between your feet.\n";

        while (!Checkpoint1::rabbit_item_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Leave the items. \n";
            std::cout << "2. Take just the gloves.\n";
            std::cout << "3. Take the fan.  \n";
            std::cout << "4. Take everything. \n";

            auto input3 = getUserInput(custom_character, false);
            std::istringstream iss(input3);
            int rabbit_item;
            if (iss >> rabbit_item) { // Attempt to read an integer from the input
                rabbit_item_breaker = ch_one_gates.rabbitItemChoice(rabbit_item, custom_character);

                // Use the fan and possibly drop and/or keep it
                if (checkInventory("Paper Fan", custom_character)) {
                    std::cout
                            << "You feel quite hot, likely because you are taking up most of the space inside of this building.\n"
                               "Then you remember you have the fan! You pull it out and start fanning yourself... \n"
                               "While this is happening, you are talking to yourself trying to stay calm. \n"
                               "You are getting dizzy again, not really sure why as you are standing still but it feels like the room is moving \n";
                    custom_character.talk(" THE ROOM IS MOVING \n");
                    std::cout << "You yell as you come to realization that you are SHRINKING again \n"
                                 "Out of panic, you drop the fan... at the same time though, you stop shrinking. \n";
                    custom_character.dropItem("Paper Fan");
                    std::cout << "The fan is laying in front of you now. A potentially useful tool ...\n";

                    while (!Checkpoint1::fan_item_breaker) {
                        std::cout << "What would you like to do?\n";
                        std::cout << "1. Pick up the fan.\n";
                        std::cout << "2. Leave the fan.\n";
                        auto input4 = getUserInput(custom_character, false);
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
                std::cout
                        << "You awake feeling refreshed, but also, have shrunk down, potentially big enough to get through the door... \n";
            };

            // Complete find the rabbit quest
            custom_character.completeLastQuestObjective();

            // print break
            getUserInput(custom_character, true);

            std::cout
                    << "You look around, noticing the room has changed a bit. Then the small door catches your eye. You bolt to the door, hoping to make it through "
                       "but as you get there you notice it's closed AGAIN. Not only that, the key from earlier, is back on the table WAY above where you are able to reach. \n";
            custom_character.talk("Well DRAT, what am I supposed to do now? \n");

            std::cout << "As soon as you finish your thought, you feel the air around you change... \n";
            textFormatter::printBold("** SPLASH ** \n");
            std::cout << "Magically, you are now neck deep in salt water. \n";
            custom_character.talk("What a strange and magical place this is. \n");

            std::cout
                    << "In the distance, you hear some light splashing. Your first thoughts, are `Oh no, a shark` but then you bring yourself back to reality \n"
                       "or at least as close to reality as this is, and realize you are small so it could be anything. Focusing your vision, you see that it was in fact a mouse! \n"
                       "You see the mouse swim over to the nearest piece of land. On the bank, you see many other creatures like a Duck, a Dodo, a Lory and an Eaglet. \n"
                       "You slowly climb on the embankment, as to not startle the animals. \n";

            custom_character.addQuest("Find your way out... again.");

            while (!Checkpoint1::embankment_breaker) {
                std::cout << std::endl;
                std::cout << "What would you like to do?\n";
                std::cout << "1. Try and talk to the animals.\n";
                std::cout << "2. Shoo them away. \n";
                std::cout << "3. Ignore them, instead looking for a way out \n";

                auto input5 = getUserInput(custom_character, false);
                std::istringstream iss(input5);
                int embankment;
                if (iss >> embankment) { // Attempt to read an integer from the input
                    embankment_breaker = ch_one_gates.embankmentChoice(embankment, custom_character);
                }
            }

            std::cout << "While looking over the strange selection of animals, you hear a familiar sound... \n";
            textFormatter::printBoldItalic("** Pitter Patter ** ** Pitter Patter ** \n");
            std::cout << "It is the rabbit from earlier! back again! \n";
            rabbit.talk(
                    "The Duchess! The Duchess! Oh my dear paws! Oh my fur and whiskers! She'll get me executed, as sure as ferrets are ferrets! Where can I have dropped them, I wonder? \n");

            // print break
            getUserInput(custom_character, true);

            // 2nd divergent path, if you have the gloves you can give them to him, by passing the next sequence, if you dont you have to go the house

            if (checkInventory("Gloves", custom_character)) {
                std::cout << "The rabbit seems to be looking for the gloves, which luckily you have on you! \n";
                while (!Checkpoint1::glove_breaker) {
                    std::cout << std::endl;
                    std::cout << "What would you like to do?\n";
                    std::cout << "1. Give the rabbit the gloves.\n";
                    std::cout << "2. Pretend you don't know what hes talking about. \n";
                    std::cout << "3. Wait to see if the rabbit acknowledges you. \n";

                    auto input6 = getUserInput(custom_character, false);
                    std::istringstream iss(input6);
                    int gloves;
                    if (iss >> gloves) { // Attempt to read an integer from the input
                        glove_breaker = ch_one_gates.gloveChoice(gloves, custom_character);
                    }
                    if (!glove_breaker) {
                        break;
                    }
                }
            } else {
                std::cout << "The rabbit sees you and calls out to you.\n";
                rabbit.talk(" Why, Mary Ann, what are you doing out here? Run home this moment, and fetch me a pair of gloves");
                std::cout << "Startled from him responding, you run towards a house you see in the distance... \n"
                             "Upon arrival, you look around the entrance for the gloves. You think to yourself `If I had gloves ,they would be in my wardrobe' \n"
                             "You run upstairs, and find the wardrobe. Opening it up, you find a full set of tuxedos, gloves and fans. \n"
                             "You grab a pair of gloves, and run downstairs to meet the Rabbit in the entry way. You hand him the gloves. \n";
            }
            custom_character.completeLastQuestObjective();

            rabbit.talk("Oh my what a help you have been! Thank you so very much! I am in your debt!");
            custom_character.talk("Mr Rabbit, I am glad to have your attention, where am I exactly?\n");
            std::cout << "Before the rabbit can answer, there is a rap at the door \n";
            textFormatter::printBold("** Knock Knock ** \n");
            std::cout << "At the door appeared a Fish-Footman... \n";
            fishman.talk("Good day, I have a letter for the Duchess.");
            std::cout << "He extends his arm holding a large letter. \n";
            fishman.talk("It is an invitation from the Queen to play croquet.");
            std::cout
                    << "As you are the closest person to him, he hands you the letter and turns away, heading back in whatever direction he came.";

            // print break
            getUserInput(custom_character, true);

            // Add to inventory and add quest
            custom_character.addItemToInventory(letter);
            custom_character.addQuest("Deliver the letter");

            std::cout << "When you turn around to pass the letter to the rabbit, you notice he's gone! \n";
            custom_character.talk("Oh my that rabbit is oh so sly. Always disappearing.\n");


            while (!Checkpoint1::house_breaker) {
                // Multiple paths and rooms exist, but one desired path. If they fail the route, return to this checkpoint.
                RestartHouse:
                std::cout << "In front of you there are a few possible paths : \n";
                std::cout << "1. The stairs up to the bedroom area. \n"
                             "2. A doorway to some sort of living room. \n"
                             "3. A closed door, adjacent to the entryway, with a strong scent wafting from it. Likely the kitchen. \n"
                             "4. Opposite the main door, is a closed door. Possibly a back door or garden entrance. \n";

                auto input7 = getUserInput(custom_character, false);
                std::istringstream iss(input7);
                int house;
                if (iss >> house) { // Attempt to read an integer from the input
                    house_breaker = ch_one_gates.houseChoice(house, custom_character);

                    if (house_breaker) {
                        bool kitchen_breaker;
                        // This is the main path to take
                        duchess.talk("You buffoon, this soup tastes like pepper! Too much! Too much!");
                        std::cout << "The Duchess spits out the food aggressively. \n";
                        cook.talk("I am so sorry I will start over.");

                        std::cout
                                << "The Duchess turns to look at you, with a puzzling look then notices the letter in your hand. \n";
                        duchess.talk("You, give that here.");
                        std::cout << "You hand over the letter to the duchess. \n";
                        custom_character.dropItem("Letter");
                        custom_character.completeLastQuestObjective();
                        duchess.talk("Thank you dear.");
                        custom_character.talk("It is for a croquet match with the Queen.");
                        duchess.talk(
                                "With the Queen!? Oh I must go get ready. Cook forget the soup, it's horrid anyways.");
                        std::cout << "The Duchess pushes past you and rushes upstairs. \n";
                        std::cout
                                << "The cook turns to look at you, looking awfully glum after her insulting his cooking. \n";
                        cook.talk(
                                "Would you like some food? I have lots to spare. I swear it's not as bad as she says.");

                        while (!kitchen_breaker) {
                            std::cout << std::endl;
                            std::cout << "What would you like to do?\n";
                            std::cout << "1. Accept some food. It can't be that bad. \n";
                            std::cout << "2. Politely pass on the food.  \n";
                            std::cout << "3. Accept some food, asking for more for the road.  \n";

                            auto input8 = getUserInput(custom_character, false);
                            std::istringstream iss(input8);
                            int kitchen;
                            if (iss >> kitchen) { // Attempt to read an integer from the input
                                kitchen_breaker = ch_one_gates.kitchenChoice(kitchen, custom_character);
                            };

                            // introduce cheshire cat
                            std::cout << "After speaking with the cook, you turn to exit the kitchen. \n"
                                         "While turning, you are spooked by a pair of eyes looking directly at you. \n"
                                         "It's a cat, perched up on a shelf just watching...\n";

                            NPC cat = NPC("Cat") ;
                            cat.talk("Hello dear, you must be new, what is your name?");
                            std::string response = "Hello Mr Puss, my name is " + custom_character.name ;
                            custom_character.talk(response);
                            cat.talk(
                                    "Pleasure to meet you, you may call me Cheshire, or the Cheshire Cat, whatever suits you best.");
                            std::cout
                                    << "The cat flashes you a wide grin, taking up most of its face with large pointed teeth. \n"
                                       "You look it up and down and notice not only does it have sharp teeth, but also sharp claws. \n"
                                       "While friendly at the moment, it would be wise to stay on the good side of such a vicious looking creature. \n";
                            custom_character.talk("Would you tell me, please, which way I ought to go from here?");
                            cheshirecat.talk("That depends a good deal on where you want to get to,");
                            custom_character.talk("I don't much care where - ");
                            custom_character.talk("- so long as I get somewhere,");

                            // print break
                            getUserInput(custom_character, true);

                            cheshirecat.talk("Oh, you're sure to do that, if you only walk long enough.");

                            custom_character.talk("What sort of people live about here?");

                            cheshirecat.talk("In that direction, -- ");
                            std::cout << "the Cat said, waving its right paw round --\n";
                            cheshirecat.talk("lives a Hatter: and in that direction, ");
                            std::cout << " -- waving the other paw -- \n";
                            cheshirecat.talk("lives a March Hare. Visit either you like: they're both mad.");

                            custom_character.talk("But I don't want to go among mad people.");

                            cheshirecat.talk(
                                    "Oh, you can't help that, We're all mad here. I'm mad. You're mad.");

                            // print break
                            getUserInput(custom_character, true);

                            custom_character.talk("How do you know I'm mad?");
                            cheshirecat.talk("You must be, or you wouldn't have come here.");

                            custom_character.talk("And how do you know that you're mad?");
                            cheshirecat.talk("To begin with, a dog's not mad. You grant that?");
                            custom_character.talk("I suppose so.");

                            cheshirecat.talk(
                                    "Well, then, you see, a dog growls when it's angry, and wags its tail when it's pleased. \n Now I growl when I'm pleased, and wag my tail when I'm angry. Therefore I'm mad.");

                            custom_character.talk("I call it purring, not growling.");
                            cheshirecat.talk("Call it what you like. Do you play croquet with the Queen today?");

                            custom_character.talk("I should like it very much, but I haven't been invited yet.");
                            cheshirecat.talk("You'll see me there.");

                            // print break
                            getUserInput(custom_character, true);

                            std::cout << "The cat threw a wide grin, and winked as it then vanished from sight. \n";

                            std::cout
                                    << "You return to the entryway from earlier, but this time, the door to the garden that was closed is now open \n";
                            std::cout
                                    << "Squinting to focus your vision, you see two creatures sitting at the table; the Mad Hatter and the March Hare \n";
                            std::cout
                                    << "The March Hare see you looking and beckons you over. You walk towards the garden, and get ready to join the tea party \n";

                            custom_character.addQuest("Attend the Tea Party");

                            textFormatter::printBoldItalic("\n \n END CHAPTER 1 \n \n");

                            // End Section 1
                            return custom_character;
                        }
                    } else {
                        goto RestartHouse;
                    };
                }
            }

        }
    }
