#ifndef DRAGON_H
#define DRAGON_H

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
