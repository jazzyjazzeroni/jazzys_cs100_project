#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <memory> // For smart pointers
#include "Swords.h"
#include "Potions.h"
#include "../Character_header/Goblin.h"
#include "../Character_header/Character.h"
#include "../Character_header/MainCharacter.h"
using namespace std;

class GameMap {
private:
    int height{};
    int width{};
    int numGoblin{};
    int goblinKilled{};
    vector<vector<shared_ptr<Object>>> mapMatrix;  // Use smart pointers to handle objects

public:
    GameMap();
    GameMap(const vector<vector<int>>& initMatrix, int w, int h);
    // ~GameMap() 
    // {
    //     for (int i = 0; i < height; i++) {
       
    //         for(int j = 0; j < width; j++) {
    //          mapMatrix[i][j].reset();
    //         }
    //         mapMatrix[i].clear();
    //     }
    //     mapMatrix.clear();
    // };

~GameMap() =default;
    void killGoblin(int x, int y);
    shared_ptr<Object> getObjectAt(int x, int y);
    void setObjectAt(int x, int y, const shared_ptr<Object>& obj);

    int getNumGoblins() const;
    int getGoblinsKilled() const;
    int getWidth() const;
    int getHeight() const;
};

#endif
