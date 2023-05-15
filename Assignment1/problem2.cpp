// Temperature input program 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>

using namespace std;

bool unitCheck(char);
bool typeCheck(int, int);
void tempOutputs(int, char);
int unitConversion(int, char);

void tempConversion() {
    // Parent function.Collect the inputs, handle the conversions and checks then return the result.
    int temperature;
    char units;
    int id_type;

   
    cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa. \n";
    cout <<  "Please enter your temperature: ";
    cin.get()  >> temperature; 
    cout << "\n";

    if (typeCheck(temperature, id_type) == false)
    {
        cout << "The value you have entered is incorrect or not supported. Please enter an integer value :";
        cin.get() >> temperature;
        cout << "\n";
    }
    else 
    {
        cout <<  "Please enter your units (F/C): ";
        cin.get()  >> units;

        if (unitCheck(units) == false)
        {
            cout << "The value you have entered is incorrect or not supported. Please enter either F/C";
            cin.get() >> units;
        }
        else {
            
            tempOutputs(temperature, units);
   
        }


    }
    

}

void tempOutputs(int temperature, char units) {
    // After receiving the inputs we add the conversion logic and then run the calculations
    string lhs = "Celsius";
    string rhs = "Celsius";
    int calculation;

    if (units == 'F') {
        lhs = "Fahrenheiht";

    }
    else {
        rhs = "Fahrenheit";
    }

    calculation = unitConversion(temperature, units);

    cout << "A temperature of " << temperature << " degrees " << lhs << " is equivalent to " << calculation << " " << rhs << ".";
}

int unitConversion(int temperature, char units) {
    // main math calculation 
    int calculation;

    if (units == 'C') {
        calculation = (temperature * 9 / 5) + 32 ;
    }
    else {
        calculation = (temperature - 32) * 5/9 ; 
    }

    return calculation;

}

bool unitCheck(char units) {
    // Capitilize the unit regardless then check if it is either of the two correct values 
    char upperunit;
    upperunit = toupper(units);

    if ( upperunit  == 'F' || upperunit == 'C' )
    {
        return true;
    }

    return false;
}

bool typeCheck(int value, int desired_value){
    // Using this function, we will check verify if the value matches the desired value
    // If it does, return true, else return false

    if (typeid(value) == typeid(desired_value)){
        return true;
    }
    else {
        return false;
    }

}