#include "../Character_header/MainCharacter.h"
#include <iostream>

using namespace std;

// Constructor
MainCharacter::MainCharacter(const std::string &name, int health, int damage, const std::string &element)
    : Character(MAINCHAR, name, health, damage, element), powers(element), currentElement(powers.getPower()) {
      x = 0; y = 0; 
    }
MainCharacter::MainCharacter(int x, int y) : x(x), y(y) {
}


void MainCharacter::heal(int amount) {
    health = min(health + amount, MAX_HEALTH); 
    cout << "Theodore" << " heals for " << amount << " health points. Current health: " << health << endl;
}


    void MainCharacter::equipSword(const Sword & newSword) {
            cout << "Do you want to equip and/or swap exisiting sword? (y/n): ";
            char choice;
            cin >> choice;

            if (choice == 'y') {
                this->sword = Sword(newSword.getValue(), "New Sword"); // Replace the sword
                cout << "New sword: " << newSword.getName() << endl;

            } else if (choice == 'n') {
                cout << " Sword remains unchanged." << endl;
            } else {
                cout << "Invalid choice. Sword remains unchanged." << endl;
            }
    }

    
 

    int MainCharacter::mod(int value, int limit) {
        return (value % limit + limit) % limit;  
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

    return {newX, newY}; 
}

    void MainCharacter::setPosition(int newX, int newY) {
        cout << "the player is moved to " << newX << " " << newY << endl;
        x = newX;
    y = newY;

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
            cout << "Elemental Power used against " << enemyAllegiance << "!" << endl << endl; //to do change to actula power
            cout << "You dealt " << powerDamage << " damage!" << endl;
            target.receiveDamage(attackAmount+sword.getPower()+powerDamage);
        } else if (powers.getPower() == opponentPower.getPower()) {
            cout << "Warning: Using the same element against " << enemyAllegiance 
                << " results in self-damage!" << endl << endl;
            cout << "Dealt no damage!" << endl << endl;
        } else {
            cout << "This Elemental Power is ineffective against " << enemyAllegiance << "!" << endl << endl;
            cout << "Dealt no damage!" << endl << endl;
            target.attack(*this);
            // todo take damage from goblin
        }
        
    } 

    if (!target.isalive()) {
        cout << "The opponent has been defeated!" << endl;
    }
}

    void MainCharacter::print() const {
        cout << "Main Character: " << name << ", Health: " << health << ", Attack: " << attackAmount << endl;
    }
