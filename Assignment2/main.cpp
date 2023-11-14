using namespace std;

#include "Assignment2Question1.cpp"
#include "Assignment2Question2.cpp"
#include "Assignment2Question3.cpp"
#include "Assignment2Question4.cpp"
#include "Assignment2Question5.cpp"


 int main() {

//    // PROBLEM 1 -- > Done
//    string input;
//
//    Animal animal;
//    // default constructor
//    animal.sound();
//
//    // Pig
//    Pig pig;
//    pig.sound();
//
//    // Sheep
//    Sheep sheep;
//    sheep.sound();
//
//    // Duck
//    Duck duck;
//    duck.sound();
//
//    // Cow
//    Cow cow;
//    cow.sound();
//
//
//    // Test input function --> Problem 1
//    cout << "Enter an animal: ";
//    cin >> input;
//
//    while (!AnimalTest::Test(input)) {
//         cout << "Enter an animal: ";
//         cin >> input;
//    }
//
//    // PROBLEM 2 --> Done
//    // Test function for the Book class ; mainly on creation
//    // test getters in the main
//    Book red_rising = Book();
//
//    red_rising.setTitle("Red Rising");
//    red_rising.setISBN("034553980X");
//    red_rising.setAuthor("Pierce Brown");
//    red_rising.setEdition("1st Edition");
//    red_rising.setPublisher("Del Rey Books");
//    red_rising.setYearPublished("Jan. 1 2014");
//    red_rising.details();
//
//    // create a second book, this time only getting one item at a time
//    Book golden_son = Book();
//    golden_son.setTitle("Golden Son");
//    golden_son.setISBN("0345539818");
//    golden_son.setAuthor("Pierce Brown");
//    golden_son.setEdition("1st Edition");
//    golden_son.setPublisher("Del Rey Books");
//    golden_son.setYearPublished("Jan. 6 2015");
//
//    // get all the details
//    cout << golden_son.get("title") << "\n";
//    cout << golden_son.get("isbn") << "\n";
//    cout << golden_son.get("author") << "\n";
//    cout << golden_son.get("edition") << "\n";
//    cout << golden_son.get("publisher")<< "\n";
//    cout << golden_son.get("year published") << "\n";
//
//    // PROBLEM 3 ; The elevator --> Done
//
//    // init the elevator
//    Elevator elevator = Elevator();
//
//    // go all the way up to floor 5, one at a time
//    elevator.up();
//    elevator.up();
//    elevator.up();
//    elevator.up();
//
//    // test the max floor error response
//    elevator.up();
//
//    // go all the way down
//    elevator.down();
//    elevator.down();
//    elevator.down();
//    elevator.down();
//
//    // go beyond first floor to test error response
//    elevator.down();
//
//    // reset to one (main floor)
//    elevator.reset();
//
//    // go to floor outside upper limit
//    elevator.go_to(6);
//
//    // go to floor outside lower limit
//    elevator.go_to(-1);
//
//    // go to specific floor, then reset
//    elevator.go_to(3);
//    elevator.reset();
//
//    // create a big elevator, for a tower with 20 floors
//    Elevator big_elevator = Elevator(20);
//    big_elevator.go_to(20);
//
//    // PROBLEM 4 --> Done
//    Mouse mouse("Lola");
//    mouse.jump();
//    mouse.dance();
//    mouse.eat("cheese");
//    mouse.move();
//    mouse.sleep();
//    mouse.groom();
//    // unique ability
//    mouse.hide();
//
//    Gerbil gerbil("Gibby");
//    gerbil.jump();
//    gerbil.dance();
//    gerbil.eat("apple");
//    gerbil.move();
//    gerbil.sleep();
//    gerbil.groom();
//    // unique
//    gerbil.smell();
//
//    Hamster hamster("Hammy");
//    hamster.jump();
//    hamster.dance();
//    hamster.eat("carrot");
//    hamster.move();
//    hamster.sleep();
//    hamster.groom();
//    // unique
//    hamster.exercise();
//
//    GuineaPig guineapig("Gerald-Paul");
//    guineapig.jump();
//    guineapig.dance();
//    guineapig.eat("celery");
//    guineapig.move();
//    guineapig.sleep();
//    guineapig.groom();
//    //unique
//    guineapig.talk();

    // PROBLEM 5

    // Init a base point function
    Point base;
    base.Show();

    // Increase x and y
    base.Add(1, 1);

    // Increase x
    base.Add(1);

    // Increase y
    base.Add(0,1);

    // Decrease x and y
    base.Subtract(1, 1);

    // Decrease x
    base.Subtract(1);

    // Decrease y
    base.Subtract(0, 1);

    // Create a shape (circle)
    Point circle_point(1,1);
    Circle base_circle(circle_point, 10);

    // Display
    base_circle.display();

     return 0;

};
