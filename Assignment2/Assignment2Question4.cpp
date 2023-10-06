//
// Created by alex on 08/08/23.
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Rodent {
public:
    Rodent(const string& name = "rodent", const string& species="rodent") : name(name), species(species){
        cout << "This is " << name << ". They are a " << species << "." << endl;
    };

    void dance() {
        cout << name << " the " << species << " is dancing!!" << std::endl;
    }

    void jump() {
        cout << name << " the " << species << " is jumping!!" << std::endl;
    }

    void move() {
        cout << name << " the " << species << " is moving" << std::endl;
    }

    void sleep() {
        cout << name << " the " << species << " is sleeping. shhh!" << std::endl;
    }

    void groom() {
        cout << name << " the " << species << " is grooming itself." << std::endl;
    }

    void eat(string food) {
        cout << name << " the " << species <<  " is eating " << food << ". yum!" << std::endl;

    }
protected:
    string name;
    string species;
};

class GuineaPig : public Rodent {
public:
    GuineaPig(const string& name = "GuineaPig") : Rodent(name, "GuineaPig") {

    }

    void talk() {
        // Guineapig squeak
        cout << name << " says: *squeak*, *squeak*, *squeak!*" << endl;
    }


};

class Hamster : public Rodent {
public:
    Hamster(const string& name = "Hamster") : Rodent(name, "hamster") {

    }

    void exercise() {
        // Hamster running on the wheel
        cout << "wrrrrrrrr the hamster wheel is spinning as " << name << "the hamster is running." << endl;
    }


};

class Gerbil : public Rodent {
public:
    Gerbil(const string& name = "Gerbil") : Rodent(name, "gerbil") {
    }

    void smell() {
        // sniffing around
        cout << name << " is smelling: " << "*sniff* *sniff* *sniff*" << endl;
    }
};

class Mouse : public Rodent {
public:
    Mouse(const string& name = "Mouse") : Rodent(name, "mouse") {
    }

    void hide() {
        // Mouse hiding from predators
        cout << name << " the " << species << " is hiding." << endl;
    }

};