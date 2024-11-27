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

    //Initializes the starting room, player, and levels
    void gameStart();

    // Gets user input (hit w, hit a, hit s, hit d, "take sword", "take potion", "fight goblin")
    // This function parses the input and determines the approporiate action
    void handleInput();

    // nextLevel()
    // update()
    //updates inventory
    // will trigger the event with goblin
    // 
    void updateLevel();

    // will start the level against the final boss
    void finalBoss();
    void pause();
    void quit();
};

#endif