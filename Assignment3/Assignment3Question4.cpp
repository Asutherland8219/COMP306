/*
 Title: Assignment3Question4.cpp
 Description: Multi array addition, create various arrays, then add them up
 Date: January 28th, 2024
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create three floating point arrays, square them and then sum them up.

 Compile (assuming Cygwin is running): g++ -o Assignment3 Assignment3Question4.cpp
 Execution (assuming Cygwin is running): ./Assignment3Question4.exe

 Classes (functions):
    - Function
        floatingPointArray() - The main and only function which handles logic and prints the desired output

 Variables:
 	- string lines - the maximum number of lines
 	- int count - the counter index

*/

/*
 TEST PLAN

 Normal case:
 	> floatingPointArray();
 	> Output:
        0: 0 + 0 = 0
        1: 1 + 1 = 2
        2: 2 + 4 = 6
        3: 3 + 9 = 12
        4: 4 + 16 = 20
        5: 5 + 25 = 30
        6: 6 + 36 = 42
        7: 7 + 49 = 56
        8: 8 + 64 = 72
        9: 9 + 81 = 90
        10: 10 + 100 = 110
        11: 11 + 121 = 132
        12: 12 + 144 = 156
        13: 13 + 169 = 182
        14: 14 + 196 = 210
        15: 15 + 225 = 240
        16: 16 + 256 = 272
        17: 17 + 289 = 306
        18: 18 + 324 = 342
        19: 19 + 361 = 380
        20: 20 + 400 = 420
        21: 21 + 441 = 462
        22: 22 + 484 = 506
        23: 23 + 529 = 552
        24: 24 + 576 = 600



 Bad Case
    Not user input based, so less likely to experience any serious issues. The only bad case I could imagine is if there was some sort of arithmetic issue
    or some sort of weird race condition between the 4 for loops.


 Discussion:
 	Program that creates 3 arrays, based on 25 numbers. The first being a standard value, the 2nd being the standard value squared and the 3rd
 	being the sum of the first 2 arrays.

*/
#include <iostream>
#include <array>

void floatingPointArray() {
    const int arraySize = 25;
    std::array<float, arraySize> array_base{};
    std::array<float, arraySize> array_squared{};
    std::array<float, arraySize> array_sum{};

    // Fill the first array with the loop counter value
    for (int i = 0; i < arraySize; ++i) {
        array_base[i] = static_cast<float>(i);
    }

    // Fill the second array with the loop counter value squared
    for (int i = 0; i < arraySize; ++i) {
        array_squared[i] = static_cast<float>(i * i);
    }

    // Add base and squared to make the third array
    for (int i = 0; i < arraySize; ++i) {
        array_sum[i] = array_base[i] + array_squared[i];
    }

    // Display all three arrays
    for (int i = 0; i < arraySize; ++i) {
        std::cout << i << ": " << array_base[i] << " + " << array_squared[i] << " = " << array_sum[i] << std::endl;
    }
}
