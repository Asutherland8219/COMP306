/*
 Title: Assignment1Question2.cpp
 Description: A temperature conversion application based on user input
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
	Convert a user entered value to either Fahrenheit or Celsius, also entered by the user.
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 Assignment1Question2.cpp
 Execution (assuming Cygwin is running): ./Assignment1Question2.exe
 
 Classes (functions):
	- tempOutputs : Enter the temp and desired units, output is the answer in sentence format.

 Variables:
 	temperature - int - the temperature value 
 	units - char - the Units you would like to convert to
*/

/*
 TEST PLAN
 
 Normal case:
 	>tempConversion()
 	

 Case 1 (Incorrect type entered during first input)
 	> Raise incorrect input and ask user to try again, if Y then try again, if N then  exit program
 	> If any other input, raise "Too many incorrect attempts"

 Case 2 ( Incorrect type entered during 2nd input , F/C)
    > Raise incorrect input and ask user to try again, do not restart the program. Follow the same error flow.
    > Wait for a good input, if it is still bad on 2nd attempt, kill the program.

 Case 3 ( Incorrect format, upper or lower case)
    > Converting all values to upper so that this issue does not occur

 Discussion: The program waits for the correct type of input, if we dont get the correct type the first time then we try again.
 If on that 2nd attempt it does not work, kill the program.

*/

#include "unitConversionHeader.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>
#include <any>
using namespace std;

void tempOutputs(int, char);

void tempConversion() {
    // Parent function.Collect the inputs, handle the conversions and checks then return the result.
    int temperature;
    char units;
    char retry;
    char killswitch;
    bool running;

    running = true;
    cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa. \n";

    while (running) {
        cout << "Please enter your temperature: \n";
        cin >> temperature;

        cout << "\n";

        if (cin.good()) {
            cout << "Please enter your units (F/C): ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // convert to upper to eliminate risk of inputting the wrong value, lowercase is sufficient
            cin >> units;

            if (cin.good()) {
                units = toupper(units);
                cout << "\n";

                if (units == 'F' || units == 'C') {
                    tempOutputs(temperature, units);
                    cout << "\n";
                    cout << " Do you want another conversion? (Y/N): \n";
                    cin >> killswitch;
                    killswitch = toupper(killswitch);
                }
                else {
                    cout << "The value you have entered is incorrect or not supported. Would you like to try again? (Y/N): \n";
                    cin >> retry;
                    units = toupper(retry);

                    if (units == 'Y') {
                        continue;

                    }
                    if (units == 'N') {
                        cout << "Exiting program. Thank you, Goodbye.";
                        running = false;
                    }
                    else {
                        cout << "Too many incorrect attempts. Exiting program. Good bye. \n";
                        running = false;

                    }
                }
            }
        }

        else if (cin.fail()) {
            cin.clear();
            cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

            cout << "The value you have entered is incorrect or not supported. Would you like to try again? (Y/N): \n";
            cin >> retry;
            units = toupper(retry);

            if (units == 'Y') {
                continue;

            }
            if (units == 'N') {
                cout << "Exiting program. Thank you, Goodbye.";
            }
            else {
                cout << "Too many incorrect attempts. Exiting program now. \n";
                cout << "Thank you. Goodbye. \n";
                running = false;
            }
        }

        if (killswitch == 'N') {
            cout << "Exiting program. Thank you, Goodbye. \n";
            running = false;
        } else {

        }
    }
    }



void tempOutputs(int temperature, char units) {
    // After receiving the inputs we add the conversion logic and then run the calculations
    string lhs = "Celsius";
    string rhs = "Celsius";
    int calculation;

    if (units == 'F') {
        lhs = "Fahrenheit";

    }
    else {
        rhs = "Fahrenheit";
    }
    // taken from header
    calculation = unitConversion(temperature, units);

    cout << "A temperature of " << temperature << " degrees " << lhs << " is equivalent to " << calculation << " degrees " << rhs << ". \n";
}

