#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
#include "Powers.h"
#include "Inventory.h"
#include "Interface.h"
#include "GameMap.h"
#include "Sword.h"
using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    Powers powers;
    Inventory inventory;
    Sword sword;
    char move;

public:
    MainCharacter(const string &name, double health, double attackStrength, const string &allegiance);

    void attack(Character &opponent) override;
    void WitchInteraction();
    void heal(int);
    char getMovement();
    void usePowers();
    const Inventory& getInventory() const;
    void usePotion();
    void equipSword();

};

#endif