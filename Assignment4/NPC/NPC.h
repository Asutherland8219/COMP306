//
// Created by asuth on 12/20/2023.
//

#ifndef COMP306_NPC_H
#define COMP306_NPC_H

#include <iostream>
#include <string>

class NPC {
    protected:
        std::string name;

    public:
        NPC(const std::string& npcName);

        void talk(const std::string& dialogue) const;
    };

    class WhiteRabbit : public NPC {
    public:
        WhiteRabbit();
    };

    class FishFootman : public NPC {
    public:
        FishFootman();
    };

    class Duchess : public NPC {
    public:
        Duchess();
    };

    class CheshireCat : public NPC {
    public:
        CheshireCat();
    };

    class Cook : public NPC {
    public:
        Cook();
    };



#endif //COMP306_NPC_H
