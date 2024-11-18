#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
#include "Powers.h"
#include "Inventory.h"
#include "Interface.h"
using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    Powers powers;
    Inventory inventory;
    char move;

public:
    MainCharacter(const string &name, double health, double attackStrength, const string &allegiance);

    void attack(Character &opponent) override;
    void WitchInteraction();
    void heal(int);
    char getMovement();
    void setMovement(char);
    void usePowers();
    const Inventory& getInventory() const;
    void usePotion();
    void useMushroom();
    void equipSword();

};

#endif