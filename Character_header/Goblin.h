#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
using namespace std; 

class Goblin : public Character {
private:
    int specialPower;

public:
    Goblin(const string &name, int health, int attackStrength, int specialPower, const string &allegiance);

    int getHealth() const override;
    CharType getType() override;
    void setHealth(int) override;
    bool isalive() const override;
    void dealtDamage(int) override;
    void recieveDamage(int) override;
    void attack(Character &player) override;
    
    void SpecialAttack(int);
};

#endif