The Problems
Problem 1

Write a class called Animal with a default sound() method that does not output a specific animal sound. Instead, the generic output should be the statement, An animal makes a sound based on the animal that it is. The default constructor for Animal should also print I am an animal to standard output.

Create child classes for the following animals:

    pig
    sheep
    duck
    cow

The default constructor should print out I am a xxx, where xxx is the name of the animal. Create a sound() method for each new child class, which overrides the default method from the Animal class. The child class sound() method will print a different sound (word descriptor) for each animal, based on the child class:

    pig says “oink”
    sheep says “baah”
    duck says “quack”
    cow says “moo”

This sound() method does not generate an actual sound; it only prints the word descriptor to standard output.

Write a main() that creates several instances of each animal, and then calls each animal instance’s sound() method, so that different animals print different sounds accordingly.

Create another class called AnimalTest that reads the command line user input and creates the appropriate Animal child class based on the type of animal, and then calls the animal’s sound() method. Take some time to reflect on which class to create.

Problem 2

Define a class called Book. The Book class should store attributes, such as the title, ISBN number, author, edition, publisher, and year of publication. These attributes must be private.

Provide public get/set methods in this class to access these attributes. Test your Book class by creating several books and displaying the attributes.
 
Problem 3

Create a class called Elevator that can be moved between floors in an N-storey building. Elevator uses a constructor to initialize the number of floors (N) in the building when the object is instantiated.

Elevator also has a default constructor that creates a five- (5) storey building.

The Elevator class has a termination condition that requires the elevator to be moved to the main (i.e., first) floor when the object is cleaned up. Write a finalize() method that satisfies this termination condition and verifies the condition by printing a message to the output, Elevator ending: elevator returned to the first floor.

In main(), test at least five (5) possible scenarios that can occur when Elevator is used in a building with many floors (e.g., create, move from one floor to another, etc.).