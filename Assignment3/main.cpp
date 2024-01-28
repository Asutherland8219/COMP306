//
// Created by alex on 27/08/23.
//
#include "inputMenu.cpp"
#include "Assignment3Question4.cpp"
#include "Assignment3Question5.cpp"
#include "Assignment3Question6.cpp"
#include <set>

int main() {
    // Question 1, 2, 3
    inputMenu();

    // Question 4
    floatingPointArray();
    std::cout << std::endl;

    // Question 5
    std::cout << std::endl;
    Bookshelf bookshelf;
    bookshelf.testBookshelf();

    // Test second condition
    bookshelf.testSecondCondition();

    // Question 6 Custom set
    Set<int> set;
    set.add(1);
    set.add(2);
    set.add(3);

    // add a duplicate
    set.add(3);

    // Output set
    std::cout << "Custom Set: ";
    for (const int element : set) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Standard C++ set
    std::set<int> stdSet;
    stdSet.insert(1);
    stdSet.insert(2);
    stdSet.insert(3);
    // Duplicate test
    stdSet.insert(3);

    std::cout << "STD Set: ";
    for (const int stdelem : stdSet) {
        std::cout << stdelem << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test cases for Bookshelf with assertions and custom error messages: \n";
    // Test invalid book
    std::cout << "- Invalid book; too few values. \n";
    bookshelf.testInvalidBookFew();

    std::cout << "- Invalid book; too many values. \n";
    bookshelf.testInvalidBookMany();

    // Test duplicate entries
    std::cout << "- Duplicate ISBN values \n";
    bookshelf.testDuplicateEntries();


};

