#include "GameMap.h"
#include "../Character_header/MainCharacter.h"
#include "Inventory.h"
#include "MenuPrinter.h"
#include <vector>
#ifndef LEVEL_H
#define LEVEL_H
using namespace std;

class Level {
private:
    GameMap gameMap;
    MainCharacter player;
    Inventory inventory;
    int goblinGoal;
    bool end;

public:
    Level(int power, const vector<vector<int>>& mapLayout, int numGoblins);
    Level::Finalbosslevel(int power);
    void start();
    void takeAction();
};

#endif