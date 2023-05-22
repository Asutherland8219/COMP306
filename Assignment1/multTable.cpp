/*
 Title: multTable.cpp
 Description: Creating a Multiplication Table from 1 to 12
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/
#include <iostream>
#include <iomanip>
using namespace std;


void tableFrame (int);
void printValues (int n, int high);

// The printMultiples, and printMulTable methods were taken from sample code in the Unit 6 readings.

void printTable () {
	int i = 1;
	int high = 12;
	// Styling in order to move the headers to the right leaving the empty space representing 0
    cout << "\t" << setw(1) << "|";

    // Output the column headers
	tableFrame(high);

	// The parent while loop. We run another while loop inside of this one 
	// A for loop would also suffice.
	while (i <= high) {
		cout << setw(5) << i << "\t" << "|"; 

		printValues(i, high );
		i += 1;
	}

}



void printValues (int n, int high) {
	int i = 1;
	
	// While the i value is less than 12 we loop through and do two things:
	// 1. calculate the value , see   n*i
	// 2. print the value along with styling
	// Demonstrated using a while loop but a for loop will also work
	while (i <= high) {
		cout  << setw(3) << n*i  << setw(3) << "|" << "\t";
		i = i + 1;

	}
	cout << endl;
}


void tableFrame (int high) {
	// We print the headers before hand because in the styling template we need to start indented and print 
	// the range on the x and y axis.

	// Done with a simple for loop;
	for (int col = 1; col <= high; col++) {
        cout << setw(3) << col << setw(3) << "|" << "\t";
		
    }
	cout << endl;
}





