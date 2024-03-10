//
// Created by asuth on 2/26/2024.
//

#include <iostream>
#include "ChapterThree.h"
Duchess duchess;
    bool ChapterThreeGates::duchessIntroChoice(int duchess_intro, Character custom_character) {

        switch (duchess_intro) {
            case 1:
                custom_character.talk("Hello Duchess, good to see you again, if you even remember who I am.");
                duchess.talk("Of course dear, you were the boring looking one who came into the kitchen, correct?");
                custom_character.talk("Yes that was me. How did you get yourself into this mess anyways?");
                duchess.talk("Well you see the Queen is not a fan of waiting, and I was a few minutes late.");
                custom_character.talk("Well that seems like unreasonable justification to lock you in a cell?");
                duchess.talk("I agree whole heartedly. Tell me have you seen my cat? The Cheshire Cat.");
                custom_character.talk("Why yes, he was the reason this whole debacle happened. They are trying to find him to behead him.");
                duchess.talk("Oh that sly minx of a cat. Even helping me when it doesn't mean to. Come now dear, lets be on our way.");
                custom_character.talk("On our way to where exactly?");
                duchess.talk("Back home, to the chalet. Come take my arm I need your assistance walking.");
                std::cout << "You take her arm and begin guiding her along. She leans on you quite heavily unable to walk of her own accord. \n"
                             "You head in the direction of the house you were at earlier. \n";
                duchess_intro_choice = false;
                break;
            case 2:
                std::cout << "You grab the Duchess while everyone is pre-occupied and bolt back towards the house";
                custom_character.talk("Can you not go any faster? We only have a short window of opportunity.");
                duchess.talk("I don't want to break a sweat! It will ruin my makeup.");
                custom_character.talk("Listen, if you don't hurry up, you are gonna end up back in the cell. Does that register with you?");
                std::cout << "This seems to have clicked, as she straightened up and started running faster. \n";
                duchess_intro_choice = false;
                break;
            case 3:
                custom_character.talk("How the hell did you end up here? Aren't you a duchess? shouldn't you be smart enough to not get in these situations?");
                duchess.talk("Well yes I am and perhaps I should be but you see --");
                custom_character.talk("Nope, don't want to hear it , let's go. Time to get you home");
                std::cout << "You grab the Duchess while everyone is pre-occupied and bolt back towards the house";
                duchess_intro_choice = false;
                break;
        }
        return duchess_intro_choice;
    }

    bool ChapterThreeGates::duchessHouseChoice(int duchess_house, Character custom_character) {
        Item amethyst_ring("Amethyst Signet Ring", "A gold ring, bedazzled with purple emeralds ", 1);
        switch (duchess_house) {
            case 1:
                custom_character.talk("Excuse me, where are we going exactly?");
                duchess.talk("My dear, there is a trial at the castle. Everyone MUST go. Come now get ready.");
                custom_character.talk("A trial for what?");
                duchess.talk("Some tarts were stolen from the Queen. They have a long list of witnesses to go through.");
                std::cout << "You slowly get out of bed and put your clothes on. The Duchess comes back into your room after you are dressed.\n";
                duchess.talk("Oh deary, you look so drab, you must add some flare to your outfit. Wait here I'll grab something from my collection");
                std::cout << "She leaves the room for a few minutes, while waiting you sit on the edge of the bed. \n"
                             "After a few minutes, she returns. \n";
                duchess.talk("Well I may have misspoke, a lot of my clothing won't fit you, additionally a lot of it I don't want to give away."
                             "I do have one thing though.");
                std::cout << "She pulled out a ring box and flashed it open. Inside was a very nice gold signet ring, with purple amethyst surrounding it.";
                custom_character.talk("Oh I appreciate the offer but I am not looking to wed.");
                duchess.talk("No you buffoon, it is a pinky ring. Something to add a bit more Pizzazz to your outfit.");
                std::cout << "You take the box, and slip on the ring. It actually looks quite nice.";
                duchess.talk("Now that is much better, make sure not to hide your hands so you can show this off.");
                duchess.talk("I do very much appreciate your assistance earlier, take this as a token of thanks.");
                std::cout << "For the first time since you have met the Duchess, she smiled. \n"
                             "You smile back and nod your head in thanks.\n";
                duchess.talk("NOW lets get moving, we don't want to be late, we know how well that went for me last time.");
                std::cout << "You let out a little chuckle at that and head downstairs to begin your trek to the castle\n";

                custom_character.addItemToInventory(amethyst_ring);

                duchess_house_choice = false;
                break;
            case 2:
                custom_character.talk("Ugh, I am not interested, please go without me.");
                std::cout << "You roll over and close your eyes, as soon as you do, you feel the blankets being ripped off of you. \n";
                duchess.talk("I said lets go... NOW");
                std::cout << "The shrillness of her voice really stood out when she said now so you jolted upright. \n";
                custom_character.talk("where are we going exactly?");
                duchess.talk("My dear, there is a trial at the castle. Everyone MUST go. Come now get ready.");
                custom_character.talk("A trial for what?");
                duchess.talk("Some tarts were stolen from the Queen. They have a long list of witnesses to go through.");
                std::cout << "You slowly get out of bed and put your clothes on. The Duchess comes back into your room after you are dressed.\n";
                duchess.talk("NOW lets get moving, we don't want to be late, we know how well that went for me last time.");
                std::cout << "You let out a little chuckle at that and head downstairs to begin your trek to the castle\n";
                duchess_house_choice = false;
                break;
            case 3:
                std::cout << "You slowly get out of bed and put your clothes on. The Duchess comes back into your room after you are dressed.\n";
                duchess.talk("You are a great listener, would make for an excellent house servant. Please let me know if you are interested when we return.");
                std::cout << "The thought of this made you want to vomit. Out of politeness, you simply smiled at the Duchess.";
                duchess.talk("NOW lets get moving, we don't want to be late, we know how well that went for me last time.");
                std::cout << "You let out a little chuckle at that and head downstairs to begin your trek to the castle\n";
                duchess_house_choice = false;
                break;
        }
        return duchess_intro_choice;
    }

