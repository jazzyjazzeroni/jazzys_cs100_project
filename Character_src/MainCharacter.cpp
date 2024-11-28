#include "../Character_header/MainCharacter.h"
#include <iostream>

using namespace std;

// Constructor
MainCharacter::MainCharacter(const std::string &name, int health, int attackStrength, const std::string &allegiance)
    : allegiance(allegiance), x(0), y(0), powers("FUSED_POWER") { // Default power as "FUSED_POWER"
    this->name = name;
    this->health = health;
    this->attackAmount = attackStrength;
    this->type = MAINCHAR;
}

void MainCharacter::attack(Character &opponent) {
    cout << name << " attacks " << opponent.getType() << " with a sword, dealing " << attackAmount << " damage!" << endl;
    opponent.recieveDamage(attackAmount);

    if (!opponent.isalive()) {
        std::cout << "The opponent has been defeated!" << std::endl;
    }
}

void MainCharacter::heal(int amount) {
    health = min(health + amount, MAX_HEALTH); // Prevent exceeding MAX_HEALTH
    cout << name << " heals for " << amount << " health points. Current health: " << health << endl;
}

void MainCharacter::usePowers() {
    cout << name << " uses a special power!" << endl;
    powers.usePower(powers.getPower(), allegiance); // Assuming `activate()` is a method in `Powers`
}

void MainCharacter::usePotion(const string &potionName) {
    for (auto &potion : inventory.getPotions()) { // Access potions directly
        if (potion.getType() == potionName) {
            heal(potion.getHealingAmount()); // Heal the character
            inventory.removePotion(potionName); // Remove used potion
            cout << "Used potion: " << potionName << endl;
            return;
        }
    }
    cout << "Potion not found in inventory!" << endl;
}

void Character::updateElementForLevel() {
    currentElement = level.getElementForLevel(level.getCurrentLevel());
}

Power_type Character::getCurrentElement() const {
    return currentElement;
}

void MainCharacter::usePotion(const string &potionName) {
    if (inventory.hasPotion(potionName)) {
        Potion potion = inventory.getPotion(potionName); // Get potion from inventory
        heal(potion.getHealingAmount());                // Apply its effect
        inventory.removePotion(potionName);             // Remove it from inventory
        cout << "Used potion: " << potionName << endl;
    } else {
        cout << "Potion not found in inventory!" << endl;
    }
}
// Add sword function (pick up a sword)
    void MainCharacter::equipSword(const Sword & newSword) {
        //todo give o[ption to swap or replace sword]
            // Swap or replace the sword
            this->sword = Sword(newSword.getValue(), "New Sword");
            inventory.addSword(newSword);
    }
    // Equips a sword
//     void MainCharacter::equipSword(Object & newSword) {
//         if (newSword.getType() == "sword") {
//             // Swap or replace the sword
//             this->sword = Sword(newSword.getValue(), "New Sword");

//         }
//     for (const auto &sword : inventory.getSwords()) { // Access swords directly
//         if (sword.getName() == swordName) {
//             attackAmount = sword.getPower(); // Equip and update attack strength
//             cout << "Equipped sword: " << swordName << " (Damage: " << sword.getPower() << ")" << endl;
//             return;
//         }
//     }
//     cout << "Sword not found in inventory!" << endl;
// }
  

MainCharacter::MainCharacter(int x, int y) : x(x), y(y), powers("FUSED_POWER") {}
    int MainCharacter::mod(int value, int limit) {
        return (value % limit + limit) % limit;  // Handle negative values properly
    }

    Object MainCharacter::move(char action, GameMap &gameMap) {
        int New_x = x, New_y = y;

        if (action == 'w') { // Move up
            New_y = mod(y - 1, gameMap.getHeight()); // Wrap around vertically
        } else if (action == 's') { // Move down
            New_y = mod(y + 1, gameMap.getHeight()); // Wrap around vertically
        } else if (action == 'a') { // Move left
            New_x = mod(x - 1, gameMap.getWidth()); // Wrap around horizontally
        } else if (action == 'd') { // Move right
            New_x = mod(x + 1, gameMap.getWidth()); // Wrap around horizontally
        }

        x = New_x;
        y = New_y;

        return gameMap.getObjectAt(x, y);
    }

    pair<int, int> MainCharacter::getPosition() const {
        return {x, y};
    }

    void MainCharacter::attack(Character &target) {
         if (target.getType() == GOBLIN) { 
        Goblin &goblin = dynamic_cast<Goblin &>(target);
        cout << name << " attacks the Goblin fiercely with a sword, dealing " 
             << attackAmount << " damage!" << endl;
        goblin.recieveDamage(attackAmount);
    } else {
        cout << name << " attacks the opponent with a sword, dealing " 
             << attackAmount << " damage!" << endl;
        target.recieveDamage(attackAmount);
    }

    if (!target.isalive()) {
        cout << "The opponent has been defeated!" << endl;
    }
    }

    void MainCharacter::heal(int amount) {
        setHealth(getHealth() + amount); // Assuming you have a setHealth method in Character
    }

    // todo Check if the character is alive
    // bool MainCharacter::isalive() const {
    //     return (getHealth() > 0);
    // };


    // todo Update the element based on the current level
