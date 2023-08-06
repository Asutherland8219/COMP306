//
// Created by alex on 06/08/23.
//

#include <iostream>
#include <iomanip>
#include <string>

class Elevator{
private:
    int position = 1;
    int top = 0;
public:
    Elevator(int N = 5){
        //default constructor for the class, 5 stories
        top = N;
        std::cout << "You are currently on floor: " << position << std::endl;
    }

    void up(){
        // move up a floor
        if (in_range(position)) {
            position++;
            std::cout << "Going up." << std::endl;
        }
    }

    void down(){
        //move down a floor
        if (in_range(position)) {
            position--;
            std::cout << "Going down." << std::endl;
        }

    }

    void go_to(int N){
        // go to a specific floor
        if (in_range(position)) {
            position = N;
            std::cout << "We have arrived on floor " << position << std::endl;
        }

    }

    bool in_range(int desired_floor){
        // checks if the value is in the range, if it is do nothing. If it isnt print either too high or too low
        if (desired_floor > top ){
            std::cout << "This value is more than the maximum of floors in this building.\n" << std::endl;
            return false;
        }
        else if (desired_floor < 1 ){
            std::cout << "This is less than the number of floors in this building. \n" << std::endl;
            std::cout << "Please enter a value between " << 1 << "and " << top << std::endl;
            return false;
        }
        else {
            return true;
        }

    };


};