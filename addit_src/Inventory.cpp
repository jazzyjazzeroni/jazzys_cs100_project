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

const Sword& Inventory::getSword(const string &name) const {
    for (const auto &sword : swords) {
        if (sword.getName() == name) {
            return sword; // Return a copy of the sword if found
        }
    }
    throw runtime_error("Sword '" + name + "' not found!"); // Throw an error if sword not found
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

const Potion& Inventory::getPotion(const string &name) const {
    for (const auto &potion : potions) {
        if (potion.getType() == name) {
            return potion; // Return a copy of the potion if found
        }
    }
throw runtime_error("Potion '" + name + "' not found!"); // Throw an error if potion not found
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

// void Inventory::open(MainCharacter &player) {
//     cout << "Inventory:\n";
//     cout << "Swords:\n";
//     for (const auto &sword : swords) {
//         cout << sword.getName() << " - Damage: " << sword.getPower() << endl;
//     }
//     cout << "Potions:\n";
//     for (const auto &potion : potions) {
//         cout << potion.getType() << " - Heal: " << potion.getHealingAmount() << endl;
//     }
// }

// int main() {
//     try {
//         // Create Inventory object
//         Inventory inv;

//         // Create items
//         Sword excalibur(50, "Excalibur");
//         Sword katana(35, "Katana");
//         Potion healPotion(25, "Healing Potion");
//         Potion manaPotion(20, "Mana Potion");

//         // Add items to inventory
//         inv.addSword(excalibur);
//         inv.addSword(katana);
//         inv.addPotion(healPotion);
//         inv.addPotion(manaPotion);

//         // Test retrieval of items
//         cout << "Retrieving 'Excalibur': " << inv.getSword("Excalibur").getName() << endl;
//         cout << "Retrieving 'Healing Potion': " << inv.getPotion("Healing Potion").getType() << endl;

//         // Test existence of items
//         cout << "Has 'Katana'? " << (inv.hasSword("Katana") ? "Yes" : "No") << endl;
//         cout << "Has 'Sting'? " << (inv.hasSword("Sting") ? "Yes" : "No") << endl;

//         // Test removal of items
//         inv.removeSword("Katana");
//         cout << "After removal, has 'Katana'? " << (inv.hasSword("Katana") ? "Yes" : "No") << endl;

//         inv.removePotion("Mana Potion");
//         cout << "After removal, has 'Mana Potion'? " << (inv.hasPotion("Mana Potion") ? "Yes" : "No") << endl;
//         cout << "\nRemaining swords in inventory:\n";
//         for (const auto &sword : inv.getSwords()) {
//             cout << "  " << sword.getName() << " - Damage: " << sword.getPower() << endl;
//         }

//         cout << "\nRemaining potions in inventory:\n";
//         for (const auto &potion : inv.getPotions()) {
//             cout << "  " << potion.getType() << " - Heal: " << potion.getHealingAmount() << endl;
//         }
//     }
//     catch (const runtime_error &e) {
//         cerr << "Error: " << e.what() << endl;
//     }

//     return 0;
// }