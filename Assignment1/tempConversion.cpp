/*
 Title: tempConversion.cpp
 Description: A temperature conversion application based on user input
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>
using namespace std;

void tempOutputs(int, char);

void tempConversion() {
    // Parent function.Collect the inputs, handle the conversions and checks then return the result.
    int temperature;
    char units;
    int id_type;

   
    cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa. \n";
    cout <<  "Please enter your temperature: ";
    cin >> temperature; 
    cout << "\n";

    while (cin.good()) {
        cout <<  "Please enter your units (F/C): ";
        cin >> units; 
        cout << "\n";  

        if (cin.good()) {
            tempOutputs(temperature, units);
        }
        else {
            cout << "The value you have entered is incorrect or not supported. Please enter either F or C for Fahrenheit or Celsius respectively:";
            cin >> temperature;
        }

    }
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

