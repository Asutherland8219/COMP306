// Temp conversion table, starting at -40 with 5 increments 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>

using namespace std;

int rowConversion(int, char);
void tableHeaders();

void tempConversionTable() {
    // parent function 
    int increment = 5;
    int floor = -40;

    tableHeaders();
}

int rowConversion(int temperature, char units) {
    int calculation;

    if (units == 'C') {
        calculation = (temperature * 9 / 5) + 32 ;
    }
    else {
        calculation = (temperature - 32) * 5/9 ; 
    }

    return calculation;
}

void tableHeaders() {
    cout << "\t" << "Temperature \t" << "|" << "\t" << "Temperature \t \n";
    cout << "\t" << "(degrees) \t" << "|" << "\t" << "(degrees) \t \n";
}
