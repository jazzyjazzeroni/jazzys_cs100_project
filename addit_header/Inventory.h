#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <string>
#include <iostream>
#include <vector>
#include "Potions.h"   // Assuming you have a separate Potions class
#include "Swords.h"    // Assuming you have a separate Swords class
#include "../Character_header/MainCharacter.h" 

using namespace std;

class Inventory {
private:
    vector<Sword> swords;        // Vector to hold swords
    vector<Potion> potions;      // Vector to hold potions

public:
    void addSword(const Sword &sword);
    void removeSword(const string &name);
    const Sword& getSword(const string &name) const;
    bool hasSword(const std::string &name) const;
    void addPotion(const Potion &potion);
    void removePotion(const string &name);
    const Potion& getPotion(const string &name) const;
    bool hasPotion(const std::string &name) const;
    void open(MainCharacter &player);
    const std::vector<Potion>& getPotions() const;  // Get list of potions
    const std::vector<Sword>& getSwords() const;
    void usePotion(MainCharacter &player, const string &name);
    void equipSword(MainCharacter &player, const string &name);
};

#endif