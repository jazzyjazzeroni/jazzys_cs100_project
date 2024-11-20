#include <vector>
#include "Level.h"
#include "MenuPrinter.h"
#include "GameMap.h"
#include "../Character_header/MainCharacter.h"
#include "Inventory.h"

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

using namespace std;

class GameManager {
private:
    int currLevel;
    vector<Level> levels;

public:
    GameManager();
    void gameStart();
};

#endif