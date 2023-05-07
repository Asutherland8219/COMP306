// At this point, you will not create anything so complex. Instead, your mission is to create a C++ program that will generate a multiplication table. Start with the 1× table, followed by 2×, then 3×, and so on, until you have generated a table from 1× to 12×. An example output would display as follows:
#include <iostream>
#include <iomanip>
using namespace std;


void tableFrame (int);
void printMultiples (int n, int high);

// The printMultiples, and printMulTable methods were taken from sample code in the Unit 6 readings.

void printMultTable (int high) {
	int i = 1;
	
	// Styling in order to move the headers to the right leaving the empty space representing 0
    cout << "\t" << setw(1) << "|";

    // Output the column headers
	tableFrame(high);

	// The parent while loop. We run another while loop inside of this one 
	// A for loop would also suffice.
	while (i <= high) {
		cout << setw(5) << i << "\t" << "|"; 

		printMultiples(i, high );
		i += 1;
	}

}



void printMultiples (int n, int high) {
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





