using namespace std;

#include "problem1_Animal.cpp"
#include "problem1_AnimalTest.cpp"
#include "problem2_Book.cpp"

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
    cout << golden_son.get("title");
    cout << golden_son.get("isbn");
    cout << golden_son.get("author");
    cout << golden_son.get("edition");
    cout << golden_son.get("publisher");
    cout << golden_son.get("year published");


    return 0;

};
