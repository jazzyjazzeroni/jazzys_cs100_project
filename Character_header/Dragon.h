#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"
using namespace std; 

class Dragon : public Character {
private:
    string allegiance;
    int breatheFire;
    int fireBall;
    // Powers specialpowers;

public:
    Dragon(const string &name, double health, double attackStrength, const string &allegiance);
    void fly(string);
    int getfireAttack();
    int getfireBall();
    void setfireBall();
    void setfireAttack();
    void attack(Character &opponent) override;
    
};

#endif