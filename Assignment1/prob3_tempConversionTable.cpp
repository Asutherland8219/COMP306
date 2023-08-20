/*
 Title: prob3_tempConversionTable.cpp
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
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 prob3_tempConversionTable.cpp
 Execution (assuming Cygwin is running): ./prob3_tempConversionTable.exe
 
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
#include <cmath>
#include <typeinfo>
#include "unitConversionHeader.h"

using namespace std;

void tableHeaders() {
    cout <<  setw(5) << "\t" << "Temperature \t" << "|" << "\t" << "Temperature \t \n";
    cout << "\t" << " (degrees) \t" << "|" << "\t" << " (degrees) \t \n";
    cout << "\t" << "F" << "\t" << setw(5) << "C";
    cout << "\t|\t" << "C" << "\t" << setw(5) << "F \n";
}


void tempConversionTable() {
    // parent function 
    float increment = 5.0;
    float floor = -40.0;
    float ceiling = 455.0;

    tableHeaders();

    for ( floor; ceiling; floor += increment) {

        // column one, F to C 
        cout << "\t" << floor << "\t";
        cout << std::setprecision(3) << std::fixed << unitConversion(floor, 'F');

        // pipe
        cout << "\t|";

        // column two, C to F 
        cout << "\t" << floor << "\t";
        cout << unitConversion(floor, 'C') << "\n";


        if ( floor == ceiling){
            break;
        }
    }

}

