
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "./Potions.h"
#include <iostream>
#include <algorithm>


class Inventory {
private:
    std::vector<Potion> potions{};      // Vector to hold potions

public:
    Inventory() = default; // Default constructor
    ~Inventory() = default; // Default destructor

    // Potion management
    void addPotion(const Potion& potion);
    void removePotion(const std::string& name);
    bool hasPotion(const std::string& name) const;
    Potion getPotion(const std::string& name) const;
    void usePotion(MainCharacter& );

    // Print inventory contents
    void print() const;
};

#endif