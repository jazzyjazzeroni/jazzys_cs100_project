#include <vector>
#include "GameMap.h"

using namespace std;

GameMap(vector<vector<int>> initMatrix, w, h)
    {
        mapMatrix
        for y in range h:
            for x in range w;
                if(initMatrix[y][x] == 0)
                {
                    mapMatrix[y][x] = Object()
                }
                if(initMatrix[y][x] == 1)
                {
                    mapMatrix[y][x] = Sword(10, "small sword")
                }
                if(initMatrix[y][x] == 2)
                {  mapMatrix[y][x] = Sword(15, "bigger sword")
               
                }
                if(initMatrix[y][x] == 3)
                {
                    mapMatrix[y][x] = Goblin()
                    numGoblin ++
                }
            
              
    }
    void init();
    void killgoblin(x,y)
    {
        set goblin[y]x] = Object
        goblinkilledp ++
    }