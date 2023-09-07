/*
 Title: Assignment1Question5.cpp
 Description: List the prime numbers between 0 and 10000
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
	List all prime numbers between 0 and 10000
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 Assignment1Question5.cpp
 Execution (assuming Cygwin is running): ./Assignment1Question5.exe

 Classes (functions) :
	- isPrimeNumber : calculates if the number is in fact prime
    - findPrimeNumber : prints the number if it is prime

 Variables:
 	int value - the number that we are checking if it is prime
*/

/*
 TEST PLAN
 
 Normal case:
 	>findPrimeNumbers
 	

 Case 1 (infinite loop)
 	> we set the floor and ceiling values in the function and then increment. If we didn't set these correctly
 	it could loop.
 

 Discussion:
 	The values are hard coded in this program so any issues that may occur are limited. If we had a prompt and input model
	then the test plan would have to be much more elaborate.
 
*/

#include <iostream>
#include <cmath>

// basic check to see if the value satisfies the constraints of being  a prime number 
bool isPrimeNumber(int value) {
    // we could also use greater than 1; we know that 0,1 are both not prime
    if (value < 2)
        return false;

    for (int i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrimeNumbers() {
    // Find and print prime numbers in the range 
    for (int number = 1; number <= 10000; ++number) {
        if (isPrimeNumber(number)) {
            std::cout << number << std::endl;
        }
    }

    return 0;
}

