
#include "../addit_header/Inventory.h"
<<<<<<< HEAD
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
=======

using namespace std;

// Potion management
void Inventory::addPotion(const Potion& potion) {
    potions.push_back(potion);
}

void Inventory::removePotion(const std::string& name) {
    potions.erase(
        remove_if(potions.begin(), potions.end(), [&name](const Potion& potion) {
            return potion.getType() == name;
        }),
        potions.end()
    );
}

bool Inventory::hasPotion(const std::string& name) const {
    return any_of(potions.begin(), potions.end(), [&name](const Potion& potion) {
        return potion.getType() == name;
    });
}

Potion Inventory::getPotion(const std::string& name) const {
    auto it = find_if(potions.begin(), potions.end(), [&name](const Potion& potion) {
        return potion.getType() == name;
    });
    if (it != potions.end()) {
        return *it;
    }
    throw runtime_error("Potion not found");
}

// Print inventory contents
void Inventory::print() const {
    cout << "Potions in inventory:" << endl;
    for (const auto& potion : potions) {
        potion.print();
    }
}

void Inventory::usePotion(MainCharacter& mainCharacter) {
    if (potions.empty()) {
        cout << "No potions in inventory" << endl;
        return;
    }
>>>>>>> master

    cout << "Select a potion to use:" << endl;
    for (size_t i = 0; i < potions.size(); i++) {
        cout << i + 1 << ". ";
        potions[i].print();
    }

<<<<<<< HEAD
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

=======
    int choice;
    cout << "Enter choice: ";
    while (!(cin >> choice) || choice < 1 || choice > potions.size()) {
        cout << "Invalid choice. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    mainCharacter.heal(potions[choice - 1].getHealingAmount());
    removePotion(potions[choice - 1].getType());
}
>>>>>>> master
