using namespace std;

#include "Animal.cpp"
#include "AnimalTest.cpp"

int main() {

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
   return 0;

};
