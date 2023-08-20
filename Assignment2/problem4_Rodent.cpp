//
// Created by alex on 08/08/23.
//
#include <iostream>
#include <iomanip>
#include <string>


class Rodent {
public:
    Rodent(const std::string& name = "rodent", const std::string& species="rodent") : name(name), species(species){
        cout << "This is " << name << ". They are a " << species << "." << std::endl;
    };

    void dance() {
        std::cout << name << " the " << species << " is dancing!!" << std::endl;
    }

    void jump() {
        std::cout << name << " the " << species << " is jumping!!" << std::endl;
    }

    void move() {
        std::cout << name << " the " << species << " is moving" << std::endl;
    }

    void sleep() {
        std::cout << name << " the " << species << " is sleeping. shhh!" << std::endl;
    }

    void groom() {
        std::cout << name << " the " << species << " is grooming itself." << std::endl;
    }

    void eat(std::string food) {
        std::cout << name << " the " << species <<  " is eating " << food << ". yum!" << std::endl;

    }
protected:
    std::string name;
    std::string species;
};

class GuineaPig : public Rodent {
public:
    GuineaPig(const std::string& name = "GuineaPig") : Rodent(name, "GuineaPig") {

    }

    void talk() {
        // Guineapig squeak
        std::cout << name << " says: *squeak*, *squeak*, *squeak!*" << std::endl;
    }


};

class Hamster : public Rodent {
public:
    Hamster(const std::string& name = "Hamster") : Rodent(name, "hamster") {

    }

    void exercise() {
        // Hamster running on the wheel
        std::cout << "wrrrrrrrr the hamster wheel is spinning as " << name << "the hamster is running." << std::endl;
    }


};

class Gerbil : public Rodent {
public:
    Gerbil(const std::string& name = "Gerbil") : Rodent(name, "gerbil") {
    }

    void smell() {
        // sniffing around
        std::cout << name << " is smelling: " << "*sniff* *sniff* *sniff*" << std::endl;
    }
};

class Mouse : public Rodent {
public:
    Mouse(const std::string& name = "Mouse") : Rodent(name, "mouse") {
    }

    void hide() {
        // Mouse hiding from predators
        std::cout << name << " the " << species << " is hiding." << std::endl;
    }

};