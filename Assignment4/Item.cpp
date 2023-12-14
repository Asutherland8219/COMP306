//
// Created by asuth on 12/13/2023.
//

#include "Item.h"

// Constructor
Item::Item(const std::string& name, const std::string& description, int value)
        : name(name), description(description), value(value) {}

// Getters
std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

int Item::getValue() const {
    return value;
}