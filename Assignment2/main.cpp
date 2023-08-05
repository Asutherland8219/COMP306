using namespace std;

#include "problem1_Animal.cpp"
#include "problem1_AnimalTest.cpp"
#include "problem2_Book.cpp"
#include "problem2_BookTest.cpp"


int main() {

    // problem 1
    std::string input ;

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

    // Test input function
    cout << "Enter an animal: ";
    cin >> input;
    (AnimalTest(input));

    // problem 2
    // Test function for the Book class ; mainly on creation
    // test getters in the main
    Book red_rising = Book();

    red_rising.setTitle("Red Rising");
    red_rising.setISBN("034553980X");
    red_rising.setAuthor("Pierce Brown");
    red_rising.setEdition("1st Edition");
    red_rising.setPublisher("Del Rey Books");
    red_rising.setYearPublished("Jan. 1 2014");




   return 0;

};
