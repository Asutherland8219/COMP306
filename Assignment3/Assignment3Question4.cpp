//
// Created by asuth on 12/10/2023.
//
#include <iostream>

void floatingPointArray() {
    const int arraySize = 25;
    float array1[arraySize];
    float array2[arraySize];
    float array3[arraySize];

    // Fill the first array with the loop counter value
    for (int i = 0; i < arraySize; ++i) {
        array1[i] = static_cast<float>(i);
    }

    // Fill the second array with the loop counter value squared
    for (int i = 0; i < arraySize; ++i) {
        array2[i] = static_cast<float>(i * i);
    }

    // Add corresponding elements from the first two arrays and fill the third array
    for (int i = 0; i < arraySize; ++i) {
        array3[i] = array1[i] + array2[i];
    }

    // Display all three arrays
    for (int i = 0; i < arraySize; ++i) {
        std::cout << i << ": " << array1[i] << " + " << array2[i] << " = " << array3[i] << std::endl;
    }
}