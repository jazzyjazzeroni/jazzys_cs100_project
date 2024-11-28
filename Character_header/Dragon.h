#ifndef DRAGON_H
#define DRAGON_H

#include "../addit_header/GameMap.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/MenuPrinter.h"
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#include "../Character_header/Dragon.h"
#include <vector>

class Dragon : public Character {
private:
    int breathe_fire;
    int fire_ball;
    MainCharacter& mc;

public:
    // Dragon();
    ~Dragon();
    Dragon(MainCharacter& mc, const string &name, int pHealth, int pBreatheFire, int pFireBall);    
    int getfireAttack();
    int getfireBall();
    void setfireBall(int pFireBall);
    void setfireAttack(int pBreatheFire);
    void attack(Character &opponent);
    void startBattle();
    void declareWinner();
    
};

#endif