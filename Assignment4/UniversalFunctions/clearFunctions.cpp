//
// Created by asuth on 2/14/2024.
//
#include <iostream>
#include <cstdlib>

void clearScreen() {
#ifdef _WIN32
    // For Windows
    std::system("cls");
#else
    // For Unix-based systems (Linux, macOS)
    std::system("clear");
#endif
}

bool clearInputBuffer() {
    if (std::cin.fail()) {
        // Clear error flags
        std::cin.clear();

        // Discard the rest of the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true; // Input buffer cleared successfully
    }

    return false; // Input buffer was not in a fail state
}

