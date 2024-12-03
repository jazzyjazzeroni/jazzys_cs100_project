#include "../Character_header/MainCharacter.h"
#include <iostream>

using namespace std;

// Constructor
MainCharacter::MainCharacter(const std::string &name, int health, int damage, const std::string &element)
    : Character(MAINCHAR, name, health, damage, element), powers(element), currentElement(powers.getPower()) {
        // inventory = std::make_shared<Inventory>();;
    }
MainCharacter::MainCharacter(int x, int y) : x(x), y(y) {
    // inventory = make_shared<Inventory>(); // Initialize inventory
}

// void MainCharacter::attack(Character &opponent) {
//     cout << name << " attacks " << opponent.getType() << " with a sword, dealing " << attackAmount << " damage!" << endl;
//     opponent.receiveDamage(attackAmount);

//     if (!opponent.isalive()) {
//         std::cout << "The opponent has been defeated!" << std::endl;
//     }
// } might fix

void MainCharacter::heal(int amount) {
    health = min(health + amount, MAX_HEALTH); // Prevent exceeding MAX_HEALTH
    cout << name << " heals for " << amount << " health points. Current health: " << health << endl;
}

// void MainCharacter::usePowers() {
//     cout << name << " uses a special power!" << endl;
//     powers.usePower(powers.getPower(), allegiance); // Assuming `activate()` is a method in `Powers`
// }




// Add sword function (pick up a sword)
    void MainCharacter::equipSword(const Sword & newSword) {
        //todo give o[ption to swap or replace sword]
            // Swap or replace the sword
            this->sword = Sword(newSword.getValue(), "New Sword");
            // inventory->addSword(newSword);
            sword = newSword; // Equip the sword
    // inventory->addSword(newSword); // Add to inventory
    // cout << "Equipped sword: " << newSword.getName() << endl;
    }
    // Equips a sword

    int MainCharacter::mod(int value, int limit) {
        return (value % limit + limit) % limit;  // Handle negative values properly
    }

   pair<int, int>  MainCharacter::move(char action,int height, int width) {
    int newX = x, newY = y;
    

    if (action == 'w') { // Move up
        newY = mod(y - 1, height);
    } else if (action == 's') { // Move down
        newY = mod(y + 1, height);
    } else if (action == 'a') { // Move left
        newX = mod(x - 1, width);
    } else if (action == 'd') { // Move right
        newX = mod(x + 1, width);
    }

    setPosition(newX, newY);

    return {newX, newY}; // Ensure return type matches shared_ptr<Object>
    // return gameMap.getObjectAt(newX, newY); // Ensure return type matches shared_ptr<Object>
}

    void MainCharacter::setPosition(int newX, int newY) {
        cout << "the player is moved to " << newX << " " << newY << endl;
        x = newX;
    y = newY;
        // this->x = x;
        // this->y = y;
    }


    pair<int, int> MainCharacter::getPosition() const {
        return {x, y};
    }

void MainCharacter::attack(Character &target) {
    if (target.getType() == "Goblin") { 
        Powers opponentPower = target.getPower();
        string enemyAllegiance = opponentPower.getcurrentElement() ;
        // cout << name << " attacks the Goblin fiercely with a sword, dealing " 
        //      << attackAmount << " damage!" << endl;
        if (powers.canUsePower(opponentPower)) {
            int powerDamage = powers.calculateDamage(); // Update power damage
            cout << "Elemental Power used against " << enemyAllegiance << "!" << endl;
            cout << "Dealt " << powerDamage << " damage!" << endl;
            target.receiveDamage(attackAmount+sword.getPower()+powerDamage);
        } else if (powers.getPower() == opponentPower.getPower()) {
            cout << "Warning: Using the same element against " << enemyAllegiance 
                << " results in self-damage!" << endl;
            cout << "Dealt no damage!" << endl;
        } else {
            cout << "This Elemental Power is ineffective against " << enemyAllegiance << "!" << endl;
            cout << "Dealt no damage!" << endl;
            target.attack(*this);
            // todo take damage from goblin
        }
    } 

    if (!target.isalive()) {
        cout << "The opponent has been defeated!" << endl;
    }
}

    // void MainCharacter::heal(int amount) {
    //     setHealth(getHealth() + amount); // Assuming you have a setHealth method in Character
    // }
    void MainCharacter::print() const {
        cout << "Main Character: " << name << ", Health: " << health << ", Attack: " << attackAmount << endl;
    }
    // todo Check if the character is alive
    // bool MainCharacter::isalive() const {
    //     return (getHealth() > 0);
    // };


    // todo Update the element based on the current level