#include <vector>
#include "../addit_header/GameMap.h"

using namespace std;

GameMap::GameMap() : height(0), width(0), numGoblin(0), goblinKilled(0) {
    mapMatrix.resize(0, vector<Object>(0));
}


void GameMap::killGoblin(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Invalid map coordinates");
    }

    Object& obj = mapMatrix[y][x];
    if (obj.getType() == "Goblin") {
        obj = Object();
        goblinKilled++;
    } else {
        std::cerr << "No goblin at the specified coordinates" << std::endl;
    }
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
        int count = 0;
    for (const auto& row : mapMatrix) {
        for (const auto& obj : row) {
            if (obj.getType() == "Goblin") {
                count++;
            }
        }
    }
    return count;
    }
GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h) : height(h), width(w), numGoblin(0), goblinKilled(0) {
    mapMatrix.resize(h, vector<Object>(w));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (initMatrix[y][x]) {
            case 1:
                mapMatrix[y][x] = Goblin("Goblin", 100, 10, "Fire");
                numGoblin++;
                break;
            case 2:
                mapMatrix[y][x] = Sword(10, "Basic Sword");
                break;
            case 3:
                mapMatrix[y][x] = Sword(15, "Greater Sword");
                break;
            case 4:
                mapMatrix[y][x] = Potion(5, "Small Potion");
                break;
            case 5:
                mapMatrix[y][x] = Potion(10, "Large Potion");
                break;
            default:
                mapMatrix[y][x] = Object();
                break;
            }
        }
    }
}  
