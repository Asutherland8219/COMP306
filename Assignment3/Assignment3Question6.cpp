//
// Created by asuth on 12/12/2023.
//

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




