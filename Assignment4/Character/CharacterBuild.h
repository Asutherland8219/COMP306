#ifndef CHARACTER_BUILD_H
#define CHARACTER_BUILD_H

#include "Character.cpp"
#include "../Inventory/Inventory.cpp"
#include "../Inventory/Items/Item.cpp"
#include <string>
#include <limits>
#include <algorithm>

class CharacterBuild {
public:
    static Character character_build();
    static Character test_character_build();
};

#endif //CHARACTER_BUILD_H
