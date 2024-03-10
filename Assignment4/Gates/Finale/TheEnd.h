#ifndef CHAPTERFOURGATES_H
#define CHAPTERFOURGATES_H

#include "../../Character/Character.h"
#include "../../NPC/NPC.h"

class ChapterFourGates {
public:
    static bool attention_breaker;
    static bool court_breaker;
    static King king;
    static WhiteRabbit rabbit;
    static Queen queen;
    static Duchess duchess;

    static bool attentionChoice(int attention_choice, const Character& custom_character);
    static bool courtChoice(int court_choice, const Character& custom_character);
};

#endif // CHAPTERFOURGATES_H
