//
// Created by alex on 08/08/23.
//
#include <iostream>
#include <iomanip>
#include <string>


class Rodent {
public:
    //Rodent(std::string name) : name(name) {};

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

    }

};