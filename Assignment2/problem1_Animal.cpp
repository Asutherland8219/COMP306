//
// Created by alex on 08/07/23.
//

#include <iostream>
using namespace std;

class Animal {
public:

    Animal(const std::string& animalType = "animal") {
        // Default constructor for the Animal class
        cout << "I am an " << animalType << "." << endl;
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

