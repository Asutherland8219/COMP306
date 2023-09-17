/*
 Title: Assignment1Question3.cpp
 Description: A temperature conversion table
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
	Convert a table of temperatures ranging from -40 to 455.
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 Assignment1Question3.cpp
 Execution (assuming Cygwin is running): ./Assignment1Question3.exe
 
 Classes (functions):
	- tableHeaders() :
    - tempConversionHeaders() :

 Variables:
 	int increment - the integer amount to increment each instance by
 	int floor - the starting value
 	int ceiling - the top value, max value
*/

/*
 TEST PLAN
 
 Normal case:
 	>printTable()
 	

 Case 1 (infinite loop)
 	> If by chance the ceiling value was not set, then this calculation would continue indefinitely
 	> In order to avoid this, we just increment the floor value till it equals the ceiling
 

 Discussion:
 	The values are hard coded in this program so any issues that may occur are limited. If we had a prompt and input model
	then the test plan would have to be much more elaborate.
 
*/


#include <iostream>
#include <iomanip>
#include "unitConversionHeader.h"

using namespace std;

void tableHeaders() {
    cout <<  setw(5) << "\t" << "Temperature\t" << " |" << "\t" << "  Temperature\n";
    cout <<  setw(5) << "\t" << " (degrees) \t" << " |" << "\t" << "   (degrees)\n";
    cout <<  setw(5) << "\t" << "F" << "\t" << setw(5) << "C";
    cout <<  setw(5) << "\t |\t" << "\t" << "C" << "\t" << setw(5) << "F \n";
}


void tempConversionTable() {
    // parent function 
    float increment = 5.0;
    float floor = -40.000;
    float ceiling = 455.0;

    tableHeaders();

    for ( floor; ceiling; floor += increment) {

        // column one, F to C 
        cout << "\t" << std::setprecision(3) << std::fixed << floor << "\t";
        cout << std::setprecision(3) << std::fixed << unitConversion(floor, 'F');

        // pipe
        cout << "\t |";

        // column two, C to F 
        cout << "\t" << std::setprecision(3) << std::fixed << floor << "\t";
        cout << unitConversion(floor, 'C') << "\n";


        if ( floor == ceiling){
            break;
        }
    }

}

