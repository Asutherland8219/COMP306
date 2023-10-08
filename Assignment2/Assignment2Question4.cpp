/*
 Title: Assignment2Question4.cpp
 Description: The Rodent Class
 Date: October 5th, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create a Rodent parent class with subclasses for mouse, gerbil, hamster and guinea pig. Each has default attributes,
 jump, dance, eat, move, sleep, groom and then their unique abilities.

 Compile (assuming Cygwin is running): g++ -o Assignment2 Assignment2Question4.cpp
 Execution (assuming Cygwin is running): ./Assignment2Question4.exe

 Classes (functions):
	- Rodent()
        - jump
        - dance
        - eat
        - move
        - sleep
        - groom
    - Mouse()
        - hide
    - Gerbil()
        - smell
    - Hamster()
        - exercise
    - GuineaPig()
        - talk

 Variables:
    name : the name of the rodent being created
    species : the species of the animal, used for cleaner print statements

*/

/*
 TEST PLAN

 Normal case:
     Mouse mouse("Lola");
     --> This is Lola. They are a mouse.

     mouse.jump();
     --> Lola the mouse is jumping!!

     mouse.dance();
     --> Lola the mouse is dancing!!

     mouse.eat("cheese");
     --> Lola the mouse is eating cheese. yum!

     mouse.move();
     --> Lola the mouse is moving

     mouse.sleep();
     --> Lola the mouse is sleeping. shhh!

     mouse.groom();
     --> Lola the mouse is grooming itself.

     // unique ability
     mouse.hide();
     --> Lola the mouse is hiding.

     Gerbil gerbil("Gibby");
     --> This is Gibby. They are a gerbil.

     gerbil.jump();
     --> Gibby the gerbil is jumping!!

     gerbil.dance();
     --> Gibby the gerbil is dancing!!

     gerbil.eat("apple");
     --> Gibby the gerbil is eating apple. yum!

     gerbil.move();
     --> Gibby the gerbil is moving

     gerbil.sleep();
     --> Gibby the gerbil is sleeping. shhh!

     gerbil.groom();
     --> Gibby the gerbil is grooming itself.

     // unique
     gerbil.smell();
     --> Gibby is smelling: *sniff* *sniff* *sniff*


     Hamster hamster("Hammy");
     --> This is Hammy. They are a hamster.

     hamster.jump();
     --> Hammy the hamster is jumping!!

     hamster.dance();
     --> Hammy the hamster is dancing!!

     hamster.eat("carrot");
     --> Hammy the hamster is eating carrot. yum!

     hamster.move();
     --> Hammy the hamster is moving

     hamster.sleep();
     --> Hammy the hamster is sleeping. shhh!

     hamster.groom();
     --> Hammy the hamster is grooming itself.

     // unique
     hamster.exercise();
     --> wrrrrrrrr the hamster wheel is spinning as Hammythe hamster is running.


     GuineaPig guineapig("Gerald-Paul");
     --> This is Gerald-Paul. They are a GuineaPig.

     guineapig.jump();
     --> Gerald-Paul the GuineaPig is jumping!!

     guineapig.dance();
     --> Gerald-Paul the GuineaPig is dancing!!

     guineapig.eat("celery");
     --> Gerald-Paul the GuineaPig is eating celery. yum!

     guineapig.move();
     --> Gerald-Paul the GuineaPig is moving

     guineapig.sleep();
     --> Gerald-Paul the GuineaPig is sleeping. shhh!

     guineapig.groom();
     --> Gerald-Paul the GuineaPig is grooming itself.

     //unique
     guineapig.talk();
     --> Gerald-Paul says: *squeak*, *squeak*, *squeak!*



 Bad Case + Discussion:
    Hamster hamster(5);
    --> The only area of potential issue is the parameter is the name field of the animal constructor. Each animal is set to handle a string value so entering
    an int will cause the program to not compile.

    Any other bad case could be from the eat ability as it is also has a parameter. Again, if it is int it will not compile.

*/
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
        cout << "wrrrrrrrr the hamster wheel is spinning as " << name << " the hamster is running." << endl;
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