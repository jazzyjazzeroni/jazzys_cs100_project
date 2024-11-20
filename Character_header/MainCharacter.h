#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
#include "../addit_header/Powers.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Swords.h"
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

    virtual void attack(Character &opponent) override;
    virtual void WitchInteraction();
    virtual void heal(int);
    virtual char getMovement();
    virtual void usePowers();
    virtual const Inventory& getInventory() const;
    virtual void usePotion();
    virtual void equipSword();
    // string getAllegiance() const;   
    // void setAllegiance(const string &newAllegiance);
};

#endif