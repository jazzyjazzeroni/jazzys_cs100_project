#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
#include "../addit_header/Powers.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Level.h"
#include "../addit_header/Swords.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Object.h"
#include <string>
#include <utility>

using namespace std; 

class Goblin : public Character {
private:
    int specialPower;

public:
    Goblin(const string &name, int health, int attackStrength, int specialPower, const string &allegiance);
    Goblin(int);
    Goblin();
    int getHealth() const ;
    CharType getType() ;
    void setHealth(int) ;
    bool isalive() const ;
    void dealtDamage(int) ;
    void recieveDamage(int) ;
    void attack(Character &player) override;
    
};

#endif