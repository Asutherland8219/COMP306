using namespace std;

#include "Animal.cpp"

int main() {

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

   return 0;

};
