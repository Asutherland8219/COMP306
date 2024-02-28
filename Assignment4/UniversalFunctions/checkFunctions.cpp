//
// Created by asuth on 2/17/2024.
//


// Function to check if an item exists in the inventory
bool checkInventory(const std::string& itemName, const Character& character) {
    const Inventory& userInventory = character.inventory;

    // Check if the item with the specified name exists in the inventory
    auto it = std::find_if(userInventory.items.begin(), userInventory.items.end(),
                           [&itemName](const Item& item) {
                               return item.getName() == itemName;
                           });

    // Return true if the item was found, false otherwise
    return it != userInventory.items.end();
}
