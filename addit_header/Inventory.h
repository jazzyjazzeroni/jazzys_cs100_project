// #include <string>
// #include <iostream>
// #include <vector>
// #include "Potions.h"
// #include "Swords.h"
// using namespace std;
// #ifndef __INVENTORY_H__
// #define __INVENTORY_H__

// class Item {
// public:
//     string name;
//     int value;

//     Item(string name, int value) : name(name), value(value) {}
// };

// class Inventory {
// private:
//     vector<Item> swords;
//     vector<Item> potions;

// public:
//     void addSword(const string &name, int damage);
//     void addPotion(const string &name, int healAmount);

//     void removeSword(const string &name);
//     void removePotion(const string &name);

//     Item* getSword(const string &name);
//     Item* getPotion(const string &name);
// };

// #endif

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
    
    // Methods to manage potions
    void addPotion(const Potion &potion);
    void removePotion(const string &name);
    Potion getPotion(const string &name) const;

    // Display current inventory for the player
    void open(MainCharacter &player);

    // Use a potion on the player
    void usePotion(MainCharacter &player, const string &name);

    // Equip a sword for the player
    void equipSword(MainCharacter &player, const string &name);

    // Display current inventory status
    void printStatus() const;
};

#endif
