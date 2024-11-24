#include "GameMap.h"
#include "../Character_header/MainCharacter.h"
#include "Inventory.h"
#include "MenuPrinter.h"
#include "GameManager.h"
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
    int levelNumber;
    bool end;

public:
    Level(int power, const vector<vector<int>>& mapLayout, int numGoblins);
    Level::Finalbosslevel(int power);
    static vector<Level> initializeLevels();
    void start();
    void takeAction();
};

#endif