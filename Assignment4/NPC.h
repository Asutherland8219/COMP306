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



#endif //COMP306_NPC_H
