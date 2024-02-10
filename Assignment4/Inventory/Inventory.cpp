//
// Created by asuth on 12/13/2023.
//

/*
 Base Inventory class. Initialize with the Character class. Simple functions such as addItem which adds item, and display
 inventory which lists the inventory alaong with their name, and description.

 Internal function use is listed with a suffix of _, _display_inventory mirrors the main display inventory function
 except also returns a value. This value will be used in calculations with the choices matrix later.
 */

#include "Inventory.h"
#include <iostream>

// Constructor
Inventory::Inventory() {}
std::vector<Item> Inventory::items;

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