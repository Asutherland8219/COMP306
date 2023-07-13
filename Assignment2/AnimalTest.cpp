//
// Created by alex on 10/07/23.
//
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
