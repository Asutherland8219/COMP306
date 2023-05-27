/*
 Title: multTable.cpp
 Description: Creating a Multiplication Table from 1 to 12
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION
 
 Program Purpose:
	Create a multiplication table from 1 to 12 with appropriate style guidelines given.
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 multTable.cpp
 Execution (assuming Cygwin is running): ./multTable.exe
 
 Classes:
	- tableFrame: set the top row for the table
	- printValues: print the values in the table
	- printTable: The main function that prints the entire table. This is the class I would add to Main.

 Variables:
 	i - int - 1 Starting value for the table  
 	high - int - 12 The final value, basically the stop point.
*/

/*
 TEST PLAN
 
 Normal case:
 	>printTable()
 	

 Case 1 (infinite loop)
 	> if we ommit the final point of 12, the loop may continue indefinitely.
 

 Discussion:
 	The values are hard coded in this program so any issues that may occur are limited. If we had a prompt and input model
	then the test plan would have to be much more elaborate.
 
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





