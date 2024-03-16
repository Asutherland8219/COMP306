//
// Created by asuth on 12/13/2023.
//

#ifndef COMP306_INVENTORY_H
#define COMP306_INVENTORY_H


#include <vector>
#include "Items/Item.h" // Include the header for the Item class
#include <algorithm>

class Inventory {
public:
    // Constructors
    Inventory();

    // Methods
    static void addItem(const Item& newItem);
    static void displayInventory() ;
    // Internal Inventory
    std::vector<Item> _displayInventory() const;
    static std::vector<Item> items;
    void dropItem(const std::string& itemName) const;
    static Item getInventoryItem(const std::string& itemName) ;
    void updateItem(const std::string& oldName, const Item& updatedItem) const;
};



#endif //COMP306_INVENTORY_H
