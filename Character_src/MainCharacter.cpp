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
  

MainCharacter::MainCharacter(int x, int y) : x(x), y(y) {}  // Ensure this initializes member variables x and y

    // Modulo function to wrap around the coordinates
    int MainCharacter::mod(int value, int limit) {
        return (value % limit + limit) % limit;  // Handle negative values properly
    }

    // Movement function that uses modulo to ensure the character stays on the map
    Object move(char action, GameMap &gameMap) {
        // int x = x, y = y;

        if (action == 'w') { // Move up
            y = mod(y - 1, gameMap.getHeight()); // Wrap around vertically
        } else if (action == 's') { // Move down
            y = mod(y + 1, gameMap.getHeight()); // Wrap around vertically
        } else if (action == 'a') { // Move left
            x = mod(x - 1, gameMap.getWidth()); // Wrap around horizontally
        } else if (action == 'd') { // Move right
            x = mod(x + 1, gameMap.getWidth()); // Wrap around horizontally
        }

        // Update the player's position
        // x = newX;
        // y = newY;

        // Return the object at the new position
        return gameMap.getObjectAt(x, y);
    }

    // Get position of the character
    pair<int, int> getPosition() const {
        return {x, y};
    }

    // Attack function
    void attack(GameMap &gameMap, int targetX, int targetY) {
        Object &target = gameMap.getObjectAt(targetX, targetY);
        
        if (target.getType() == "goblin") {
            // Assuming you have a method for attack calculation here
            Goblin &goblin = dynamic_cast<Goblin&>(target);
            // Do the attack logic here
        }
    }

    // Add sword function (pick up a sword)
    void addSword(GameMap &gameMap, int swordX, int swordY) {
        Object &newSword = gameMap.getObjectAt(swordX, swordY);
        if (newSword.getType() == "sword") {
            // Swap or replace the sword
            sword = Sword(newSword.getValue(), "New Sword");
        }
    }

    // Heal the character using a potion
    void heal(int amount) {
        setHealth(getHealth() + amount); // Assuming you have a setHealth method in Character
    }

    // Check if the character is alive
    bool isAlive() const {
        return getHealth() > 0;
    };



