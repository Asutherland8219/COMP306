// At this point, you will not create anything so complex. Instead, your mission is to create a C++ program that will generate a multiplication table. Start with the 1× table, followed by 2×, then 3×, and so on, until you have generated a table from 1× to 12×. An example output would display as follows:
#include <iostream>
using namespace std;


void printMultiples (int n, int high) {
	int i = 1;
	while (i <= high) {
		cout << n*i << " ";
		i = i + 1;
	}
	cout << endl;
}

/// @brief 
/// @param high 
void printMultTable (int high) {
	int i = 1;
	while (i <= high) {
		printMultiples (i, high);
		i = i + 1;
	}
}