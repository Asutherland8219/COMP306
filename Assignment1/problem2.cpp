#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>

using namespace std;

char unitCheck(char);
bool typeCheck(int, int);

void tempInputs() {
    int temperature;
    char units;
    int id_type;

   
    cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa. \n";
    cout <<  "Please enter your temperature: ";
    cin  >> temperature ; 

    if (typeCheck(temperature, id_type) == false)
    {
        cout << "The value you have entered is incorrect or not supported. Please enter an integer value.";
    }
    else {
        cout <<  "Please enter your units (F/C): ";
        cin  >> units;

    };
   
}

char unitCheck(char unit) {
    // Capitilize the unit regardless then check if it is either of the two correct values 
    return unit;
}

bool typeCheck(int value, int desired_value){
    // Using this function, we will check verify if the value matches the desired value
    // If it does, return true, else return false

    if (typeid(value) == typeid(desired_value)){
        cout << true;
    }
    else {
        cout << false;
    }

}