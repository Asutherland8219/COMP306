//
// Created by asuth on 12/10/2023.
//
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
