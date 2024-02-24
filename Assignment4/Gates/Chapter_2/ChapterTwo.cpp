//
// Created by asuth on 2/18/2024.
//

#include <iostream>
#include <sstream>
#include "../../Inventory/Items/Item.h"
#include "../../NPC/NPC.h"
#include "../../Character/Character.h"

class ChapterTwoGates {
private:
public:
    bool cook_breaker;
    bool cat_breaker;

    bool cookChoice(int cook_choice, const Character& custom_character) {
        Cook cook;
        Item shrinking_mushroom("Shrinking Mushroom", "A mushroom that makes you smaller.", 1);
        Item growing_mushroom("Growing Mushroom", "A mushroom that makes you larger.", 1);
        Item cake("Cooks Cake", "A small cake prepared by the cook. Along with a small cloth bag.", 1);
        switch (cook_choice) {
            case 1:
                std::cout << "You flash him a friendly smile in return. He keeps walking towards the kitchen, unbothered "
                             "from getting chewed out by the Queen earlier. \n";
                cook_breaker = true;
                break;
            case 2:
                std::cout << "You smile back at him but before he goes you get his attention...\n";
                custom_character.talk("Excuse me Mr cook.");
                cook.talk("yes dear?");
                custom_character.talk("Do you have any insight on these mushrooms? Perhaps an idea on what they do? if anything.");
                std::cout << "You pull out the small pieces of mushrooms you grabbed earlier to show him.";
                cook.talk("Yes of course! I am the one who prepared the tea party!");
                cook.talk("The red mushroom, is a growing mushroom, while the blue is it's counterpart, a shrinking mushroom.");
                custom_character.talk("Oh thank you so much! This is ever so helpful.");
                cook.talk("Of course! All the best! Let me know if you have any more food questions.");
                custom_character.talk("I will! Thanks again!");
                // update the mushrooms
                custom_character.inventory.updateItem("Red Mushroom", shrinking_mushroom);
                custom_character.inventory.updateItem("Blue Mushroom", growing_mushroom);
                cook_breaker = true;
                break;
            case 3:
                std::cout << "You grab the cooks attention, making him stop in his tracks to talk.\n";
                custom_character.talk("Mr cook, I wanted to apologize for not standing up for you earlier."
                                      "The way the Duchess was treating you was appalling.");
                cook.talk("Oh dear don't worry about that, if anything, that was her being nice; she is one mean old bag.");
                std::cout << "He fires you a wink after the last remark, noticing that your mouth was agape from the comment. \n";
                cook.talk("I do appreciate you taking the time to apologize and even considering the thought of standing up for me."
                          "Would you do me a favor and wait right here?");
                std::cout << "You smile and nod. \n"
                             "The cook dips into the kitchen and a few seconds later he is back out. \n"
                             "In his hands, he holds a cloth bag with small white box... \n";
                cook.talk("Here is a parting gift, I know you must be aching to get home. It is a cake, and if record shows"
                          "may be of use later on to you. Your pockets must be getting full so take the bag as well!");
                std::cout << "He smiles and hands you the bag containing cake box";
                Inventory::addItem(cake);
                custom_character.talk("Thank you so much! I am sure It will be delicious!");
                std::cout << "You hear a shrill sound in the distance, likely the Duchess losing her mind over something \n";
                cook.talk("Well that's my signal, back to work! Good luck!");
                custom_character.talk("Thank you for all your help!");
                std::cout << "He smiles and bows to you then quickly bolts back into the kitchen.";
                cook_breaker = true;
                break;
        }
        return cook_breaker;
    }

    bool catChoice(int cat_choice, const Character& custom_character) {
        switch (cat_choice) {
            case 1:
                std::cout
                        << "You flash him a friendly smile in return. He keeps walking towards the kitchen, unbothered "
                           "from getting chewed out by the Queen earlier. \n";
                cat_breaker = true;
                break;
            case 2:
                std::cout << "You smile back at him but before he goes you get his attention...\n";
                cat_breaker = true;
                break;
            case 3:
                std::cout << "You grab the cooks attention, making him stop in his tracks to talk.\n";
                cat_breaker = true;
                break;
        }
        return cat_breaker;
    }



};