#include "../addit_header/Inventory.h"
#include "../Character_header/MainCharacter.h"
#include <iostream>
#include <stdexcept>

void Inventory::addSword(const Sword &sword) {
    swords.push_back(sword);
}

void Inventory::removeSword(const std::string &name) {
    for (auto it = swords.begin(); it != swords.end(); ++it) {
        if (it->getName() == name) {
            swords.erase(it);
            break;
        }
    }
}

const Sword& Inventory::getSword(const std::string &name) const {
    for (const auto &sword : swords) {
        if (sword.getName() == name) {
            return sword;
        }
    }
    throw std::runtime_error("Sword '" + name + "' not found!");
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
    potions.push_back(potion);
}

void Inventory::removePotion(const std::string &name) {
    for (auto it = potions.begin(); it != potions.end(); ++it) {
        if (it->getType() == name) {
            potions.erase(it);
            break;
        }
    }
}

const Potion& Inventory::getPotion(const std::string &name) const {
    for (const auto &potion : potions) {
        if (potion.getType() == name) {
            return potion;
        }
    }
    throw std::runtime_error("Potion '" + name + "' not found!");
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

