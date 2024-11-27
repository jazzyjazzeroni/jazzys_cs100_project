#include "GameMap.h"
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#include "Object.h"
#include "Inventory.h"
#include "MenuPrinter.h"
#include "GameManager.h"
#include "Powers.h"
#include <vector>
#include <map>
#ifndef LEVEL_H
#define LEVEL_H
using namespace std;

class Level {
private:
    GameMap gameMap;
    std::map<int, Power_type> levelElements; // Map level number to element type
    MainCharacter player;
    Inventory inventory;
    int goblinGoal;
    int levelNumber;
    bool end;

public:
    Level(int power, const vector<vector<int>>& mapLayout, int numGoblins);
    void Level::Finalbosslevel(int power);
    static vector<Level> initializeLevels();
    void start();
    void takeAction();
    GameMap getGameMap() const{ return gameMap; }
    Power_type getElementForLevel(int level) const; // Get element for a specific level
    void setLevel(int level); // Set the current level
    int getCurrentLevel() const;
};

#endif