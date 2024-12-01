#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
// #include "../Character_header/MainCharacter.h"
#include "Swords.h"
#include "Potions.h"

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
    // const std::vector<Potion>& getPotions() const;  // Get list of potions
    // const std::vector<Sword>& getSwords() const;
    // void usePotion(MainCharacter &player, const string &name);
    // void equipSword(MainCharacter &player, const string &name);
    //     void open(MainCharacter &player);

};

#endif // INVENTORY_H