//
// Created by asuth on 12/13/2023.
//
#include <iostream>
#include <string>
#include "../Character/Character.h"
#include "../NPC/NPC.h"
#include "../Gates/Chapter_1/ChapterOne.cpp"
#include "../UniversalFunctions/user_input.cpp"
#include <sstream>

class Checkpoint1 {
private:
    bool panic_breaker;

public:
    void Chapter1(const Character& custom_character) {
        ChapterOneGates ch_one_gates;
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
    }
};