
// Created by asuth on 12/13/2023.
//

#include <iostream>
#include <string>
#include "../Gates/Chapter_2/ChapterTwo.cpp"
#include "../Character/Character.h"
#include "../NPC/NPC.h"
#include "../UniversalFunctions/userInput.cpp"

class Checkpoint2 {
private:
    // gate breakers
    bool cook_breaker;
    bool cat_breaker;
    bool small_door_breaker;
    bool gardener_breaker;
    bool queen_breaker;
    bool gardener_save_breaker;

public:
    Character Chapter2(Character custom_character) {
        ChapterTwoGates ch_two_gates;
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

        // Items
        Item red_mushroom("Red Mushroom", "A mushroom with a red cap and yellow spots", 0);
        Item blue_mushroom("Blue Mushroom", "A mushroom with a blue cap and white spots", 0);

        std::cout
                << "There was a table set out under a tree in front of the house, and the March Hare and the Hatter were having tea at it: a Dormouse was sitting between them, fast asleep, \n"
                   " and the other two were using it as a cushion, resting their elbows on it, and talking over its head. \n"
                   "The table was a large one, but the three were all crowded together at one corner of it: \n"
                   "You approach the table and sit down at a vacant seat. \n";
        march_hare.talk("Have some wine");

        std::cout << "You looked all round the table, but there was nothing on it but tea. \n";
        custom_character.talk("I don’t see any wine");

        march_hare.talk("There isn’t any");

        custom_character.talk("Then it wasn't very civil of you to offer it");

        march_hare.talk("It wasn't very civil of you to sit down without being invited");

        custom_character.talk(
                "You called me over! Did you not want me to sit? I didn't know it was your table, it’s laid for a great many more than three.");

        mad_hatter.talk("Your hair wants cutting");

        std::cout << "He had been watching you inquisitively during your conversation with the March Hare \n";

        custom_character.talk("You should learn not to make personal remarks; it's very rude.");

        std::cout << "In response to this remark, the Mad Hatter was wide eyed and in shock. \n";

        mad_hatter.talk("Why is a raven like a writing-desk?");

        std::cout << "You think to yourself, `oh joy, some riddles`";

        custom_character.talk("I do not know.");

        march_hare.talk("Do you mean that you think you can find out the answer to it?");

        custom_character.talk("Exactly so");

        march_hare.talk("Then you should say what you mean");

        custom_character.talk(
                "Did I not say what I mean? I said I do not know, care to share the answer to your riddle?");

        std::cout << "and here the conversation dropped, and the party sat silent. \n"
                     "After a few minutes, the Mad Hatter broke the silence. \n ";

        mad_hatter.talk("What day of the month is it?");
        std::cout
                << "he turned to you and he had taken his watch out of his pocket, and was looking at it uneasily, shaking it every now and then, and holding it to his ear. \n";

        custom_character.talk("From where I cam from, The fourth.");

        mad_hatter.talk("Two days wrong!");

        std::cout << "He turned and glared at the March Hare";
        mad_hatter.talk("I told you butter wouldn't suit the works!");

        // grab the mushrooms
        std::cout
                << "While he was turned to talk and argue with the, you peruse the table for anything that might be useful on the table...\n";
        std::cout
                << "You see two mushrooms, one blue and one red. You grab a piece of both and slip them into your pocket.\n";
        // add the mushrooms
        Character::addItemToInventory(red_mushroom);
        Character::addItemToInventory(blue_mushroom);

        march_hare.talk("It was the best butter");

        mad_hatter.talk(
                "Yes, but some crumbs must have got in as well ; you shouldn't have put it in with the bread-knife.");

        std::cout
                << "The March Hare took the watch and looked at it gloomily: then he dipped it into his cup of tea, and looked at it again: but he could think of nothing better to say \n";
        std::cout << "It seems the conversation has reached a stalemate. This is a good time to leave. \n";

        custom_character.talk("Well, Gentleman, it has been a pleasure but I must be going. ");
        std::cout << "You push back your chair, and stand up, bowing down to be polite (even though they weren't) \n"
                     "As you walk away, you can hear them still bickering with one another. \n";
        std::cout
                << "When you return inside the house, you see the cook walking by. He flashes you a friendly smile. \n";

        while (!cook_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Smile back, letting him go on his merry way.\n";
            std::cout << "2. Stop him and ask some questions; perhaps he knows something about the mushrooms. \n";
            std::cout << "3. Apologize for not standing up for him earlier. \n";

            auto input1_ch2 = getUserInput(custom_character);
            std::istringstream iss(input1_ch2);
            int cook;
            if (iss >> cook) { // Attempt to read an integer from the input
                cook_breaker = ch_two_gates.cookChoice(cook, custom_character);
            }
        }

        std::cout
                << "You stop for a moment and think, `where to go now? I suppose I should try and reach the Queen, to see if she knows how to leave Wonderland.`";

        // add attempt to call to the cat, seeing if it can help you
        std::cout << "A thought crosses your mind, `what if the cat knows anything helpful, it disappeared before I had a chance to talk to it`";

        custom_character.talk("Mr kitty, hello can you hear me? I may not be able to see you but maybe you are still listening. Pspspspsps here kitty kitty.");

        cheshirecat.talk("I do not appreciate these mundane callings. I am no ordinary feline you know. Additionally, my name is Cheshire Cat, not kitty kitty...");

        std::cout << "You hear the cat talking but don't see him yet. \n"
                     "Suddenly, you turn to face the living room area and see a shape slowly appearing in the doorway. First you see the sharp teeth and two big eyes. \n"
                     "This time though, they do not look friendly and instead look quite perturbed and disgruntled at your remarks/\n";

        while (!cat_breaker) {
            std::cout << std::endl;
            std::cout << "What would you like to do?\n";
            std::cout << "1. Apologize profusely, hoping to get back on the cats good side.\n";
            std::cout << "2. Apologize, and quickly ask a follow up question, hoping to distract the cat into answering. \n";
            std::cout << "3. Double down, mock the cat for being offended. \n";

            auto input2_ch2 = getUserInput(custom_character);
            std::istringstream iss(input2_ch2);
            int cat;
            if (iss >> cat) { // Attempt to read an integer from the input
                cat_breaker = ch_two_gates.catChoice(cat, custom_character);
            }
        }

        std::cout << "You return back to the room with the tiny door. Hoping to see something has changed. \n"
                     "Unfortunately, once you get there, you see the large table and the small locked door. ";

        // Add inventory check for Fan to shrink, red mushroom to grow, blue mushroom to shrink
        // if fan, use fan, if red mushroom grow large get key then use blue mushroom or fan to shrink
        // if no items, simply run up and kick the door repeatedly yelling for help... it magically opens

        // Assuming you have characters named Five, Seven, and custom_character
// Use Five.talk, Seven.talk, and custom_character.talk for their respective lines

        std::cout
                << "A large rose-tree stood near the entrance of the garden: the roses growing on it were white, but there were three gardeners at it, busily painting them red. \n"
                   "Normal Gardeners they were not, for they were shaped like playing cards, each with a number and house. \n"
                   "You stand and watch them, and hear one of them speak: ";
        two.talk("Look out now, Five! Don't go splashing paint over me like that!");
        five.talk("I couldn't help it; Seven jogged my elbow.");
        seven.talk("That's right, Five! Always lay the blame on others!");
        five.talk("You'd better not talk! ; I heard the Queen say only yesterday you deserved to be beheaded!");
        two.talk("What for?");
        seven.talk("That’s none of your business, Two!");
        five.talk(
                "Yes, it is his business! and I'll tell him—it was for bringing the cook tulip-roots instead of onions.");
        std::cout << "Seven flung down his brush \n";
        seven.talk("Well, of all the unjust things—");
        std::cout
                << "he turned as he was speaking and spotted you standing there. Once he saw you and stopped talking the others turned and looked at you as well... \n"
                   "Suddenly they started bowing towards you. \n";

        // Insert talking sequence asking questions.


        // Assuming you have characters named Two, custom_character, Queen, King, Knave, and soldiers
// Use Two.talk, custom_character.talk, Queen.talk, King.talk, Knave.talk, soldiers.talk for their respective lines

        std::cout << "Five and Seven said nothing, but looked at Two. \n";
        two.talk(
                "Why the fact is, you see, Miss, this here ought to have been a red rose-tree, and we put a white one in by mistake; and if the Queen was to find it out, we should all have our heads cut off, you know.");
        two.talk("So you see, Miss, we're doing our best, afore she comes, to—");
        std::cout << "At this moment Five, who had been anxiously looking across the garden spoke up: ";
        five.talk("The Queen! The Queen!");
        std::cout << "and the three gardeners instantly threw themselves flat upon their faces."
                     "There was a sound of many footsteps \n"
                     "Then came a large army of similar designed characters to the gardeners, all surrounding the four of them. \n"
                     "Finally, then came the Queen and the King. She spoke, addressing the one named two: ";
        queen.talk("Who is this?");
        std::cout << "Tow only bowed and smiled in reply. \n";
        queen.talk("Idiot!");
        std::cout << "She turned to look at you. \n";
        queen.talk("What’s your name, child?");
        std::string response = "My name is " + custom_character.name + " so pleased to meet you your Majesty";
        custom_character.talk(response);
        queen.talk("And who are these?");
        std::cout << "She pointed to the three gardeners bowing down on the ground. \n";

        // Use lowercase names and replace Alice with custom_character
        custom_character.talk("How should I know?; It’s no business of mine.");
        std::cout
                << "The queen turned crimson with fury, and, after glaring at her for a moment like a wild beast, screamed:";

        queen.talk("OFF WITH HER HEAD -- OFF WITH--");

        // Add talking choice here
        custom_character.talk("Nonsense!");

        std::cout << "The King laid his hand upon her arm, and timidly said : ";
        king.talk("Consider, my dear: she is only a child!");
        std::cout << "The Queen turned towards the face down cards and yelled : ";
        queen.talk("Get up!");
        std::cout << "They slowly stood up, as they were standing, she repeated herself in a more shrill tone: ";
        queen.talk("Get up!");
        std::cout
                << "the three gardeners instantly jumped up, and began bowing to the king, the queen, the royal children, and everybody else.";

        queen.talk("Leave off that!; You make me giddy. ; What have you been doing here?");

        two.talk("“May it please your majesty, we were trying—");

        queen.talk("I see!...  Off with their heads!");

        std::cout
                << "and the procession moved on, three of the soldiers remaining behind to execute the unfortunate gardeners, who ran towards you for protection.";

        custom_character.talk("You shan’t be beheaded!");

        //and she put them into a large flower-pot that stood near.");

// Assuming you have characters named queen, custom_character, and soldiers
// Use lowercase names and replace Alice with custom_character
        queen.talk("Are their heads off?");

        soldiers.talk("Their heads are gone, if it please your majesty!");

        queen.talk("That’s right! ; Can you play croquet?”");

        std::cout << "The soldiers were silent, and looked at you as the question was evidently meant for you.";

        custom_character.talk("Yes!");

        queen.talk("Come on, then!");

        std::cout << "You join the procession, heading to play croquet with the Queen. \n";

        rabbit.talk("It’s—it’s a very fine day!");

        std::cout << "You were walking by the White Rabbit, who was peeping anxiously into your face.";

        custom_character.talk("“Very, —where’s the duchess?");

        rabbit.talk("Hush! Hush!");

        std::cout
                << "He looked anxiously over his shoulder as he spoke, and then raised himself upon tiptoe, put his mouth close to her ear, and whispered :";
        rabbit.talk("She's under sentence of execution.");

        custom_character.talk("What for?");

        rabbit.talk("Did you say What a pity!?");

        custom_character.talk("No, I didn't, I don’t think it's at all a pity. I said What for?");

        rabbit.talk("She boxed the queen’s ears—");

        custom_character.talk("HAHAHAHAHAHAHAHAHAHAHAHAH you're kidding right? That is hilarious!");

        rabbit.talk("Oh, hush! ; The queen will hear you! You see, she came rather late, and the queen said—");


    return  custom_character;







    };
};