//
// Created by asuth on 2/18/2024.
//

#include "TheEnd.h"
#include "../../UniversalFunctions/userInput.h"

bool ChapterFourGates::court_breaker;
bool ChapterFourGates::attention_breaker;
Duchess ChapterFourGates::duchess;
Queen ChapterFourGates::queen;
WhiteRabbit ChapterFourGates::rabbit;
King ChapterFourGates::king;

bool ChapterFourGates::attentionChoice(int attention_choice, const Character& custom_character) {

    switch (attention_choice) {
        case 1:
            std::cout << "You kick them in the arse, trying not to hold back, reminding yourself of their remarks earlier. \n"
                         "They both let out a yelp, but then turn to face the Duchess, and then spin around and rush toward opening the doors. \n";
            attention_breaker = true;
        case 2:
            std::cout << "You flick them both in the ears. They both turn towards you angrily, then notice the Duchess looking at them, waiting.\n"
                         "They turn on a dime, and rush towards opening the doors. \n";
            attention_breaker = true;
        case 3:
            std::cout << "You pretend not to pay attention, wanting to see what would happen. \n";
            duchess.talk("OPEN THE DOOR YOU BUFFOONS");
            std::cout << "The Mad Hatter and the March Hare, both nearly leap out of their skin, and bolt towards the door pushing them open. \n";
            attention_breaker = true;
    }
    return attention_breaker;
}

