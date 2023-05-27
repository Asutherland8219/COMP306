/*
 Title: tempConversion.cpp
 Description: A temperature conversion application based on user input
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
	Convert a user entered value to either Fahrenheight or Celsius, also entered by the user.
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 tempConversion.cpp
 Execution (assuming Cygwin is running): ./tempConversion.exe
 
 Classes:
	- tempOutputs : Enter the temp and desired units, output is the answer in sentence format.

 Variables:
 	temperature - int - the temperature value 
 	units - char - the Units you would like to conver to
*/

/*
 TEST PLAN
 
 Normal case:
 	>printTable()
 	

 Case 1 (infinite loop)
 	> if we ommit the final point of 12, the loop may continue indefinitely.
 

 Discussion:
 	The values are hard coded in this program so any issues that may occur are limited. If we had a prompt and input model
	then the test plan would have to be much more elaborate.
 
*/

#include "unitConversionHeader.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>

using namespace std;

void tempOutputs(int, char);
int unitConversion(int, char);

void tempConversion() {
    // Parent function.Collect the inputs, handle the conversions and checks then return the result.
    int temperature;
    char units;
    bool running;

    running = true;
   
    cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa. \n";

    cout <<  "Please enter your temperature: ";
    cin >> temperature; 

    while (running == true) {
        cout << "\n";
        if (cin.good()) {
            cout <<  "Please enter your units (F/C): ";
            cin >> units; 
            cout << "\n";
        }  

        if (cin.good()) {
            tempOutputs(temperature, units);
            running = false;
        }
        else {
            cout << "The value you have entered is incorrect or not supported. Please enter either F or C or to exit the program enter N :";
            cin >> temperature;

            if (temperature == 'N') {
                running = false;
            }
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

