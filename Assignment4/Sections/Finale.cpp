//
// Created by asuth on 12/13/2023.
//

// Start ch.11, Who stole the tarts

class Finale {
private:
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
    Duchess duchess;
    Cook cook;
    Mouse mouse;

    Character TheEnd(Character custom_character) {
        std::cout << "You arrive at the castle, and are in total shock and awe at the large gates. \n";
        custom_character.talk("my oh my these doors are huge");
        duchess.talk("Yes the Queen is known for being extravagant. These may be a a bit over the top.");
        duchess.talk("Come now, we don't want to be late");
        std::cout << "The duchess guides us along towards where we are supposed to go \n"
                     "You arrive again, at a large set of doors. Once arriving, the duchess, instead of asking, simply coughs multiple times to get the Hare and Mad Hatters attention \n"
                     "You notice them not paying any attention \n";

        // print break
        getUserInput(custom_character, true);

        // Add choices between kicking them, yelling at them, doing it yourself etc

        std::cout << "Once the doors open, you see the King and Queen, sat on their throne, with a great crowd assembled around them. \n"
                     "all sorts of little birds and beasts, as well as the whole pack of cards: the Knave was standing before them, in chains, with a soldier on each side to guard him;\n "
                     "and near the King was the White Rabbit, with a trumpet in one hand, and a scroll of parchment in the other. \n"
                     "In the very middle of the court was a table, with a large dish of tarts upon it.";
        std::cout << "The King, was wearing a goofy wig, indicating that he was the judge. \n"
                     "Just adjacent to him, was a box of 12 jurors, most of whom were an animal of some sort\n";
        rabbit.talk("Silence! Silence in the court!");
        king.talk("Herald, read the accusation!");
        std::cout << "The rabbit, blew on a trumpet three times, indicating the start of the adjudication \n";
        rabbit.talk("The Queen of Hearts, she made some tarts,\n"
                    "    All on a summer day:\n"
                    "The Knave of Hearts, he stole those tarts,\n"
                    "    And took them quite away!");
        king.talk("Consider your verdict");

        // print break
        getUserInput(custom_character, true);

        rabbit.talk("Not yet, Not yet!");
        std::cout << "The rabbit looked terrified as he interrupted the king. But he continued... \n";
        rabbit.talk("There's a great deal to come before that!");
        king.talk("Call the first witness then!");
        rabbit.talk("First witness! Come forth!");
        std::cout << "It seems the Mad hatter was the first, but he was not known of this, and was the midst of having tea and bread with butter. \n"
                     "He approached the bench, moving to the witness seat and turned to the King.\n";
        mad_hatter.talk("I beg pardon your Majesty, for bringing these in, but I hadn't quite finished my tea when I was sent for.");
        king.talk("You ought to have finished, when did you begin?");
        std::cout << "The Mad Hatter, looked to the March Hare for assistance on this \n";
        mad_hatter.talk("Fourteenth of March I believe it was.");
        march_hare.talk("The fifteenth actually");
        mad_hatter.talk("Are you certain? I do believe it was the fourteenth but if you say fifteenth so be it.");
        std::cout << "The king turned to the jury. \n";
        king.talk("Write that down! write that down!");
        king.talk("Take off your hat, Mad Hatter");
        mad_hatter.talk("It isn't mine");
        king.talk("STOLEN! A THIEF!");

        // print break
        getUserInput(custom_character, true);


        mad_hatter.talk("I keep them to sell, I've none of my own. I am a hatter");
        std::cout << "Here the Queen put on her spectacles, and began staring at the Hatter, who turned pale and fidgeted.\n";
        king.talk("Give your evidence, and don't be nervous, or I'll have you executed on the spot.");
        std::cout << "he kept shifting from one foot to the other, looking uneasily at the Queen, and in his confusion he bit a large piece out of his teacup instead of the bread-and-butter.";
        queen.talk("Bring me the list of the singers in the last concert!");
        std::cout << "The King turned to the Mad Hatter, glaring at him and repeated himself in a stern tone.";
        king.talk("Give your evidence, or I’ll have you executed, whether you’re nervous or not.");
        std::cout << "The Hatter, responded with a tremble in his voice. \n";
        mad_hatter.talk("I'm a poor man, your Majesty, -and I hadn’t begun my tea—not above a week or so-and what with the bread-and-butter getting so thin-and the twinkling of the tea-");
        king.talk("The twinkling of the what?");
        mad_hatter.talk("It began with the tea,");
        king.talk("Of course twinkling begins with a T! Do you take me for a dunce? Go on!");
        mad_hatter.talk("I'm a poor man, and most things twinkled after that-only the March Hare said-");
        march_hare.talk("I didn't!");
        mad_hatter.talk("You did!");
        march_hare.talk("I deny it!");
        king.talk("He denies it, leave out that part");

        // print break
        getUserInput(custom_character, true);

        std::cout << "The tremble in the Mad Hatters voice got progressively worse as he kept speaking.\n";
        king.talk("You're a very poor speaker,");
        std::cout << "One of the jurors, a guinea pig, cheered at this remark.";
        king.talk("SILENCE IN THE COURT");
        std::cout << "The court silences instantly. \n";
        king.talk("If that's all you know about it, you may stand down,");
        mad_hatter.talk("I can't go no lower; I'm on the floor as it is.");
        king.talk("Then you may sit down,");
        mad_hatter.talk("I'd rather finish my tea.");
        king.talk("Then you may go.");
        std::cout << "The Mad Hatter scurried away -- \n";
        queen.talk("—and just take his head off outside,");
        std::cout << "The Queen said this to one of the officers, but at this point the Mad Hatter was long gone out the door. \n";
        king.talk("Call the next witness!");
        std::cout << "The next witness, was the Duchess' Cook. He looked at you and smiled before approaching.\n";
        king.talk("Give your evidence");
        cook.talk("Shan't");

        // print break
        getUserInput(custom_character, true);

        std::cout << "The King turned to look at the White Rabbit with an angry glare.\n";
        rabbit.talk("Your Majesty mush cross examine this witness.");
        std::cout << "The King took a deep breath and let out a sigh \n";
        king.talk("What were the tarts made of?");
        mouse.talk("Treacle");
        std::cout << "When the mouse spoke up, from a drowsy state, as he was sleeping in the stands \n"
                     "This caused some uproar in the courtroom and some responses from the jury.\n";
        king.talk("Never mind! Everyone, SILENCE!");
        std::cout << "After a minute or two, he continues. \n";
        king.talk("Bring the next witness!");
        std::cout << "He turned to talk to the Queen. \n";
        king.talk("Really my dear, you must cross-examine the next witness. It quite makes my forehead ache!");
        std::cout << "The Rabbit fumbled with the list and then yelled out: \n";

        // print break
        getUserInput(custom_character, true);

        std::string response = "The next witness is " + custom_character.name + "!";
        rabbit.talk(response);

        std::cout << "You turn ghastly white, then notice all eyes are on you. Nervously you make your way to the stand. \n";

        king.talk("What do you know about this business?");

        // Add section about discussion in court

        textFormatter::printBoldItalic("END CHAPTER 3/FINALE");




















        return custom_character;
    }
};
