using namespace std;

#include "Assignment2Question1.cpp"
#include "Assignment2Question2.cpp"
#include "Assignment2Question3.cpp"
#include "Assignment2Question4.cpp"
#include "Assignment2Question5.cpp"


 int main() {

    // PROBLEM 1 -- > Done
    string input;

    Animal animal;
    // default constructor
    animal.sound();

    // Pig
    Pig pig;
    pig.sound();

    // Sheep
    Sheep sheep;
    sheep.sound();

    // Duck
    Duck duck;
    duck.sound();

    // Cow
    Cow cow;
    cow.sound();


    // Test input function --> Problem 1
    cout << "Enter an animal: ";
    cin >> input;

    while (!AnimalTest::Test(input)) {
         cout << "Enter an animal: ";
         cin >> input;
    }

    // PROBLEM 2 --> Done
    // Test function for the Book class ; mainly on creation
    // test getters in the main
    Book red_rising = Book();

    red_rising.setTitle("Red Rising");
    red_rising.setISBN("034553980X");
    red_rising.setAuthor("Pierce Brown");
    red_rising.setEdition("1st Edition");
    red_rising.setPublisher("Del Rey Books");
    red_rising.setYearPublished("Jan. 1 2014");
    red_rising.details();

    // create a second book, this time only getting one item at a time
    Book golden_son = Book();
    golden_son.setTitle("Golden Son");
    golden_son.setISBN("0345539818");
    golden_son.setAuthor("Pierce Brown");
    golden_son.setEdition("1st Edition");
    golden_son.setPublisher("Del Rey Books");
    golden_son.setYearPublished("Jan. 6 2015");

    // get all the details
    cout << golden_son.get("title") << "\n";
    cout << golden_son.get("isbn") << "\n";
    cout << golden_son.get("author") << "\n";
    cout << golden_son.get("edition") << "\n";
    cout << golden_son.get("publisher")<< "\n";
    cout << golden_son.get("year published") << "\n";

    // PROBLEM 3 ; The elevator --> Done

    // init the elevator
    Elevator elevator = Elevator();

    // go all the way up to floor 5, one at a time
    elevator.up();
    elevator.up();
    elevator.up();
    elevator.up();

    // test the max floor error response
    elevator.up();

    // go all the way down
    elevator.down();
    elevator.down();
    elevator.down();
    elevator.down();

    // go beyond first floor to test error response
    elevator.down();

    // reset to one (main floor)
    elevator.reset();

    // go to floor outside upper limit
    elevator.go_to(6);

    // go to floor outside lower limit
    elevator.go_to(-1);

    // go to specific floor, then reset
    elevator.go_to(3);
    elevator.reset();

    // create a big elevator, for a tower with 20 floors
    Elevator big_elevator = Elevator(20);
    big_elevator.go_to(20);

    // PROBLEM 4 --> Done
    Mouse mouse("Lola");
    mouse.jump();
    mouse.dance();
    mouse.eat("cheese");
    mouse.move();
    mouse.sleep();
    mouse.groom();
    // unique ability
    mouse.hide();

    Gerbil gerbil("Gibby");
    gerbil.jump();
    gerbil.dance();
    gerbil.eat("apple");
    gerbil.move();
    gerbil.sleep();
    gerbil.groom();
    // unique
    gerbil.smell();

    Hamster hamster("Hammy");
    hamster.jump();
    hamster.dance();
    hamster.eat("carrot");
    hamster.move();
    hamster.sleep();
    hamster.groom();
    // unique
    hamster.exercise();

    GuineaPig guineapig("Gerald-Paul");
    guineapig.jump();
    guineapig.dance();
    guineapig.eat("celery");
    guineapig.move();
    guineapig.sleep();
    guineapig.groom();
    //unique
    guineapig.talk();

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
    double radius = 10;
    Circle base_circle(circle_point, radius);

    // Display
    std::cout << "Good Circle:";
    base_circle.display();

    // Create a bad circle
    double radius_bad  = -1;
    try {
         Circle bad_circle(circle_point, radius_bad);
     } catch (const std::exception& except) {
         // Catch exception
         std::cerr << "Caught exception: " << except.what() << std::endl;
     }

    // Create a rectangle
    Point bottom_left_corner(4, 8);
    Point bottom_right_corner(8,8);
    Point upper_left_corner(4,16);
    Point upper_right_corner(8, 16);

    std::cout << "Good rectangle:";
    Rectangle rec(bottom_left_corner, bottom_right_corner, upper_left_corner, upper_right_corner);

    // Display all
    rec.display();

    // Create a square using the same values
     Point bottom_left_corner_sq(4, 8);
     Point bottom_right_corner_sq(8,8);
     Point upper_left_corner_sq(4,12);
     Point upper_right_corner_sq(8, 12);

     // Check exception is thrown for square
     try {
         Rectangle square(bottom_left_corner_sq, bottom_right_corner_sq, upper_left_corner_sq, upper_right_corner_sq);
     } catch (const std::exception& except) {
         // Catch exception
         std::cerr << "Caught exception: " << except.what() << std::endl;
     }

     // Check exception is thrown for a bad rectangle, (ie. not square, just
     Point bottom_left_corner_bad(-1, 8);
     Point bottom_right_corner_bad(8,8);
     Point upper_left_corner_bad(4,12);
     Point upper_right_corner_bad(8, 12);

     try {
         Rectangle bad_rec(bottom_left_corner_bad, bottom_right_corner_bad, upper_left_corner_bad, upper_right_corner_bad);
     } catch (const std::exception& except) {
         // Catch exception
         std::cerr << "Caught exception: " << except.what() << std::endl;
     }

     // Create a Triangle
     Point peak(4,8);
     Point left_point(4,12);
     Point right_point(8, 12);
     std::cout << "Good Triangle:";
     Triangle tri(peak, right_point, left_point);
     tri.display();

    // Create a bad triangle
     Point peak_bad(1,1);
     Point left_point_bad(2,2);
     Point right_point_bad(3, 3);

     try {
         Triangle tri_bad(peak_bad, right_point_bad, left_point_bad);
     } catch (const std::exception& except) {
         // Catch exception
         std::cerr << "Caught exception: " << except.what() << std::endl;
     }

     return 0;

};
