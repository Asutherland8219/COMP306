//
// Created by asuth on 12/13/2023.
//

#ifndef COMP306_ITEM_H
#define COMP306_ITEM_H

#include <string>

class Item {
public:
    // Constructors
    Item(const std::string& name, const std::string& description, int value);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    int getValue() const;
    void setName(const std::string& newName);
    void setDescription(const std::string& newDescription);
    std::string name;



private:
    std::string description;
    int value;
};


#endif //COMP306_ITEM_H
