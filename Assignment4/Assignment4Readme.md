Your Game

The game you write for this assignment is based on the book Alice’s Adventures in Wonderland by Lewis Carroll, also known as Alice in Wonderland. You may base your game on either the book by Lewis Carroll or one of the movie adaptations of the book.

Alice’s Adventures in Wonderland is in the public domain. You can access a copy of the work online through Project Gutenberg.

Alice in Wonderland makes for an entertaining adventure game, because there are many rooms (scenes), as well as a number of key characters and situations you may employ in your game.

You are not expected to follow the entire plot of the book, nor are you expected to program the entire book, all the items, or all the characters.

Rather, your game is to be an adaptation of the book into the form of an adventure game in which your character—Alice, perhaps—sees various scenes and characters and can interact with them and with the items found in their vicinity. There is no requirement that your main character (i.e., you, the player) represents Alice, although this is probably the most common choice.

For example, you may start your game as Alice, above ground, who encounters the white rabbit and talks to him. Eventually, you find the rabbit hole and fall down to the room containing “eat me” and “drink me.” Consuming these items will presumably have the same effect as in the book.

Likewise, you may interact with the Cheshire Cat, the Mad Hatter and other book characters. Prolonged interaction with the Red Queen will, presumably, prove to be unfortunate.

Ultimately, you will decide how the book characters, scenes and items “come to life” in your game.
Project Requirements

The game must employ object-oriented principals for all the components. That means the highest class is Game—your finished game. You may choose to call this main class Wonderland or another appropriate name. The Game class should have one main() method that creates an instance of the game and invokes it for game execution. Within Game, necessary classes must include Locations, Items, Characters, Actions, Inventory and Control. You may find more classes are necessary to complete the game.

The Control class is the class that reads user input and checks the input against valid Actions. If an Action is allowed, then the methods required to complete the action should be called on the objects involved (e.g., Action: “take”; object involved: “flashlight”). Certain actions will result in changes in the user’s inventory. Other actions will change the user’s location. Changes in location will trigger appropriate descriptive outputs based on the room entered and whether it is the first time entering.

Give careful consideration to your how the objects (classes) in your game interact.

Your game can contain any reasonable number of locations (rooms), with a minimum of five (5). A common starting point is near the rabbit hole, and the ending point is somewhere in wonderland. Once you descend into the rabbit hole, you are unable to return. Otherwise, the locations (rooms) and how you connect them is your design choice, which MUST be completely documented as part of the design documents for the game. You should create a “safe room” to act as a gathering area for your treasures.

Locations should have a minimum of one entrance and one exit (not the same), but at least one room must have more than three (3) exits.

You must portray a minimum of five (5) characters from the book. You must have a minimum of 12 items for the main character to interact with, which should be taken from the book.

You will need to establish a goal for the main character (e.g., Alice), and you must state this at the beginning of the game.

The items, characters, location descriptions and action words should be contained in separate text files, which are opened and loaded into the game at the start of the game.