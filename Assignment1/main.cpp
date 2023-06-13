#include <iostream>
#include "multTable.cpp"
#include "tempConversion.cpp"
#include "tempConversionTable.cpp"
#include "cppHelp.cpp"
#include "unitConversion.cpp"
#include "unitConversionHeader.h"

using namespace std;

void tableFrame (int);
void printValues (int n, int high);
void tempConversion();
bool typeCheck(int, int);
void printTable(void);
void tempConversionTable(void);
    
int main() {
    // printTable();
    tempConversion();
    // tempConversionTable();
    helpMenu();

    return 0;
};
