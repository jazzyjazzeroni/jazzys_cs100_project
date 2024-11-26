#include "../Character_header/MainCharacter.h"
#include <iostream>

using namespace std;

// Constructor
MainCharacter::MainCharacter(const string &name, int health, int attackStrength, const string &allegiance)
    : allegiance(allegiance) {
    this->name = name;
    this->health = health;
    this->attackAmount = attackStrength;
    this->type = MAINCHAR; // Assuming `MAIN_CHARACTER` is a valid CharType
}

// Attacks the opponent
void MainCharacter::attack(Character &opponent) {
    cout << name << " attacks " << opponent.getName() << " with a sword, dealing " << attackAmount << " damage!" << endl;
    opponent.takeDamage(attackAmount);
}

// Interaction with the Witch
void MainCharacter::WitchInteraction() {
    cout << "You meet the witch in the forest." << endl;
    cout << "She offers to enhance your powers or health. What will you choose? (1 = Powers, 2 = Health): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        powers.useFusedPower();
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
    health += amount;
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

// Gets the character's inventory
const Inventory& MainCharacter::getInventory() const {
    return inventory;
}

// Uses a potion from the inventory
void MainCharacter::usePotion() {
    if (inventory.hasPotion()) {
        cout << name << " uses a potion!" << endl;
        inventory.usePotion(); // Assuming `usePotion()` removes a potion from the inventory
        heal(50); // Example: restores 50 health
    } else {
        cout << "No potions available!" << endl;
    }
}

// Equips a sword
void MainCharacter::equipSword() {
    cout << name << " equips a new sword!" << endl;
    sword = inventory.getBestSword(); // Assuming `getBestSword()` is a method in `Inventory`
    attackAmount = sword.getAttackStrength(); // Update attack strength
}

