/*
 Title: tempConversionTable.cpp
 Description: A temperature conversion table from -40 to 455
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>
#include "unitConversionHeader.h"

using namespace std;

void tableHeaders();
int  unitConversion(int, char);

void tempConversionTable() {
    // parent function 
    float increment = 5;
    float floor = -40;
    float ceiling = 455;

    tableHeaders();

    for ( floor; ceiling; floor += increment) {

        // column one, F to C 
        cout << "\t" << floor << "\t";
        cout << unitConversion(floor, 'F');

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

void tableHeaders() {
    cout <<  setw(5) << "\t" << "Temperature \t" << "|" << "\t" << "Temperature \t \n";
    cout << "\t" << " (degrees) \t" << "|" << "\t" << " (degrees) \t \n";
    cout << "\t" << "F" << "\t" << setw(3) << "C";
    cout << "\t|\t" << "C" << "\t" << setw(5) << "F \n";
}
