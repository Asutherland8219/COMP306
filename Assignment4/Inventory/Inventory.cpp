//
// Created by asuth on 12/13/2023.
//

#include "Inventory.h"
#include <iostream>

// Constructor
Inventory::Inventory() {}

// Method to add an item to the inventory
void Inventory::addItem(const Item& newItem) {
    items.push_back(newItem);
}

// Method to display the inventory
void Inventory::displayInventory() {
    std::cout << "Inventory:\n";
    for (const auto& item : items) {
        std::cout << "Name: " << item.getName() << "\n";
        std::cout << "Description: " << item.getDescription() << "\n";
    }
}

// The internal inventory, this will be called by internal logic in order to get the flag value for
// future calculations.
void Inventory::_displayInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& item : items) {
        std::cout << "Name: " << item.getName() << "\n";
        std::cout << "Description: " << item.getDescription() << "\n";
        std::cout << "Value: " << item.getValue() << "\n\n";
    }
}