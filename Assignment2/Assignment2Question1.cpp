/*
 Title: Assignment2Question1.cpp
 Description: The Animal Class
 Date: September 14th, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create a super/parent Animal class along with specific animal instances

 Compile (assuming Cygwin is running): g++ -o Assignment2 Assignment2Question1.cpp
 Execution (assuming Cygwin is running): ./Assignment2Question1.exe

 Classes (functions):
	- Animal (Super/Parent Class)
        - Pig : Pig Animal child class
        - Sheep : Sheep Animal child class
        - Duck : Duck Animal child class
        - Cow : Cow Animal child class

        The parent Animal class has a function, sound. The sound function prints a description of
        what sound the animal would make.

        Each child class has their own unique sound.

 Variables:
 	animalType: string

    The variable is overridden by the default output of  the child class. If no default output is given, "animal" is printed
*/

/*
 TEST PLAN

 Normal case:
 	> Animal()
 	    Output: " I am an animal "

        Animal.sound()
        Output: "An animal makes a sound based on the animal that it is"

 	> Pig()
 	    Output: " I am a Pig "

        Animal.sound()
        Output: "The pig says 'oink'. "

 	> Duck()
 	    Output: " I am a Duck "

        Animal.sound()
        Output: "The duck says 'quack'. "

 	> Sheep()
 	    Output: " I am a Sheep"

        Animal.sound()
        Output: "The sheep says 'baah'."

 	> Cow()
 	    Output: " I am a Cow"

        Animal.sound()
        Output: "The cow says 'moo'. "


 Bad Case
 	> No input exists, each of the return values are hard coded so bad cases are essentially none.
 	> Any issues would be in compiling/building


 Discussion:
 	Very simple program with 2 outputs. One declaring the name of the animal,
 	another declaring the sound the animal would make.

*/

#include <iostream>
#include <any>
#include <algorithm>

using namespace std;
bool print_statement = true;


class Animal {
public:


    Animal(const std::string& animalType = "animal") {
        // Default constructor for the Animal class
        if (print_statement) {
            cout << "I am an " << animalType << "." << endl;
            print_statement = false;
        }


    }

    virtual void sound()  {
        // default sound method for the animal class
        cout << "An animal makes a sound based on the animal that it is" << endl;

    }
};

class Pig: public Animal {
public:
    Pig(){
        // default output
        cout << "I am a pig." << endl;
    }

    void sound() override {
        cout << "The pig says 'oink'. " << endl;
    }
};

class Sheep: public Animal {
public:
    Sheep() {
        // default output
        cout << "I am a sheep." << endl;
    }

    void sound() override {
        cout << "The sheep says 'baah'. " << endl;
    }
};

class Duck: public Animal {
public:
    Duck() {
        // default output
        cout << "I am a duck." << endl;
    }

    void sound() override {
        cout << "The duck says 'quack'. " << endl;
    }
};
class Cow: public Animal {
public:
    Cow() {
        //default output
        cout << "I am a cow." << endl;
    }

    void sound() override {
        cout << "The cow says 'moo'. " << endl;
    }
};

/*
 Title: Assignment2Question1Test.cpp
 Description: The Animal Class
 Date: September 14th, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create a super/parent Animal class along with specific animal instances

 Compile (assuming Cygwin is running): g++ -o Assignment2 Assignment2Question1Test.cpp
 Execution (assuming Cygwin is running): ./Assignment2Question1Test.exe

 Classes (functions):
	- Animal (Super/Parent Class)
        - Pig : Pig Animal child class
        - Sheep : Sheep Animal child class
        - Duck : Duck Animal child class
        - Cow : Cow Animal child class

        The parent Animal class has a function, sound. The sound function prints a description of
        what sound the animal would make.

        Each child class has their own unique sound.

 Variables:
 	animalType: string

    The variable is overridden by the default output of  the child class. If no default output is given, "animal" is printed
*/

/*
 TEST PLAN

 Discussion:
 	A input test function for the animal class, allows the user to input animal in order to hear its sound.
 	If any of the input values are not in the defined animals, An error, invalid selection error is raised.

*/

class AnimalTest {
public:
    static bool Test(std::string &animal) {
        // Test function for the animal class, where the animal class is a string
        bool valid = false;
        std::transform(animal.begin(), animal.end(), animal.begin(), ::toupper);

        if (animal == "PIG") {
            Pig pig;
            pig.sound();
            valid = true;

        } else if (animal == "SHEEP") {
            Sheep sheep;
            sheep.sound();
            valid = true;


        } else if (animal == "DUCK") {
            Duck duck;
            duck.sound();
            valid = true;

        } else if (animal == "COW") {
            Cow cow;
            cow.sound();
            valid = true;
        }
        else if (animal == "X") {
            cout << "Exiting program now. Thank you. \n";
            valid = true;
        }
        // Bad case checks. One offense is fine, 2nd lists options, 3rd exits
        else {
            cout << "Invalid selection. Please select one of the preset animals. \n";
            cout << "The options are: pig, sheep, duck or cow. \n";
            cout << "If you want to quit the program, enter x. \n";
        }
        return valid;
    }
};


