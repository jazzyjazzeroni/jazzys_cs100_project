<<<<<<< HEAD
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "Swords.h"
#include "Potions.h"
=======

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "./Potions.h"
#include <iostream>
#include <algorithm>
>>>>>>> master


class Inventory {
private:
    std::vector<Potion> potions{};      // Vector to hold potions

public:
<<<<<<< HEAD
    void addSword(const Sword &sword);
    void removeSword(const string &name);
    const Sword& getSword(const string &name) const;
    bool hasSword(const std::string &name) const;
    void addPotion(const Potion &potion);
    void removePotion(const string &name);
    const Potion& getPotion(const string &name) const;
    bool hasPotion(const std::string &name) const;
    const std::vector<Potion>& getPotions() const;  // Get list of potions
    const std::vector<Sword>& getSwords() const;
    // void usePotion(MainCharacter &player, const string &name);
    // void equipSword(MainCharacter &player, const string &name);
        // void open(MainCharacter &player);

};

#endif // INVENTORY_H
=======
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
>>>>>>> master
