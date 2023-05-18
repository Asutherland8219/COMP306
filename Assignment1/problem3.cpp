// Temp conversion table, starting at -40 with 5 increments 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>

using namespace std;

double rowConversion(int, char);
void tableHeaders();

void tempConversionTable() {
    // parent function 
    int increment = 5;
    int floor = -40;
    int ceiling = 455;

    tableHeaders();

    for ( floor; ceiling; floor += increment) {

        // column one, F to C 
        cout << "\t" << floor << "\t";
        cout << rowConversion(floor, 'F');

        // pipe
        cout << "\t|";

        // column two, C to F 
        cout << "\t" << floor << "\t";
        cout << rowConversion(floor, 'C') << "\n";


        if ( floor == ceiling){
            break;
        }
    }

}

double rowConversion(int temperature, char units) {
    double calculation;

    if (units == 'C') {
        calculation = (temperature * 9 / 5) + 32 ;
    }
    else {
        calculation = (temperature - 32) * 5/9 ; 
    }

    return calculation;
}

void tableHeaders() {
    cout <<  setw(5) << "\t" << "Temperature \t" << "|" << "\t" << "Temperature \t \n";
    cout << "\t" << " (degrees) \t" << "|" << "\t" << " (degrees) \t \n";
    cout << "\t" << "F" << "\t" << setw(3) << "C";
    cout << "\t|\t" << "C" << "\t" << setw(5) << "F \n";
}
