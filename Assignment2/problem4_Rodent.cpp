//
// Created by alex on 08/08/23.
//
#include <iostream>
#include <iomanip>
#include <string>


class Rodent {
public:
    Rodent(const std::string& name = "rodent"){
        cout << "This is " << name << ". They are a " << typeid(Rodent).name();
    };

    void dance() {
        std::cout << name << " is dancing!!" << std::endl;
    }

    void jump() {
        std::cout << name << " is jumping!!" << std::endl;
    }

    void move() {
        std::cout << name << " is moving" << std::endl;
    }

    void sleep() {
        std::cout << name << " is sleeping. shhh!" << std::endl;
    }

    void groom() {
        std::cout << name << " is grooming itself." << std::endl;
    }

    void eat(std::string food) {
        std::cout << name << "is eating " << food << ". yum!" << std::endl;

    }
private:
    std::string name;
};

class GuineaPig : public Rodent {
public:
    GuineaPig() {

    }

    void Talk() {
        // Guineapig squeak
        std::cout << "*squeak*, *squeak*, *squeak!*" << std::endl;
    }


};

class Hamster : public Rodent {
public:
    Hamster() {

    }

    void Exercise() {
        // Hamster running on the wheel
        std::cout << "wrrrrrrrr the hamster wheel is spinning as the hamster is running." << std::endl;
    }


};

class Gerbil : public Rodent {
public:
    Gerbil() {
    }

    void Smell() {
        // sniffing around
        std::cout << "*sniff* *sniff* *sniff*" << std::endl;
    }
};

class Mouse : public Rodent {
public:
    void Hide() {
        // Mouse hiding from predators
        std::cout << "the mouse is hiding." << std::endl;
    }

    Mouse() {

    }
};