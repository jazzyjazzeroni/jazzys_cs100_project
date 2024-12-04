#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <memory> // For smart pointers
<<<<<<< HEAD
#include "Object.h"
#include "Swords.h"
#include "../Character_header/Goblin.h"
=======
#include "Swords.h"
>>>>>>> master
#include "Potions.h"
#include "../Character_header/Goblin.h"
#include "../Character_header/Character.h"
<<<<<<< HEAD
=======
#include "../Character_header/MainCharacter.h"
>>>>>>> master
using namespace std;

class GameMap {
private:
<<<<<<< HEAD
    int height;
    int width;
    int numGoblin;
    int goblinKilled;
=======
    int height{};
    int width{};
    int numGoblin{};
    int goblinKilled{};
>>>>>>> master
    vector<vector<shared_ptr<Object>>> mapMatrix;  // Use smart pointers to handle objects

public:
    GameMap();
    GameMap(const vector<vector<int>>& initMatrix, int w, int h);
<<<<<<< HEAD
    ~GameMap() = default;
=======
    ~GameMap() 
    {
        for (auto& row : mapMatrix) {
        for (auto& obj : row) {
            obj.reset(); // Reset each shared_ptr to release memory
        }
        row.clear(); // Clear each row vector
    }
    mapMatrix.clear();
    };
>>>>>>> master

    void killGoblin(int x, int y);
    shared_ptr<Object> getObjectAt(int x, int y);
    void setObjectAt(int x, int y, const shared_ptr<Object>& obj);

    int getNumGoblins() const;
    int getGoblinsKilled() const;
    int getWidth() const;
    int getHeight() const;
};

#endif
