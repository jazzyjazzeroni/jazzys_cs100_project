#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"
using namespace std; 

class Dragon : public Character {
private:
    int breatheFire;
    int fireBall;

public:
    Dragon();
    Dragon(const string &name, double health, double attackStrength, const string &allegiance);
    int getfireAttack();
    int getfireBall();
    void setfireBall(int fireBall);
    void setfireAttack(int breatheFire);
    void attack(Character &opponent);
    
};

#endif