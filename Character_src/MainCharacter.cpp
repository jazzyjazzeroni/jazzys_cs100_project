
#include "Character.h"
#include "../addit_header/Powers.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Swords.h"
using namespace std; 


// private:
//     string allegiance;
//     Powers powers;
//     Inventory inventory;
//     Sword sword;
//     char move;

// public:
//      MainCharacter(const string &name, double health, double attackStrength, const string &allegiance);

//     virtual void attack(Character &opponent) override;
//     virtual void WitchInteraction();
//     virtual void heal(int);
//     virtual char getMovement();
//     virtual void usePowers();
//     virtual const Inventory& getInventory() const;
//     virtual void usePotion();
//     virtual void equipSword();
    // string getAllegiance() const;   
    // void setAllegiance(const string &newAllegiance);

MainCharacter::MainCharacter(const string &name, double health, double attackStrength, const string &allegiance) 
    : Character(MAINCHAR, name, health, attackStrength), allegiance(allegiance) {
    this->inventory = Inventory();
    this->powers = Powers();
    this->sword = Sword();
}

void MainCharacter::attack(Character &opponent) {
    opponent.takeDamage(attackStrength);
}

void MainCharacter::WitchInteraction() {
    powers.usePowers();
}

void MainCharacter::heal(int amount) {
    health += amount;
}

char MainCharacter::getMovement() {
    return move;
}

void MainCharacter::usePowers() {
    powers.usePowers();
}

const Inventory& MainCharacter::getInventory() const {
    return inventory;
}

void MainCharacter::usePotion() {
    inventory.usePotion();
}

void MainCharacter::equipSword() {
    inventory.equipSword();
}



