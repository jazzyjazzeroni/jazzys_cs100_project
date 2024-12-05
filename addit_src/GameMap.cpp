#include "../addit_header/GameMap.h"
#define YELLOW "\033[33m"      // Yellow
#define PINK "\033[35m"     // Pink~
#define RESET "\033[0m"        // Reset color
using namespace std;

GameMap::GameMap() : height(0), width(0), numGoblin(0), goblinKilled(0) {
    mapMatrix.resize(0, vector<shared_ptr<Object>>(0));
}

GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h) : height(h), width(w), numGoblin(0), goblinKilled(0) {
    mapMatrix.resize(h, vector<shared_ptr<Object>>(w));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (initMatrix[y][x]) {
            case 1:
                mapMatrix[y][x] = make_shared<Goblin>("Goblin", 100, 15, "Fire");
                numGoblin++;
                break;
            case 2:
                mapMatrix[y][x] = make_shared<Goblin>("Goblin", 75, 10, "Water");
                numGoblin++;
                break;
            case 4:
                mapMatrix[y][x] = make_shared<Goblin>("Goblin", 70, 7, "Air");
                numGoblin++;
                break;
            case 5:
                mapMatrix[y][x] = make_shared<Goblin>("Goblin", 65, 5, "Earth");
                numGoblin++;
                break;
            case 6:
                mapMatrix[y][x] = make_shared<Sword>(10, "Basic Sword");
                break;
            case 7:
                mapMatrix[y][x] = make_shared<Sword>(15, "Greater Sword");
                break;
            case 8:
                mapMatrix[y][x] = make_shared<Potion>(5, "Small Potion");
                break;
            case 9:
                mapMatrix[y][x] = make_shared<Potion>(10, "Large Potion");
                break;
            default:
                mapMatrix[y][x] = make_shared<Object>();  // Empty object
                break;
            }
        }
    }
}

void GameMap::killGoblin(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }

    shared_ptr<Object>& obj = mapMatrix[y][x];
    if (obj->getType() == "Goblin") {
        obj = make_shared<Object>();  // Replace with an empty object
        goblinKilled++;
    } else {
        cerr << "No goblin at the specified coordinates" << endl;
    }
}

shared_ptr<Object> GameMap::getObjectAt(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    return mapMatrix[y][x];
}

void GameMap::setObjectAt(int x, int y, const shared_ptr<Object>& obj) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    mapMatrix[y][x] = obj;
}

int GameMap::getNumGoblins() const {
    return numGoblin;
}

int GameMap::getGoblinsKilled() const {
    int count = 0;
    for (const auto& row : mapMatrix) {
        for (const auto& obj : row) {
            if (obj->getType() == "Goblin") {
                count++;
            }
        }
    }
    return count;
}

int GameMap::getWidth() const {
    return width;
}

int GameMap::getHeight() const {
    return height;
}

void GameMap::printMap(int playerX, int playerY) const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == playerX && y == playerY) {
                cout << PINK << "(^o^) " << RESET;  // Represent the player with 'P'
            } else {
                auto obj = mapMatrix[y][x];
                if (obj->getType() == "Goblin"||obj->getType() == "Sword"||obj->getType() == "Potion") {
                    cout << YELLOW << "*" << RESET;
                } else {
                    cout << ". ";  // Represent empty spaces with '.'
                }
            }
            cout << "\t";
        }
        cout << endl;
    }
}

