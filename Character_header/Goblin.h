#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
using namespace std; 

class Goblin : public Character {
private:
    int specialPower;
    string type; // "character" | "sword" | "potion" | "empty"
    int value; // 0 | 5 | 10 | 15
    

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