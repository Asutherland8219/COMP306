//
// Created by asuth on 12/20/2023.
//

/*
 NPC constructor. Used for all NPC models. Creating NPC will be initialized in this class, then when they communicate,
 will be called in the respective chapter.
 */

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
FishFootman::FishFootman() : NPC("Fish Footman") {}
Dutchess::Dutchess() : NPC("Dutchess") {}
CheshireCat::CheshireCat() : NPC("Cheshire Cat")

