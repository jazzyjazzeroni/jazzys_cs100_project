#include "../addit_header/Inventory.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Inventory::addSword(const Sword &sword) {
    swords.push_back(sword); // Adds a copy of the sword to the inventory
}

void Inventory::removeSword(const string &name) {
    for (auto it = swords.begin(); it != swords.end(); ++it) {
        if (it->getName() == name) {
            swords.erase(it);
            break;
        }
    }
}

Sword Inventory::getSword(const string &name) const {
    for (const auto &sword : swords) {
        if (sword.getName() == name) {
            return sword; // Return a copy of the sword if found
        }
    }
    throw runtime_error("Sword not found!"); // Throw an error if sword not found
}

bool Inventory::hasSword(const std::string &name) const {
    for (const auto &sword : swords) {
        if (sword.getName() == name) {
            return true;
        }
    }
    return false;
}

void Inventory::addPotion(const Potion &potion) {
    potions.push_back(potion); // Adds a copy of the potion to the inventory
}

void Inventory::removePotion(const string &name) {
    for (auto it = potions.begin(); it != potions.end(); ++it) {
        if (it->getType() == name) {
            potions.erase(it);
            break;
        }
    }
}

Potion Inventory::getPotion(const string &name) const {
    for (const auto &potion : potions) {
        if (potion.getType() == name) {
            return potion; // Return a copy of the potion if found
        }
    }
    throw runtime_error("Potion not found!"); // Throw an error if potion not found
}

bool Inventory::hasPotion(const std::string &name) const {
    for (const auto &potion : potions) {
        if (potion.getType() == name) {
            return true;
        }
    }
    return false;
}

const std::vector<Potion>& Inventory::getPotions() const {
    return potions;
}

const std::vector<Sword>& Inventory::getSwords() const {
    return swords;
}

void Inventory::open(MainCharacter &player) {
    cout << "Inventory:\n";
    cout << "Swords:\n";
    for (const auto &sword : swords) {
        cout << sword.getName() << " - Damage: " << sword.getPower() << endl;
    }
    cout << "Potions:\n";
    for (const auto &potion : potions) {
        cout << potion.getType() << " - Heal: " << potion.getHealingAmount() << endl;
    }
}
