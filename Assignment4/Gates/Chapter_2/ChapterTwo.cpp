//
// Created by asuth on 2/18/2024.
//

#include <unordered_map>
#include "ChapterTwo.h"


    bool ChapterTwoGates::cook_breaker;
    bool ChapterTwoGates::cat_breaker;
    bool ChapterTwoGates::fan_breaker;
    bool ChapterTwoGates::gardener_breaker;
    bool ChapterTwoGates::gardener_save_breaker;

    bool ChapterTwoGates::cookChoice(int cook_choice, const Character& custom_character) {
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

    bool ChapterTwoGates::catChoice(int cat_choice, const Character& custom_character) {
        CheshireCat cheshirecat;
        switch (cat_choice) {
            case 1:
                custom_character.talk("I am so sorry Mr. Cheshire Cat. I did not mean to offend, I just had no idea how to get your attention.");
                cheshirecat.talk("Oh hush you bore me with your niceties."
                                 "If you really want to leave here, go back to the small door.");
                std::cout << "He disappears. \n";
                cat_breaker = true;
                break;
            case 2:
                custom_character.talk("Apologies Mr. Cheshire Cat, while I have you attention, do you know how I leave Wonderland?");
                std::cout << "He throws a quick grin your way. Knowing you just deflecting the conversation. \n";
                cheshirecat.talk("Why of course dear I know how to escape. But I don't think I shall tell you for what is the fun in that? \n"
                                 "I can and will however direct you in the right direction."
                                 "Remember where you started as it will be the key to moving forward.");
                std::cout << "He flashes another toothy grin, and starts to disappear... \n";

                if (!checkInventory("Red Mushroom", custom_character)) {
                    custom_character.talk("Wait!! I have these mushrooms, can you tell me anything about them?");
                    cheshirecat.talk("Ha. Yes one of them is to grow, the other is to shrink. I won't tell you which is which.");
                    std::cout << "He winks at you and is gone from sight.\n";
                }
                cat_breaker = true;
                break;
            case 3:
                std::cout << "You smile at the cat and continue. \n";
                custom_character.talk("Don't be such a prude, I think you need a little catnip to loosen up.");
                cheshirecat.talk("Ou I like your attitude, you have some serious spunk, the Queen is gonna love this.");
                cheshirecat.talk("You called me over here, so what do you want?");
                custom_character.talk("Straight to the point, I like it.");
                if (!checkInventory("Red Mushroom", custom_character)) {
                    custom_character.talk("I have these mushrooms, can you tell me anything about them?");
                    cheshirecat.talk("Ha. Yes the red is to grow, the blue is to shrink. Is that all?");
                    custom_character.talk("Do you have a litter box or do you just go wherever you please around here?");
                    cheshirecat.talk("HA That is a good one. If that is all I'll be on my way. See you at the croquet game.");
                    std::cout << "The cat disappears from sight";
                }
                else {
                    custom_character.talk("Do you how to escape from here? From Wonderland?");
                    cheshirecat.talk("Of course, go through the small door earlier. Then you'll have some fun and be on your way");
                    std::cout << "He winks at you and begins to disappear \n";
                    custom_character.talk("One more question; Do you know the muffin man? Who lives on Drury lane?");
                    cheshirecat.talk("hahaha");
                    std::cout << "He cackles as he disappears out of sight";
                }
                cat_breaker = true;
                break;
        }
        return cat_breaker;
    }

    bool ChapterTwoGates::fanChoice(int fan_choice, const Character& custom_character, std::unordered_map<int, std::string> inventory_map) {
        std::vector<std::string> shrinking_items = {"Blue Mushroom", "Fan", "Shrinking Fan", "Shrinking Mushroom"};
        std::vector<std::string> growing_items = {"Red Mushroom", "Growing Mushroom","Cook's Cake"};
        switch (fan_choice) {
            case 1:
            case 2:
            case 3:
                // Check if the selected choice exists in the inventory map
                if (inventory_map.find(fan_choice) != inventory_map.end()) {
                    // Get the item name based on the user's selection
                    const std::string &selectedItem = inventory_map.at(fan_choice);

                    // Get the corresponding item from the inventory
                    const Item *selectedInventoryItem = custom_character.inventory.getInventoryItem(selectedItem);

                    // Perform actions based on the selected item
                    if (selectedInventoryItem) {
                        // Example: Display information about the selected item
                        std::cout << "Selected Item: " << selectedItem << std::endl;
                        std::cout << "Description: " << selectedInventoryItem->getDescription() << std::endl;

                        if (std::find(shrinking_items.begin(), shrinking_items.end(), selectedItem) !=
                            shrinking_items.end()) {
                            // Additional actions for shrinking items
                            std::cout << "You use the item and suddenly start getting smaller... \n";
                            custom_character.inventory.dropItem(selectedInventoryItem->name);
                            custom_character.talk("Perfect, now I can fit through the door.");
                            std::cout
                                    << "You walk over to the door, but wait, it's still locked, and you don't have key... \n";
                            custom_character.talk("no no no I can't get in! It's locked!!");
                            std::cout
                                    << "You run up to the door and start banging on it over and over again, hoping someone will answer \n"
                                       "After a few minutes of no response, in your frantic rage, you twist the door knob...";
                            std::cout << "To your surprise, it opens with ease...";
                            custom_character.talk(
                                    "What the heck!? Was the door unlocked all along and the key was just for show? or did I bang the lock loose?");
                            std::cout << "You don't waste anytime dwelling on this, and walk through the door. \n";
                        } else if (std::find(growing_items.begin(), growing_items.end(), selectedItem) !=
                                   growing_items.end()) {
                            // Additional actions for growing items
                            std::cout
                                    << "You grow larger and larger, till you are big enough to reach the table and grab the key.\n";
                            std::cout
                                    << "Once you have the key, you return to the door, but are much too large to enter...\n";

                            bool hasShrinkingItem = false;
                            std::string selectedShrinkingItem;
                            for (const std::string &shrinkingItem: shrinking_items) {
                                if (custom_character.inventory.getInventoryItem(shrinkingItem)) {
                                    hasShrinkingItem = true;
                                    break;
                                }
                            }

                            if (hasShrinkingItem) {
                                std::cout << "Choose another item to use:" << std::endl;
                                for (int i = 0; i < shrinking_items.size(); ++i) {
                                    std::cout << i + 1 << ". " << shrinking_items[i] << std::endl;
                                }

                                int shrinkingChoice;
                                std::cout << "Enter the number corresponding to your choice: ";
                                std::cin >> shrinkingChoice;

                                // Validate the user's choice
                                if (shrinkingChoice >= 1 && shrinkingChoice <= shrinking_items.size()) {
                                    selectedShrinkingItem = shrinking_items[shrinkingChoice - 1];
                                    hasShrinkingItem = true;


                                    // Additional actions for having a Shrinking item along with Growing Mushroom
                                    std::cout << "You have chosen to use: " << selectedShrinkingItem << std::endl;
                                    custom_character.inventory.dropItem(selectedShrinkingItem);

                                    std::cout
                                            << "You start growing smaller now, small enough to reach the door and unlock it. \n"
                                               "Without wasting any time, you walk through the door... \n";

                                }
                            } else {
                                std::cout
                                        << "You are too large to fit through the door. With nothing to lose, you pull your leg back and kick the door with all of your might. \n"
                                           "To your surprise the door breaks off... \n"
                                           "Because of the large exertion of force, you start to sweat profusely and notice that you are shrinking back to normal size, \n"
                                           "Though still too large to enter the door. \n";
                                std::cout
                                        << "After a few minutes of waiting, you see an item fly through the door towards you. It is a small cupcake, in the same color way as the Cheshire Cat; \n"
                                           "In the distance, you hear a laugh almost as if it is fading away. \n"
                                           "Without a thought, you eat the cupcake, because you are both hungry and curious of its effects \n"
                                           "You notice after finishing it, the door getting larger and larger, but that is not the case, as in fact, you are shrinking! \n"
                                           "Now large enough to make it through the door, you walk through, hoping there's some sort of respite on the other side... \n";
                            }
                        };

                    }
                }
                fan_breaker = true;
        }
        return fan_breaker;
    }

    bool ChapterTwoGates::gardenerIntroChoice(int gardener_choice, Character custom_character) {
        Item painted_flower("Painted Flower", "A flower, originally white that was painted red", 1);
        switch (gardener_choice) {
            case 1:
                custom_character.talk("Hello Gentleman? Gentlecards? Gentlethings? Anyways, may I ask what you are doing?");
                std::cout << "After asking, you walk over and pluck one of the painted flowers from the bush";
                Character::addItemToInventory(painted_flower);
                gardener_breaker = true;
                break;
            case 2:
                custom_character.talk("What the HELL are you doing to those flowers??");
                gardener_breaker = true;
                break;
            case 3:
                std::cout << "You point to the bucket of paint, then to the flowers, and then give the gardeners a puzzled look. \n";
                gardener_breaker = true;
        }
        return gardener_breaker;

    }

    bool ChapterTwoGates::gardenerSaveChoice(int gardener_save_choice, Character custom_character) {
        Soldiers soldiers;
        switch (gardener_save_choice) {
            case 1:
                custom_character.talk("Listen, you all should probably run. I'll distract the soldiers.");
                std::cout << "You pretend to get dizzy and faint. When you fall down, the soldiers run to you offering aid \n"
                             "In the background, you can hear the Gardeners running away. \n";
                soldiers.talk("Wait.. Where did they go? Oh crap what are we gonna do? The Queen will have our heads if we don't behead them.");
                custom_character.talk("Don't worry about them, just tell the Queen you beheaded them. She won't know the difference.");
                gardener_save_breaker = true;
                break;
            case 2:
                std::cout << "You grab the gardeners and quickly shove them into some nearby pots. Telling them to be quiet. \n";
                soldiers.talk("Where did they go? They were just here I swear. The Queen will have our head if we don't behead them.");
                custom_character.talk("Don't worry about them, just tell the Queen you beheaded them. She won't know the difference.");
                gardener_save_breaker = true;
                break;
            case 3:
                custom_character.talk("Listen, I have an idea, any chance y'all can hide your heads? Tuck it in like a turtle?");
                std::cout << "The Gardeners look puzzled, but look at each other than nod. \n";
                custom_character.talk("Great, hide your head and lie down. Don't make a sound and leave the rest to me.");
                std::cout << "The Gardeners quickly hide their heads, and lie down on the ground. You grab some berries from a nearby bush and splatter them"
                             "around the head. The soldiers approach you shortly after. \n";
                custom_character.talk("Hello Officers, you can report to the Queen they are beheaded");
                std::cout << "The Soldiers look at you, confused but also terrified. \n";
                soldiers.talk("You don't have a sword or axe, how did you manage to behead them?");
                custom_character.talk("I ripped their heads off, and threw them in the bush over there.");
                std::cout << "You point to the bush, you turn back to face the soldier and show them your red stained hands and flash a toothy grin. \n"
                             "One of the soldiers, turns green in the face and turns to vomit, the other responds to you with a tremble, also taking a step back in the process.";
                soldiers.talk("Uhh oh um yes okay that works alright thank you very much have a nice day goodbye!");
                std::cout << "The Soldiers trip over each-other trying to run away as fast as possible to return to the procession.";
                gardener_save_breaker = true;
        }
        return gardener_save_breaker;

    }
