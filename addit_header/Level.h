#ifndef LEVEL_H
#define LEVEL_H
using namespace std;
#include "Inventory.h"
#include "GameMap.h"
#include "MenuPrinter.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>


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