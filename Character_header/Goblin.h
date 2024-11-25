#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
using namespace std; 

class Goblin : public Character {
private:
    int specialPower;

public:
    Goblin(const string &name, int health, int attackStrength, int specialPower, const string &allegiance);

    void attack(Character &opponent) override;
    void SpecialAttack(int);
};

#endif