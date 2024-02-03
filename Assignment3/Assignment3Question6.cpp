/*
 Title: Assignment3Question6.cpp
 Description: Create a set, with a template, similar to the STD::set and then compare the two sets
 Date: January 28th, 2024
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create a custom set, to mimic the std::set, with a template, and compare the two models

 Compile (assuming Cygwin is running): g++ -o Assignment3 Assignment3Question6.cpp
 Execution (assuming Cygwin is running): ./Assignment3Question6.exe

 Classes (functions):
    - Class

        - Set - the set object, contains custom element types. Example being integers.
            - Variables
                - std::vector<items> elements - the set default, a vector of various items of a custom type.

        - Iterator - the iterator that moves through the set
            - Variables
                - std::vector<items>::iterator itr - the iterator value for determining location in the set.

    - Function
        - Iterator() - Iterator constructor
        - begin() - moves to the beginning of the set.
        - end() - moves to the end of the set.
        - add() - adds to the set, only executes if the elements are not duplicate

    - template
        - <typename> items - the template for this function. Allowing multiple types.

*/

/*
 TEST PLAN

 Normal case:
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

    Output:
        Custom Set: 1 2 3

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

    Output:
        STD Set: 1 2 3

 Bad Case
    Not user input based, so less likely to experience any serious issues. The type for the set is declared
    when it is created. This means if you combine types, it would error out before adding it to the set.

 Discussion:
    Create a custom set to mimic the STD set. Create a template with the set, to allow for custom types to be added to the set.
    Add validation to not return duplicate values to the test. Though not required in this assignment, it would be good to add
    error handling/exception raising if duplicates are added.

*/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename items>
class Set {
private:
    std::vector<items> elements;

public:
    class Iterator {
    private:
        typename std::vector<items>::iterator current;

    public:
        Iterator(typename std::vector<items>::iterator itr) : current(itr) {}

        items operator*() const {
            return *current;
        }

        // Overload != operator
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        // Overload ++ operator (pre-increment)
        Iterator& operator++() {
            ++current;
            return *this;
        }
    };
    // Add element to the set
    void add(const items element) {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
            elements.push_back(element);
        }
    }

    // Return iterator pointing to the beginning of the set
    Iterator begin() {
        return Iterator(elements.begin());
    }

    // Return iterator representing the "end" sentinel
    Iterator end() {
        return Iterator(elements.end());
    }

};




