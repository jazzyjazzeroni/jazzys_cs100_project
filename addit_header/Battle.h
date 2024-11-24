#ifndef BATTLE_H
#define BATTLE_H

#include "../addit_header/GameMap.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/MenuPrinter.h"
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#include "../Character_header/Dragon.h"
#include <vector>

class Battle 
{
private:
    MainCharacter& mc;
    Dragon& dragon;

public: 
    Battle(MainCharacter& mc, Dragon& dragon)
        :mc(this->mc), dragon(this->dragon){}
    void startBattle();
    void declareWinner();
};
#endif 