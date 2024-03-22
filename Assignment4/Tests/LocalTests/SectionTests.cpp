//
// Created by asuth on 3/16/2024.
//

/*

 DOCUMENTATION

 Program Purpose:
	Test each chapter/section
    No assertions or validity checks, mainly used to run each block for easier debugging.
    Instead of running the function top to bottom, can run each section as desired.

*/

#include "../../Character/Character.h"
#include "../../Sections/Intro.h"
#include "../../Sections/Welcome_to_wonderland.h"
#include "../../Sections/Meeting_the_queen.h"
#include "../../Sections/Tea_party.h"
#include "../../Sections/Finale.h"

Character TestIntro(Character custom_character) {
    Character intro_char = Intro::startAliceInWonderland(custom_character);
    return intro_char;
};

Character TestChapter1(Character intro_character) {
    Character ch_1_character = Checkpoint1::Chapter1(intro_character);
    return ch_1_character;
}