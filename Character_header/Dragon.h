#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"
using namespace std; 

class Dragon : public Character {
private:
    int breathe_fire;
    int fire_ball;

public:
    Dragon();
    Dragon(const string &name, int health, int attackStrength);
    int getfireAttack();
    int getfireBall();
    void setfireBall(int pFireBall);
    void setfireAttack(int pBreatheFire);
    void attack(Character &opponent);
    
};

#endif