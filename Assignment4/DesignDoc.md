Design doc for the Alice and Wonderland Text Based Game 

The overall structure is that of an intro, three checkpoint phases and a finale. The purpose of the checkpoints is that each pathway or scenario will have 
3 possible instances. Each instance is broken down as follows: 
- Happy Path (The best outcome for the block)
- Sub-optimal path ( A path with a mixture of outcomes, some happy some sad)
- Bad path/ Death (The character, Alice, dies and the user is forced to return to the checkpoint)

** Death will not be very violent or descriptive. In some instances it may actually be 
the incapacitation of the character that results in them returning to the checkpoint**

The intro section will have one path, think of it like a tutorial. It is a preset path that sets up the story and regardless of decision, the final outcome of the intro
will be the same. 

Checkpoint 1 introduces more decisions and outcomes as well as the ability to die. 

Checkpoint 2, will follow a similar structure but also allow some saving grace. If they took a bad path or sub-optimal path
they will have the ability to improve their current standing. 

The outcome of checkpoint 2 will decide the options in checkpoint 3. 

Checkpoint 3 will have no death component and will always make sure to move towards the ending

The finale, or ending, will have no ability to retcon or fix previous decisions. This block is predetermined 
by the previous blocks. As noted, there will be 3 outcomes available for the user. Basically written as:
- Bad ending (Death)
  - Not really "Death" but an ending that is non-satisfactory to the goal
- Suboptimal - basically just a normal ending, actions did nothing
- Happy ending - Considered the explorers ending, this means the player exhausted many paths and picked up almost every item.

________________________________________________________

The story is frame as the user being Alice. Alice stumbles into a magical forest while out for a walk foraging. Upon entering the forest 
she falls down a black hole into Wonderland. 

Her goal, at the beginning of the game, is to escape Wonderland and return to her world. 
She has no idea where to go but can see in the distance a LARGE beautiful castle. Perhaps they could be of assistance...

The main story is quite verbose and has many characters. For brevity and time-constraints, I will be taking some creative liberties in speeding up  the story. 
The beginning and entering the world will be the same, till around chapter 2. Once chapter 2, the pool of tears is completed, I will be condensing chapter 3, 4 followed 
by skipping chapter 5 (as it is filler). Then will move to 6 introducing the Cheshire cat and the duchess. Then I will move to the tea party followed by the last two chapters marking 
the conclusion of the story. 

In note form, the overarching story is as follows:
1. Enter Wonderland (either by choice or not).
2. Try and find your way out (dealing with the door).
3. Interact with Characters, like the White Rabbit, helping them along the way.
4. Meet the Duchess. 
5. Visit the garden and meet the cards.
6. Attend the tea party.
7. Play Croquet with the Queen.
8. Save the Duchess.
9. Attend the Trial in the Castle.
10. Defend your innocence!

All throughout this journey, you are trying to escape wonderland and get back home. Hoping that getting to the Castle and/or interacting with the Queen will give you more insight.

_________________________________________________________
The main components in the project are Character, NPC, Inventory, and Quests. 

- Character
  - The character you create in the intro, will be customizable.
  - Has a talk function with specialized styling
  - Has Inventory associated with it, where Item objects are stored.
  - Has Quests associated with it, where all Quest objects are stored.
- NPC
  - Parent class for all the NPC (Non-Playable Characters) in the story.
  - Each character has a child class that inherits from the NPC base class.
    - ex. WhiteRabbit : NPC
  - Has a talk function with specialized styling
- Inventory
  - A list of Item objects the user collects.
    - Item is a simple object containing a name, description and value.
  - Contains functions to list, add, remove and check objects.
  - Key component and is used to determine ending
- Quests
  - A list of Quest objects that are assigned to the user as they traverse the story.
    - Quest is an object containing a string (the name of the quest), and a status box, []
      - The box is marked with an x once completed
      - Has functions to complete Quest objects marking with x
  - Contains functions to list the Quest objects, add new Quest objects

Other pertinent components are under the UniversalFunctions directory:
  - CheckFunctions
    - Function to check that an item exists in the inventory
  - ClearFunctions
    - Created, but not used, was originally designed to clear the terminal.
  - TextFormatting
    - Text formatting functions for styling
      - Bold
      - Italic
      - Bold and Italic
  - UserInput
    - The main input function. Used for every instance in which the user must input a value for a decision.Sub function is used as terminal break
      - Allows the user to exit the program outright, access help menu, list inventory and list Quests
      - Sub function, just prompts the user to press enter to continue. This is used to split up the large text blocks making for a better UI experience

FinaleChoices
- This function is used to calculate the possible endings. It sums up the inventory and returns the appropriate ending.
- Many of the paths in the story result in Items being added to Inventory. If the user takes the optimal path, they will have many inventory items and satisfy the happy path ending.
_________________________________________________________

The project will have text code using gtest, (GoogleTest). While researching test methods in C++ I found that no such internal 
tooling existed. 

~~The gtests will be used to test chapters and logic around quests, inventory etc...
The tests will not be comprehensive, and instead focus on more problematic areas.~~ 

Upon further investigation of Gtest, I found it was not sufficient for what I wanted to test. I opted to build my own testing and use 
built-in assert functions to assess validity.

Two test function files exist:
1. Path Test
   2. Test that the users choices have resulted in the correct ending.
3. Section Test
   4. Used for debugging, test each section and make sure each is performing correctly.
   5. Used in order to test sections faster than running through the game top to bottom.
   6. Essentially, unit tests.

