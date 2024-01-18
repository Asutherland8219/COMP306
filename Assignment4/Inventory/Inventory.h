//
// Created by asuth on 12/13/2023.
//

#ifndef COMP306_INVENTORY_H
#define COMP306_INVENTORY_H


#include <vector>
#include "Items/Item.h" // Include the header for the Item class

class Inventory {
public:
    // Constructors
    Inventory();

    // Methods
    void addItem(const Item& newItem);
    void displayInventory() const;
    // Internal Inventory
    void _displayInventory() const;

private:
    std::vector<Item> items;
};



#endif //COMP306_INVENTORY_H
