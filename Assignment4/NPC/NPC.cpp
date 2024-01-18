//
// Created by asuth on 12/20/2023.
//

#include "NPC.h"

// NPC.cpp


NPC::NPC(const std::string& npcName) : name(npcName) {}

void NPC::talk(const std::string& dialogue) const {
    // add output padding for better readability
    std::cout << std::endl;
    std::cout << name << ": `" << dialogue << "`" << std::endl;
    std::cout << std::endl;
}

WhiteRabbit::WhiteRabbit() : NPC("White Rabbit") {}