bool ChapterFourGates::courtChoice(int court_choice, const Character& custom_character) {

    switch (court_choice) {
        case 1:
            custom_character.talk("I know nothing, nothing at all. I just got here.");
            king.talk("You know nothing? Nothing whatever?");
            custom_character.talk("Nothing Whatever.");
            king.talk("That's very important");
            rabbit.talk("Unimportant, your Majesty means of course");
            std::cout << "The rabbit said nervously";
            king.talk("Unimportant, of course I meant -- important, unimportant, unimportant, important");
            king.talk("SILENCE");
            std::cout << "This took you by surprise and you jumped, as it wasn't overly loud at the time. \n";
            king.talk("Rule Forty-two. All persons more than a mile high to leave the court.");
            std::cout << "The jury, and the spectators, all look at you.";
            custom_character.talk("I am not a mile high.");
            king.talk("You are.");
            queen.talk("Nearly two miles high.");
            custom_character.talk(
                    "Well, I shan't go at any rate. Besides, that's not a regulation: you invented it right now.");
            king.talk("It's the oldest rule in the book.");
            custom_character.talk("Then it ought to be Number One.");
            std::cout << "With this remark, the king turned pale and shut his notebook hastily. \n";
            king.talk("Consider your verdict.");

            getUserInput(custom_character, true);

            rabbit.talk("There's more evidence to come yet, please your Majesty, this paper has just been picked up.");
            queen.talk("What's in it?");
            rabbit.talk("I haven't opened it yet. But it seems to be a letter written by a prisoner to somebody.");
            king.talk("It must have been that, unless it was written to nobody, which isn't usual, you know.");
            custom_character.talk("Who is it directed to?");
            king.talk("Silence on the stand!");
            rabbit.talk("It isn't directed at all, in fact there's nothing written on the outside.");
            std::cout << "He opened the letter. \n";
            rabbit.talk("It isn't a letter, after all. It's a set of verses.");
            queen.talk("In the prisoners handwriting?");
            rabbit.talk("No, it doesn't look like so.");
            king.talk("It must be a forgery, clearly it is this creatures handwriting.");
            std::cout
                    << "He pointed at you as he said that; it seems they don't have perpetrator, and are just putting everyone up on the stand as potential candidates.";
            queen.talk("This proves their guilt!");

            getUserInput(custom_character, true);

            custom_character.talk("This proves nothing of the sort! You don't even know what they're about.");
            std::cout << "You start getting sweaty and nervous \n";
            king.talk("Read them.");
            rabbit.talk("Where shall I begin, please your majesty?");
            std::cout << "The king sighed and rolled his eyes. \n";
            king.talk("Begin at the beginning, go on till you come to the end: then stop.");

            getUserInput(custom_character, true);

            rabbit.talk("They told me you had been to her,\n"
                        "    And mentioned me to him:\n"
                        "She gave me a good character,\n"
                        "    But said I could not swim.\n"
                        "\n"
                        "He sent them word I had not gone\n"
                        "    (We know it to be true):\n"
                        "If she should push the matter on,\n"
                        "    What would become of you?\n"
                        "\n"
                        "I gave her one, they gave him two,\n"
                        "    You gave us three or more;\n"
                        "They all returned from him to you,\n"
                        "    Though they were mine before.\n"
                        "\n"
                        "If I or she should chance to be\n"
                        "    Involved in this affair,\n"
                        "He trusts to you to set them free,\n"
                        "    Exactly as we were.\n"
                        "\n"
                        "My notion was that you had been\n"
                        "    (Before she had this fit)\n"
                        "An obstacle that came between\n"
                        "    Him, and ourselves, and it.\n"
                        "\n"
                        "Don’t let him know she liked them best,\n"
                        "    For this must ever be\n"
                        "A secret, kept from all the rest,\n"
                        "    Between yourself and me.");

            king.talk("That's the most important piece of evidence we've heard yet -- so now let the jury...");
            custom_character.talk(
                    "If any one of them can explain it, I'll give him sixpence. I don't believe there's an atom of of meaning in it.");
            king.talk(
                    "If there's no meaning in it, that saves a world of trouble, you know, as we needn't try to find any. And yet I don't know,");
            king.talk(
                    "All right, so far; We know it to be true- I gave her one, they gave him two- why, that must be what he did with the tarts, you know-");
            custom_character.talk("But, it goes on -- they all returned from him to you,");

            getUserInput(custom_character, true);

            king.talk("Why, there they are!");
            std::cout << "He stood up from his seat, and pointed to the tarts on the table \n"
                         "He turned to address the Queen.";
            king.talk(
                    "Nothing can be clearer than that. Then again- before she had this fit- you never had fits, my dear, I think?");
            queen.talk("Never!");
            king.talk("Then the words don't fit you,");
            king.talk("It's a PUN!");
            king.talk("Let the jury consider their verdict");
            queen.talk("No, No! - Sentence first, verdict afterwards.");
            custom_character.talk("Stuff and Nonsense!");
            queen.talk("Hold your tongue!");
            custom_character.talk("I won't");
            queen.talk("Off with their head!!");
            custom_character.talk("Who cares for you!? You're nothing but a pack of cards!");
            court_breaker = true;
            break;

        case 2:
            custom_character.talk("I plead the 5th");
            king.talk("The 5th, What is the 5th?");
            queen.talk("It is some made up rubbish, it's clear they did it! OFF WITH THEIR HEADS");
            king.talk("Silence dear.");
            king.talk("I override your 5th, either tell what you know, or I will separate your head from your body.");
            custom_character.talk("I decline to answer.");
            king.talk("Let the jury consider their verdict");
            queen.talk("No, No! - Sentence first, verdict afterwards.");
            custom_character.talk("Stuff and Nonsense!");
            queen.talk("Hold your tongue!");
            custom_character.talk("I won't");
            queen.talk("Off with their head!!");
            custom_character.talk("Who cares for you!? You're nothing but a pack of cards!");
            court_breaker = true;
            break;

        case 3:
            custom_character.talk("I know the tarts are on the table in front of us. What is there beyond that?");
            std::cout << "The king gave you a nasty glare. Then stood up and noticed them.";
            king.talk("ENOUGH!");
            king.talk("Jury, consider your verdict.");
            getUserInput(custom_character, true);

            rabbit.talk("There's more evidence to come yet, please your Majesty, this paper has just been picked up.");
            queen.talk("What's in it?");
            rabbit.talk("I haven't opened it yet. But it seems to be a letter written by a prisoner to somebody.");
            king.talk("It must have been that, unless it was written to nobody, which isn't usual, you know.");
            custom_character.talk("Who is it directed to?");
            king.talk("Silence on the stand!");
            rabbit.talk("It isn't directed at all, in fact there's nothing written on the outside.");
            std::cout << "He opened the letter. \n";
            rabbit.talk("It isn't a letter, after all. It's a set of verses.");
            queen.talk("In the prisoners handwriting?");
            rabbit.talk("No, it doesn't look like so.");
            king.talk("It must be a forgery, clearly it is this creatures handwriting.");
            std::cout
                    << "He pointed at you as he said that; it seems they don't have perpetrator, and are just putting everyone up on the stand as potential candidates.";
            queen.talk("This proves their guilt!");

            getUserInput(custom_character, true);

            custom_character.talk("This proves nothing of the sort! You don't even know what they're about.");
            std::cout << "You start getting sweaty and nervous \n";
            king.talk("Read them.");
            rabbit.talk("Where shall I begin, please your majesty?");
            std::cout << "The king sighed and rolled his eyes. \n";
            king.talk("Begin at the beginning, go on till you come to the end: then stop.");

            getUserInput(custom_character, true);

            rabbit.talk("They told me you had been to her,\n"
                        "    And mentioned me to him:\n"
                        "She gave me a good character,\n"
                        "    But said I could not swim.\n"
                        "\n"
                        "He sent them word I had not gone\n"
                        "    (We know it to be true):\n"
                        "If she should push the matter on,\n"
                        "    What would become of you?\n"
                        "\n"
                        "I gave her one, they gave him two,\n"
                        "    You gave us three or more;\n"
                        "They all returned from him to you,\n"
                        "    Though they were mine before.\n"
                        "\n"
                        "If I or she should chance to be\n"
                        "    Involved in this affair,\n"
                        "He trusts to you to set them free,\n"
                        "    Exactly as we were.\n"
                        "\n"
                        "My notion was that you had been\n"
                        "    (Before she had this fit)\n"
                        "An obstacle that came between\n"
                        "    Him, and ourselves, and it.\n"
                        "\n"
                        "Don’t let him know she liked them best,\n"
                        "    For this must ever be\n"
                        "A secret, kept from all the rest,\n"
                        "    Between yourself and me.");

            king.talk("That's the most important piece of evidence we've heard yet -- so now let the jury...");
            custom_character.talk(
                    "If any one of them can explain it, I'll give him sixpence. I don't believe there's an atom of of meaning in it.");
            king.talk(
                    "If there's no meaning in it, that saves a world of trouble, you know, as we needn't try to find any. And yet I don't know,");
            king.talk(
                    "All right, so far; We know it to be true- I gave her one, they gave him two- why, that must be what he did with the tarts, you know-");
            custom_character.talk("But, it goes on -- they all returned from him to you,");

            getUserInput(custom_character, true);

            king.talk("Why, there they are!");
            std::cout << "He stood up from his seat, and pointed to the tarts on the table \n"
                         "He turned to address the Queen.";
            king.talk(
                    "Nothing can be clearer than that. Then again- before she had this fit- you never had fits, my dear, I think?");
            queen.talk("Never!");
            king.talk("Then the words don't fit you,");
            king.talk("It's a PUN!");
            king.talk("Let the jury consider their verdict");
            queen.talk("No, No! - Sentence first, verdict afterwards.");
            custom_character.talk("Stuff and Nonsense!");
            queen.talk("Hold your tongue!");
            custom_character.talk("I won't");
            queen.talk("Off with their head!!");
            custom_character.talk("Who cares for you!? You're nothing but a pack of cards!");
            court_breaker = true;
            break;
    }

    std::cout << "As you yell this, the room starts moving, this time for real. All the characters start to float to the sky. \n"
                 "Then, they exploded into cards flying all over so much that it overcame you, almost like a drowning sensation... \n";

    return court_breaker;
}

