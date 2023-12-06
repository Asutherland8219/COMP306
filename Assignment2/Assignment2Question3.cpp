/*
 Title: Assignment2Question3.cpp
 Description: Elevator Class
 Date: October 7th, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create an Elevator Class that moves between floors.

 Compile (assuming Cygwin is running): g++ -o Assignment2 Assignment2Question3.cpp
 Execution (assuming Cygwin is running): ./Assignment2Question3.exe

 Classes (functions):
	- Elevator()
        The default constructor for the Elevator object, has two attributes, position and top.

 Variables:
    int position;
        - The current position of the elevator
    int top;
        - the top floor

*/

/*
 TEST PLAN

 Normal case:
    elevator = Elevator()
        **Defaults to 5 floors, so 5 is the top value
    --> "Welcome! You are currently on floor: 0"

    elevator.up()
    --> "Going up."
    --> "You are currently on floor: 1"

    elevator.down()
    --> "Going down."
    --> "You are currently on floor: 0"

    elevator.go_to(6)
    --> "You have arrived on floor: 6"

    elevator.reset()
    --> "Elevator ending, returning to first floor"

 Bad Case:
    elevator.go_to(-1)
    --> "This is less than the number of floors in this building."
        "Please enter a value between 1 and 5"

    elevator.go_to(10)
    --> "This value is more than the maximum of floors in this building."
        "Please enter a value between 1 and 5"

 Discussion:
    An additional bad case could be entering a character value instead of a numeric value.
    Because this is not an input based problem I opted to not include any measures to handle that.

    Outside of that, the main bad cases are either entering a value far out of range (ie. below 1 or above top)
    Both of which are handled accordingly.
*/

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
            std::cout << "Please enter a value between " << 1 << " and " << top << std::endl;
            return false;
        }
        if (desired_floor == top) {
            std::cout << "You have reached the top floor of this establishment." << endl;
            std::cout << "Please enter a value between " << 1 << " and " << top << std::endl;
        } else {
            return true;
        }
        return true ;
    }
    };