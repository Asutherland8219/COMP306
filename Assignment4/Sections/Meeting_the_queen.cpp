//
// Created by asuth on 12/13/2023.
//
#include <iostream>
#include <string>
#include "../Gates/Chapter_2/ChapterTwo.cpp"
#include "../Character/Character.h"
#include "../NPC/NPC.h"
#include "../UniversalFunctions/userInput.cpp"
#include <unordered_map>


class Checkpoint3 {
private:
    // gate breakers
    bool cook_breaker;
    bool cat_breaker;
    bool small_door_breaker;
    bool gardener_breaker;
    bool queen_breaker;
    bool gardener_save_breaker;

public:
    MarchHare march_hare;
    MadHatter mad_hatter;
    Five five;
    Seven seven;
    Two two;
    Queen queen;
    Soldiers soldiers;
    King king;
    WhiteRabbit rabbit;
    CheshireCat cheshirecat;

    Character Chapter3(Character custom_character) {
    std::cout << "People began running about in all directions, tumbling up against each other; however, they got settled down in a minute or two, and the game began. \n "
                 "You have never seen such a curious croquet-ground in her life; it was all ridges and furrows; \n"
                 "the balls were live hedgehogs, the mallets live flamingoes, and the soldiers had to double themselves up and to stand on their hands and feet, to make the arches. \n";
    std::cout << "The players all played at once without waiting for turns, quarrelling all the while, and fighting for the hedgehogs;\n"
                 " and in a very short time the Queen was in a furious passion, and went stamping about, and shouting \n";
    queen.talk("Off with his head!");
    queen.talk("Off with her head!");
    std::cout << "This was repeated every few minutes. It seems the Queen is very disagreeable. It is a miracle anyone here is left alive!\n"
                 "You start to feel uneasy and nervous. You look around hoping for a way to escape... \n";
    std::cout << "In the corner of your eye, you see a shape forming on a tree branch. As usual the first thing you see is the large toothy grin...";
    cheshirecat.talk("Hello dear, how are we getting on?");
    custom_character.talk("I don't think they play fairly. and they all quarrel so dreadfully one can’t hear oneself speak—and they don’t seem to have any rules in particular; \n"
                          "at least, if there are, nobody attends to them—and you’ve no idea how confusing it is all the things being alive;\n"
                          " for instance, there’s the arch I’ve got to go through next walking about at the other end of the ground—and I should have croqueted the Queen’s hedgehog just now, only it ran away when it saw mine coming!");
    cheshirecat.talk("Oh well it sounds like you are really enjoying yourself. How do you like the Queen?");
    custom_character.talk("Not at all, she's so extremely --");
    std::cout << "As you are finishing your sentence, the Queen turns and walks towards you\n";
    custom_character.talk("—likely to win, that it’s hardly worth while finishing the game.");
    std::cout << "The Queen smiled and continued on playing \n"
                 "The King was watching this entire interaction and walked over noticing you were talking to someone... \n";
    king.talk("Who are you talking to?");
    custom_character.talk("It’s a friend of mine - a Cheshire Cat - allow me to introduce it.");
    king.talk("I don’t like the look of it at all, however, it may kiss my hand if it likes.");
    cheshirecat.talk("I'd rather not.");
    king.talk("Don’t be impertinent , and don’t look at me like that!");
    std::cout << "The cat was eying the king up and down. Almost as if looking at a meal\n";
    custom_character.talk("A cat may look at a king; I've read that in some book, but I don’t remember where.");
    king.talk("Well, it must be removed");
    std::cout << "He turned to beckon the queen. \n";
    king.talk("My dear! I wish you would have this cat removed!");
    std::cout << "She resorted to her usual remark. \n";
    queen.talk("Off with his head!");
    king.talk("I'll fetch the executioner myself");
    std::cout << "He hurried off to fetch the executioner\n";
    std::cout << "You turn around and head back to the game, as it was your turn, or at least as close as it could be to your turn in this chaos \n";
    std::cout << "After playing your turn and hitting your `hedgehog` ; you turned back around to check on the Cheshire Cat\n"
                 "As soon as you start to approach, you notice a large gathering of people and hear the Queen, the King and the Executioner all arguing. \n"
                 "It seems the executioner didn't want to kill the cat, as he has a fondness of animals, but not people. \n";
    std::cout << "You interject, trying to calm them down. \n";
    custom_character.talk("It belongs to the Duchess, perhaps you should ask her about it.");
    queen.talk("She's in prison");
    std::cout << "She turned to the executioner \n";
    queen.talk("Fetch her here.");
    std::cout << "As he ran away, you notice the Cheshire Cat seems to be getting thinner. As if disappearing into thin air \n"
                 "Once he is gone, everyone is running around frantically trying to find him. \n"
                 "The Executioner returned with the Duchess and joined the madness. \n";

    // talk with the duchess

    // after talking with her, and resting for a bit
    std::cout << "In exchange for your help, the Duchess has offered to let you rest overnight at her house. At this point, you have had a very long day, \n"
                 "Not to mention, the day has been full of adventure. Perhaps a rest is in need. \n";

    std::cout << "You rest your eyes, and seem to sleep. No dreams, No nightmares, just wait feels like a tranquil rest. \n";
    std::cout << "You almost feel like you never slept, and are awoken by yelling and panic from the Duchess...\n";
    duchess.talk("Oh dear we need to get going come come lets go lets go!!");

    // talk to the duchess, if correct path, she gives you article of clothing to wear

    std::cout << "You set out with your troupe; the Duchess, the Mad Hatter and somewhere in the midst, though not in sight is the Cheshire Cat. \n";

    std::cout << "You are on your way to the large Castle, finally, with hopes to put an end to this wonderful adventure. \n";

    // end meeting the queen.














    }

    };