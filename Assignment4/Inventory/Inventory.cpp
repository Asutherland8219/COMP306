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
    // Check if the item already exists in the inventory
    auto it = std::find_if(items.begin(), items.end(),
                           [&newItem](const Item& item) {
                               return item.getName() == newItem.getName();
                           });

    if (it == items.end()) {
        // Item not found in the inventory, add it
        items.push_back(newItem);
        std::cout << "Item added: " << newItem.getName() << "\n";
    } else {
        // Item already exists, do not add duplicate
        std::cout << "Item already exists in the inventory: " << newItem.getName() << "\n";
    }
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
std::vector<Item> Inventory::_displayInventory() const {
    return items;
    }

// Implementation of dropItem function
void Inventory::dropItem(const std::string& itemName) const {
    // Find the item based on the string given
    auto it = std::find_if(items.begin(), items.end(),
                           [&itemName](const Item& item) {
                               return item.getName() == itemName;
                           });
    if (it != items.end()) {
        // Item found, erase it from the inventory
        items.erase(it);

        // Raise a prompt saying "Item dropped"
        std::cout << "\n";
        std::cout << "Item dropped: " << itemName << "\n";
        std::cout << "\n";
    } else {
        // Item not found, raise a prompt indicating that it's not in the inventory
        std::cout << "Item not found in the inventory: " << itemName << "\n";
    }
}

// Implementation of getInventoryItem function
Item Inventory::getInventoryItem(const std::string& itemName) {
    auto it = std::find_if(items.begin(), items.end(),
                           [&itemName](const Item& item) {
                               return item.getName() == itemName;
                           });

        // Return the found item directly by value
        return *it;
}



void Inventory::updateItem(const std::string& oldName, const Item& updatedItem) const {
    auto it = std::find_if(items.begin(), items.end(),[&oldName](const Item& item) {
                               return item.getName() == oldName;
                           });

    if (it != items.end()) {
        // Item found, update it
        std::cout << "Item Updated: " << oldName << " -> " << updatedItem.getName() << "\n";
        // Update both the name and description
        it->setName(updatedItem.getName());
        it->setDescription(updatedItem.getDescription());
    } else {
        // Item not found, raise a prompt indicating that it's not in the inventory
        std::cout << "Item not found in the inventory: " << oldName << "\n";
    }
}
