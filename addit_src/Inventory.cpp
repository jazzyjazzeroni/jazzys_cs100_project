
// #include "Inventory.h"

// // Adds a sword to the inventory
// void Inventory::addSword(const Sword &sword) {
//     swords.push_back(sword); // Adds a copy of the sword to the inventory
// }

// // Removes a sword from the inventory
// void Inventory::removeSword(const string &name) {
//     for (auto it = swords.begin(); it != swords.end(); ++it) {
//         if (it->getName() == name) {
//             swords.erase(it);
//             break;
//         }
//     }
// }

// // Retrieves a sword by name from the inventory
// Sword Inventory::getSword(const string &name) const {
//     for (const auto &sword : swords) {
//         if (sword.getName() == name) {
//             return sword; // Return a copy of the sword if found
//         }
//     }
//     throw runtime_error("Sword not found!"); // Throw an error if sword not found
// }

// // Adds a potion to the inventory
// void Inventory::addPotion(const Potion &potion) {
//     potions.push_back(potion); // Adds a copy of the potion to the inventory
// }

// // Removes a potion from the inventory
// void Inventory::removePotion(const string &name) {
//     for (auto it = potions.begin(); it != potions.end(); ++it) {
//         if (it->getType() == name) {
//             potions.erase(it);
//             break;
//         }
//     }
// }

// // Retrieves a potion by name from the inventory
// Potion Inventory::getPotion(const string &name) const {
//     for (const auto &potion : potions) {
//         if (potion.getType() == name) {
//             return potion; // Return a copy of the potion if found
//         }
//     }
//     throw runtime_error("Potion not found!"); // Throw an error if potion not found
// }

// // Open inventory to display items
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
//     // You can add more interactions here based on player actions
// }

// // Use a potion on the player
// void Inventory::usePotion(MainCharacter &player, const string &name) {
//     for (auto it = potions.begin(); it != potions.end(); ++it) {
//         if (it->getType() == name) {
//             player.heal(it->getHealingAmount());
//             potions.erase(it);  // Remove the potion after use
//             cout << "Used potion: " << name << endl;
//             return;
//         }
//     }
//     cout << "Potion not found!" << endl;
// }

// // Equip a sword for the player
// void Inventory::equipSword(MainCharacter &player, const string &name) {
//     for (const auto &sword : swords) {
//         if (sword.getName() == name) {
//             player.equipSword(sword); // Equip the sword (assuming equipSword takes a Sword object)
//             cout << "Equipped sword: " << name << endl;
//             return;
//         }
//     }
//     cout << "Sword not found!" << endl;
// }

// // Display inventory status (potions, swords, etc.)
// void Inventory::printStatus() const {
//     cout << "Inventory Status:\n";
//     cout << "Swords: " << swords.size() << " items\n";
//     cout << "Potions: " << potions.size() << " items\n";
// }


#include "../addit_header/Inventory.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Adds a sword to the inventory
void Inventory::addSword(const Sword &sword) {
    swords.push_back(sword); // Adds a copy of the sword to the inventory
}

// Removes a sword from the inventory
void Inventory::removeSword(const string &name) {
    for (auto it = swords.begin(); it != swords.end(); ++it) {
        if (it->getName() == name) {
            swords.erase(it);
            break;
        }
    }
}

// Retrieves a sword by name from the inventory
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

// Adds a potion to the inventory
void Inventory::addPotion(const Potion &potion) {
    potions.push_back(potion); // Adds a copy of the potion to the inventory
}

// Removes a potion from the inventory
void Inventory::removePotion(const string &name) {
    for (auto it = potions.begin(); it != potions.end(); ++it) {
        if (it->getType() == name) {
            potions.erase(it);
            break;
        }
    }
}

// Retrieves a potion by name from the inventory
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

// Getter for swords
const std::vector<Sword>& Inventory::getSwords() const {
    return swords;
}

// Open inventory to display items
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
