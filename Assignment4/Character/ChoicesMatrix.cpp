//
// Created by asuth on 1/17/2024.
//

/* This is where the matrix assigned to the character will be created. It will also house any functions that modify
    the matrix. The purpose of the matrix, is that it will be used to gauge outcomes of the story. The overarching
    quest and progression is linear and will not change, but choices the character makes will change the final outcome.
    For example, a matrix of all 0's is default, while a matrix of 1 or 2's would result in a normal/optimal outcome etc..
*/

#include <vector>
#include <iostream>

class CharacterMatrix {
private:
    std::vector<std::vector<int>> matrix;

public:
    // Default constructor to initialize the matrix as 3x3 with zeros
    CharacterMatrix() : matrix(3, std::vector<int>(3, 0)) {}

    // Increment the value at a specific row and column
    void incrementValue(int row, int column) {
        if (row >= 0 && row < matrix.size() && column >= 0 && column < matrix[0].size()) {
            matrix[row][column]++;
        }
    }

    // Display the matrix (for debugging purposes)
    void displayMatrix() const {
        for (const auto& row : matrix) {
            for (int value : row) {
                std::cout << value << ' ';
            }
            std::cout << '\n';
        }
    }
};

