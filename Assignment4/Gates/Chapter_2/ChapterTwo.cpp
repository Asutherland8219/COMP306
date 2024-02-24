//
// Created by asuth on 2/18/2024.
//

class ChapterTwoGates {
private:
    bool bottle;
    bool bottle_inventory;
public:
    bool cook_breaker;
    bool rabbit_breaker;
    bool fan_breaker;
    bool embankment_breaker;
    bool glove_breaker;
    bool house_breaker;

    bool cookChoice(int cook_choice, const Character& custom_character) {
        Cook cook;
        Item shrinking_mushroom;
        Item growing_mushroom;
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


                break;
            case 3:
                std::cout << "Looking around again, trying to find something useful you catch a glimpse of the bottle from earlier. \n";
                std::cout << "You grab it and tip it up into your mouth... unfortunately nothing comes out \n";
                std::cout << "A thought pops into your head, perhaps this bottle could be useful later... \n";
                while (!bottle) {
                    std::cout << "What do you want to do with the bottle? \n";
                    std::cout << "1. Add the bottle to your inventory. \n";
                    std::cout << "2. Discard the bottle. \n";

                    auto input_bottle = getUserInput(custom_character);
                    std::istringstream iss(input_bottle);

                    int bottle_choice;
                    if (iss >> bottle_choice) {
                        ChapterOneGates::bottle = inventoryBottleChoice(bottle_choice, custom_character);
                        std::cout << "After looking around, you decide nothing else of use is around and go for the key. \n";
                        panicChoice(1, custom_character);
                    }

                }
                break;
        }
        return panic_breaker;
    }

};