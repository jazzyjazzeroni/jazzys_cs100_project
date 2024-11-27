#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include "Level.h"
#include "MenuPrinter.h"
#include "../addit_header/GameMap.h"
#include "../Character_header/MainCharacter.h"
#include "../addit_header/Inventory.h"

class GameManager: public MenuPrinter {
private:
    int currLevel;
    vector<Level> levels;

public:
    GameManager();
    ~GameManager();
    void gameStart();
    void pause();
    void quit();
};

#endif