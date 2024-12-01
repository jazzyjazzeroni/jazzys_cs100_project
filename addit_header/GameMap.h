#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "Swords.h"
#include "Goblin.h"
#include "Potions.h"
#include "../Character_header/Character.h"

using namespace std;

class GameMap {
private:
    int height;
    int width;
    int numGoblin;
    int goblinKilled;
    vector<vector<Sword>> SwdmapMatrix;
    vector<vector<Potion>> PowmapMatrix;
    vector<vector<Goblin>> GobmapMatrix;


public:
    GameMap();
    GameMap(const vector<vector<int>>& initMatrix, int w, int h);
    void killGoblin(int x, int y);
    Sword& getSwordAt(int x, int y);
    Potion& getPotionAt(int x, int y);
    Goblin& getGoblinAt(int x, int y);
    void setSwordAt(int x, int y, const Sword& Swd_obj);
    void setPotionAt(int x, int y, const Potion& Pow_obj);
    void setGoblint(int x, int y, const Goblin& Gob_obj);
    int getNumGoblins() const;
    int getGoblinsKilled() const;
    int getWidth() const;
    int getHeight() const;
    
};

#endif