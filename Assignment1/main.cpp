#include <iostream>
#include "prob1_multTable.cpp"
#include "prob2_tempConversion.cpp"
#include "prob3_tempConversionTable.cpp"
#include "prob4_cppHelp.cpp"
#include "prob5_prime_numbers.cpp"
#include "unitConversion.cpp"
#include "unitConversionHeader.h"


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
    find_prime_numbers();

    return 0;
};
