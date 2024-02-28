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
    std::cout << name << ": ";
    textFormatter::printItalic(dialogue);
    std::cout << std::endl;
    std::cout << "\n";
}

WhiteRabbit::WhiteRabbit() : NPC("White Rabbit") {}
FishFootman::FishFootman() : NPC("Fish Footman") {}
Duchess::Duchess() : NPC("Duchess") {}
CheshireCat::CheshireCat() : NPC("Cheshire Cat") {}
Cook::Cook() : NPC("Cook") {}
MarchHare::MarchHare() : NPC("March Hare") {}
MadHatter::MadHatter() : NPC("Mad Hatter"){}
Five::Five() : NPC("Five") {}
Seven::Seven() : NPC("Seven") {}
Queen::Queen() : NPC("Queen") {}
King::King() : NPC("King") {}
Two::Two() : NPC("Two") {}
Soldiers::Soldiers() : NPC("Soldiers") {}
Mouse::Mouse() : NPC("Dormouse") {}
Mother::Mother() : NPC("Mother") {}
Nurse::Nurse() : NPC("Nurse") {}



