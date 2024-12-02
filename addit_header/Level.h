#ifndef LEVEL_H
#define LEVEL_H
using namespace std;
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#include "../Character_header/Goblin.h"
// #include "../Character_header/Dragon.h"
#include "GameMap.h"
#include "Object.h"
#include "Inventory.h"
#include "Powers.h"
// #include "MenuPrinter.h"
// #include "GameManager.h"
#include <vector>
#include <map>


class Level {
private:
    GameMap gameMap;
    std::map<int, Power_type> levelElements; // Map level number to element type
    MainCharacter player;
    Inventory inventory;
    // Dragon dragon;
    int goblinGoal;
    int levelNumber;
    bool end;
    int currentLevel;

public:
    Level();
    Level(int power, const vector<vector<int>>& mapLayout, int numGoblins);

    // void Level::Finalbosslevel(int power);
    vector<Level> initializeLevels();
    void start();
    void takeAction();
    GameMap getGameMap() const{ return gameMap; }
    Power_type getElementForLevel(int level) const; // Get element for a specific level
    void setLevel(int level); // Set the current level
    int getCurrentLevel() const;
};
#endif