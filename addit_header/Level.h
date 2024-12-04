<<<<<<< HEAD
// #ifndef LEVEL_H
// #define LEVEL_H
// using namespace std;
// #include "GameMap.h"
// // #include "../Character_header/MainCharacter.h"
// #include "../Character_header/Character.h"
// #include "../Character_header/Goblin.h"
// // #include "../Character_header/Dragon.h"
// #include "Object.h"
// #include "Inventory.h"
// // #include "MenuPrinter.h"
// // #include "GameManager.h"
// #include "Powers.h"
// #include <vector>
// #include <map>


// class Level {
// private:
//     GameMap gameMap;
//     std::map<int, Power_type> levelElements; // Map level number to element type
//     // MainCharacter player;
//     Inventory inventory;
//     // Dragon dragon;
//     int goblinGoal;
//     int levelNumber;
//     bool end;
//     int currentLevel;

// public:
//     Level();
//     Level(int power, const vector<vector<int>>& mapLayout, int numGoblins);

//     void Level::Finalbosslevel(int power);
//     vector<Level> initializeLevels();
//     void start();
//     void takeAction();
//     GameMap getGameMap() const{ return gameMap; }
//     Power_type getElementForLevel(int level) const; // Get element for a specific level
//     void setLevel(int level); // Set the current level
//     int getCurrentLevel() const;
// };
// #endif
=======
#ifndef LEVEL_H
#define LEVEL_H
using namespace std;
#include "Inventory.h"
#include "GameMap.h"
#include "MenuPrinter.h"
#include "GameManager.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>


class Level {
private:
    bool *isOver;
    GameMap gameMap;
    std::map<int, Power_type> levelElements{}; // Map level number to element type
    MainCharacter player;
    Inventory inventory;
    // Dragon dragon;
    int goblinGoal{};
    int levelNumber{};
    bool end{};
    int currentLevel{};

public:
    Level();
    Level(int power, const vector<vector<int>>& mapLayout, int numGoblins, bool &isOver);
    ~Level(){
        cout << "Level destructor called" << endl;
    };
    vector<Level> initializeLevels();
    void start();
    void takeAction();
    GameMap getGameMap() const{ return gameMap; }
    Power_type getElementForLevel(int level) const; // Get element for a specific level
    void setLevel(int level); // Set the current level
    int getCurrentLevel() const;
};
#endif
>>>>>>> master
