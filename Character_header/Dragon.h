#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"

class Dragon : public Character {
private:
    int breathe_fire;
    int fire_ball;

public:
    Dragon();
    ~Dragon();
    Dragon(const string &name, int pHealth, int pBreatheFire, int pFireBall);
    int getfireAttack();
    int getfireBall();
    void setfireBall(int pFireBall);
    void setfireAttack(int pBreatheFire);
    void attack(Character &opponent);
    
};

#endif