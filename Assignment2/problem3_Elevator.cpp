//
// Created by alex on 06/08/23.
//

#include <iostream>
#include <iomanip>
#include <string>

class Elevator{
private:
    int position = 0;
    int top = 0;
public:
    Elevator(int N = 5){
        //default constructor for the class, 5 stories
        top = N;
        std::cout << "You are currently on floor: " << position << std::endl;
    }

    void up(){
        // move up a floor
        position++;
        if (position >= top){
            std::cout << "You have reached the top floor." << std::endl;
        }

    }

    void down(){
        //move down a floor
        position--;
        if (position <= 0){
            std::cout << "You have reached the main floor." << std::endl;
        }
    }

    void go_to(int N){
        // go to a specific floor
        position = N;
        if (position >= top ){
            std::cout << "This value is more than the maximum of floors in this building." << std::endl;
            std::cout << "Please enter a value between " << 1 << "and " << top << std::endl;

        }
    }


};