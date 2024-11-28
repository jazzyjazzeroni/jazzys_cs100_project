#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"

class Dragon : public Character {
private:
    int breathe_fire;
    int fire_ball;

public:
<<<<<<< HEAD
    Dragon();
    ~Dragon();
    Dragon(const string &name, int pHealth, int pBreatheFire, int pFireBall);
=======
    Dragon(const string &name, double health, double attackStrength, const string &allegiance);
>>>>>>> csong073/game_manager_feature
    int getfireAttack();
    int getfireBall();
    void setfireBall(int pFireBall);
    void setfireAttack(int pBreatheFire);
    void attack(Character &opponent);
    
};

#endif