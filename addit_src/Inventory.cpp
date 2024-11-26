#include "Inventory.h"

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
// void Inventory::addSword(const string &name, int damage)
// {
//     swords.emplace_back(name, damage);
// }

// void Inventory::addPotion(const string &name, int healAmount)
// {
//     swords.emplace_back(name, healAmount);
// }

// void Inventory::removeSword(const string &name) {
//     for (auto i = swords.begin(); i != swords.end(); i++) {
//         if (i->name == name) {
//             swords.erase(i);
//             return;
//         }
//         else 
//             std::cout << "No sword equipped. Continue your journey to find one!\n";
//     }
// }

// void Inventory::removePotion(const string &name) {
//     for (auto i = swords.begin(); i != swords.end(); i++) {
//         if (i->name == name) {
//             swords.erase(i);
//             return;
//         }
//         else 
//             std::cout << "No potion is in your inventory. Continue your journey to find one!\n";
//     }
// }


// // I do need someone to take a look at the two Item* implemented
// Item* Inventory::getSword(const string &name)
// {

//     for(auto &sword : swords)
//     {
//         if(sword.name == name) return &sword;
//     }
//     std::cout << "No sword found in your inventory.\n";
// }

// Item* Inventory::getPotion(const string &name)
// {
//     for(auto &potion : potions)
//     {
//         if(potion.name == name) return &potion;
//     }
//     std::cout << "No potion found in your inventory.\n";
// }


#include "Inventory.h"

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
    // You can add more interactions here based on player actions
}

// Use a potion on the player
void Inventory::usePotion(MainCharacter &player, const string &name) {
    for (auto it = potions.begin(); it != potions.end(); ++it) {
        if (it->getType() == name) {
            player.heal(it->getHealingAmount());
            potions.erase(it);  // Remove the potion after use
            cout << "Used potion: " << name << endl;
            return;
        }
    }
    cout << "Potion not found!" << endl;
}

// Equip a sword for the player
void Inventory::equipSword(MainCharacter &player, const string &name) {
    for (const auto &sword : swords) {
        if (sword.getName() == name) {
            player.equipSword(sword); // Equip the sword (assuming equipSword takes a Sword object)
            cout << "Equipped sword: " << name << endl;
            return;
        }
    }
    cout << "Sword not found!" << endl;
}

// Display inventory status (potions, swords, etc.)
void Inventory::printStatus() const {
    cout << "Inventory Status:\n";
    cout << "Swords: " << swords.size() << " items\n";
    cout << "Potions: " << potions.size() << " items\n";
}
