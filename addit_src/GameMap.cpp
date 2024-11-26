#include <vector>
#include "GameMap.h"
#include "Object.h"
#include "../Character_header/Character.h"

using namespace std;

    void GameMap::killGoblin(int x, int y){
        mapMatrix[y][x] = Object();
        goblinKilled++;
    }
    int GameMap::getWidth() const { return width; }
    int GameMap::getHeight() const { return height; }
    Object& GameMap::getObjectAt(int x, int y){
        if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Invalid map coordinates");
        }
        return mapMatrix[y][x];
    }
    void GameMap::setObjectAt(int x, int y, const Object& obj){
        if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Invalid map coordinates");
        }
        mapMatrix[y][x] = obj;
    }

    int GameMap::getNumGoblins() const{
        return numGoblin;
    }
    int GameMap::getGoblinsKilled() const{
        return goblinKilled;
    }

GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h) : width(w), height(h), numGoblin(0) {
        mapMatrix.resize(h, vector<Object>(w));
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if(initMatrix[y][x] == 0)
                {
                    mapMatrix[y][x] = Object();
                }
                if(initMatrix[y][x] == 1)
                {
                    mapMatrix[y][x] = Sword(5, "Normal Sword");
                }
                if(initMatrix[y][x] == 2)
                {  mapMatrix[y][x] = Sword(10, "Better Sword");
               
                }
                if(initMatrix[y][x] == 3)
                {  mapMatrix[y][x] = Sword(15, "Greater Sword");
               
                }
                if(initMatrix[y][x] == 4)
                {
                    mapMatrix[y][x] = Goblin();
                    numGoblin++;
                }
                if(initMatrix[y][x] == 5)
                {  mapMatrix[y][x] =   Potion(5, "Small Potion");
    
                }
                if(initMatrix[y][x] == 6)
                {  mapMatrix[y][x] = Potion(10, "Large Potion");
    
                }
            }
        }
    }
    