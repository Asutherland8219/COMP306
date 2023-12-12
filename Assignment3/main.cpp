//
// Created by alex on 27/08/23.
//
#include "inputMenu.cpp"
#include "Assignment3Question4.cpp"
#include "Assignment3Question5.cpp"
#include "Assignment3Question6.cpp"

int main() {
    // Question 1, 2, 3
//    inputMenu();

    // Question 4
    floatingPointArray();
    std::cout << std::endl;

    // Question 6
    Set<int> set;
    set.add(1);
    set.add(2);
    set.add(4);

    // add a duplicate
    set.add(4);

    // Output set
    std::cout << "Custom Set: ";
    for (const auto& element : set) {
        std::cout << element << " ";
    }
    std::cout << std::endl;


    // Question 5
    std::cout << std::endl;
    Bookshelf bookshelf;
    bookshelf.testBookshelf();

    // Test second condition
    bookshelf.testSecondCondition();

    // Test invalid book
    bookshelf.testInvalidBook();

    // Test duplicate entries
    bookshelf.testDuplicateEntries();


};

