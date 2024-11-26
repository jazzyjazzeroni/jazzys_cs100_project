#include "../Character_header/MainCharacter.h"
#include <iostream>

using namespace std;

// Constructor
MainCharacter::MainCharacter(const string &name, int health, int attackStrength, const string &allegiance)
    : allegiance(allegiance) {
    this->name = name;
    this->health = health;
    this->attackAmount = attackStrength;
    this->type = MAINCHAR;
}

// Attacks the opponent
void MainCharacter::attack(Character &opponent) {
    cout << name << " attacks " << opponent.getType() << " with a sword, dealing " << attackAmount << " damage!" << endl;
    opponent.takeDamage(attackAmount);
}

// Interaction with the Witch
void MainCharacter::WitchInteraction() {
    cout << "You meet the witch in the forest." << endl;
    cout << "She offers to enhance your powers or health. What will you choose? (1 = Powers, 2 = Health): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        powers.useFusedPower(); // Assuming enhancement details in `Powers`
        cout << "Your ultimate power has been enhanced!" << endl;
    } else if (choice == 2) {
        heal(50);
        cout << "Your health increased by 50!" << endl;
    } else {
        cout << "Invalid choice. The witch vanishes into thin air." << endl;
    }
}

// Heals the character
void MainCharacter::heal(int amount) {
    health = min(health + amount, MAX_HEALTH); // Prevent exceeding MAX_HEALTH
    cout << name << " heals for " << amount << " health points. Current health: " << health << endl;
}

// Gets the movement direction
char MainCharacter::getMovement() {
    cout << "Enter movement direction (W/A/S/D): ";
    cin >> move;
    return move;
}

// Uses a power
void MainCharacter::usePowers() {
    cout << name << " uses a special power!" << endl;
    powers.activate(); // Assuming `activate()` is a method in `Powers`
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

// Equips a sword
void MainCharacter::equipSword(const string &swordName) {
    for (const auto &sword : inventory.getSwords()) { // Access swords directly
        if (sword.getName() == swordName) {
            attackAmount = sword.getPower(); // Equip and update attack strength
            cout << "Equipped sword: " << swordName << " (Damage: " << sword.getPower() << ")" << endl;
            return;
        }
    }
    cout << "Sword not found in inventory!" << endl;
}

// // Displays inventory items
// void MainCharacter::displayInventory() const {
//     cout << "Inventory:\n";
//     cout << "Swords:\n";
//     for (const auto &sword : inventory.getSwords()) {
//         cout << sword.getName() << " - Damage: " << sword.getPower() << endl;
//     }
//     cout << "Potions:\n";
//     for (const auto &potion : inventory.getPotions()) {
//         cout << potion.getType() << " - Heal: " << potion.getHealingAmount() << endl;
//     }
// }



