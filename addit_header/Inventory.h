#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <string>
#include <iostream>
#include <vector>
#include "Potions.h"   // Assuming you have a separate Potions class
#include "Swords.h"    // Assuming you have a separate Swords class
#include "MainCharacter.h" // Assuming MainCharacter is the player character

using namespace std;

class Inventory {
private:
    vector<Sword> swords;        // Vector to hold swords
    vector<Potion> potions;      // Vector to hold potions

public:
    // Methods to manage swords
    void addSword(const Sword &sword);
    void removeSword(const string &name);
    Sword getSword(const string &name) const;
    bool hasSword(const std::string &name) const;
    
    // Methods to manage potions
    void addPotion(const Potion &potion);
    void removePotion(const string &name);
    Potion getPotion(const string &name) const;
    bool hasPotion(const std::string &name) const;

    // Display current inventory for the player
    void open(MainCharacter &player);

    const std::vector<Potion>& getPotions() const;  // Get list of potions
    const std::vector<Sword>& getSwords() const;

    // Use a potion on the player
    void usePotion(MainCharacter &player, const string &name);

    // Equip a sword for the player
    void equipSword(MainCharacter &player, const string &name);

   
};

#endif