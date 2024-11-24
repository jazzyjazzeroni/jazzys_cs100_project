#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include "Level.h"
#include "MenuPrinter.h"
#include "GameMap.h"
#include "../Character_header/MainCharacter.h"
#include "Inventory.h"

class GameManager: public MenuPrinter {
private:
    int currLevel;
    vector<Level> levels;

public:
    GameManager();
    ~GameManager();
    void gameStart();
    void pause();
};

#endif