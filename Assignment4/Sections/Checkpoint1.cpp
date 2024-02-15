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

class Checkpoint1 {
private:
    bool panic_breaker;
    bool rabbit_breaker;

public:
    void Chapter1(const Character& custom_character) {
        ChapterOneGates ch_one_gates;

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

        NPC rabbit = WhiteRabbit();
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

    }
};