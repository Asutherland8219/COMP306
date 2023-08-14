//
// Created by alex on 06/08/23.
//

#include <iostream>
#include <iomanip>
#include <string>

class Elevator {
private:
    int position = 1;
    int top = 0;
public:
    Elevator(int N = 5) {
        //default constructor for the class, 5 stories
        top = N;
        std::cout << "Welcome! You are currently on floor: " << position << std::endl;
    }

    void up(){
        // move up a floor
        int pos_up = ++position;
        if (in_range(pos_up)) {
            position = pos_up;
            std::cout << "Going up." << std::endl;
            std::cout << "You are currently on floor: " << position << std::endl;
        }
    };

    void down(){
        //move down a floor
        int pos_down = --position;
        if (in_range(pos_down)) {
            position = pos_down;
            std::cout << "Going down." << std::endl;
            std::cout << "You are currently on floor: " << position << std::endl;
        }

    };

    void reset(){
        // The reset function, returning to the main floor
        position = 1;
        std::cout << "Elevator ending: Returning to the first floor." << std::endl;
    };

    void go_to(int N){
        // go to a specific floor
        if (in_range(N)) {
            position = N;
            std::cout << "You have arrived on floor:  " << position << std::endl;
        }

    };

    bool in_range(int desired_floor) {
        // checks if the value is in the range, if it is do nothing. If it isnt print either too high or too low
        if (desired_floor > top) {
            std::cout << "This value is more than the maximum of floors in this building.\n" << std::endl;
            return false;
        }
        if (desired_floor < 1) {
            std::cout << "This is less than the number of floors in this building. \n" << std::endl;
            std::cout << "Please enter a value between " << 1 << "and " << top << std::endl;
            return false;
        }
        if (desired_floor == top) {
            std::cout << "You have reached the top floor of this establishment." << endl;
        } else {
            return true;
        }
        return true ;
    }
    };