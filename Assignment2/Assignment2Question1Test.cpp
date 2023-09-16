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
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class AnimalTest {
public:
    explicit AnimalTest(std::string& animal){
        // Test function for the animal class, where the animal class is a string

        if (animal == "pig") {
            Pig pig;
            pig.sound();
        } else if (animal == "sheep") {
            Sheep sheep;
            sheep.sound();
        } else if (animal == "duck") {
            Duck duck;
            duck.sound();
        } else if (animal == "cow") {
            Cow cow;
            cow.sound();
        } else {
                cout << "Invalid selection. Please select one of the preset animals. \n";
        }

    }
};
