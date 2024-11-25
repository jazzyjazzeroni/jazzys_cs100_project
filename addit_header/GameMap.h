#include <vector>
#include "Object.h"
#include "Swords.h"
#include "Potions.h"
#include "../Character_header/Goblin.h"
#ifndef GAMEMAP_H
#define GAMEMAP_H
using namespace std;

class GameMap {
private:
    int height;
    int width;
    int numGoblin;
    int goblinKilled;
    vector<vector<Object>> mapMatrix;

public:
    GameMap(const vector<vector<int>>& initMatrix, int w, int h);
    // void init(const vector<vector<int>>& layout);
 void init();
    void killGoblin(int x, int y);
    Object& getObjectAt(int x, int y);
    void setObjectAt(int x, int y, const Object& obj);
    int getNumGoblins() const;
    int getGoblinsKilled() const;
};

#endif