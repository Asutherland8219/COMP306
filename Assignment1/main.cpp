/*
 Title: main.cpp
 Date: August 20th, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
Not included in the documentation is the header file for unit conversion. I found that between the tempConversion
and tempConversionTable functions I was using the same function twice. Because of this, I opted to put it in one single file
and re-use it instead of calling it twice.
*/


#include "Assignment1Question1.cpp"
#include "Assignment1Question2.cpp"
#include "Assignment1Question3.cpp"
#include "Assignment1Question4.cpp"
#include "Assignment1Question5.cpp"
#include "unitConversion.cpp"

using namespace std;


int main() {
    // problem 1 --> Done
    printTable();

    // problem 2 --> Needs a little more work 
    tempConversion();

    // problem 3 --> add trailing 0's
    tempConversionTable();
    
    // problem 4 --> Done
    helpMenu();

    // problem 5  --> Done
    findPrimeNumbers();

    return 0;
}
