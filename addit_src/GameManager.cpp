#include "../addit_header/GameManager.h"

//    Level(int power, const vector<vector<int>>& mapLayout, int numGoblins);

GameManager::GameManager() : currLevel(0)
{
    vector<vector<int>> map_level_1 = {
        {0,1,4,0,0},
        {5,0,4,0,6},
        {0,0,4,1,0},
        {0,0,0,0,0},
    };
    levels.emplace_back(Level(3, map_level_1,3));

    vector<vector<int>> map_level_2 = {
        {2,0,4,0,0},
        {5,0,4,0,6},
        {5,4,0,1,0},
        {0,4,0,4,0},
    };
    levels.emplace_back(Level(2, map_level_2,5)); // 5 goblins

    vector<vector<int>> map_level_3 = {
        {4,0,4,0,4},
        {5,0,4,4,6},
        {0,0,4,2,0},
        {0,4,0,4,0},
    };
    levels.emplace_back(Level(3, map_level_3,7)); // 7 goblins

    vector<vector<int>> map_level_4 = {
        {3,0,4,0,4},
        {5,0,4,4,6},
        {4,6,4,4,0},
        {0,4,0,4,4},
    };
    levels.emplace_back(Level(0, map_level_4,10)); // 10 goblins

}

GameManager::~GameManager(){};

void GameManager::gameStart()
{
    // Incorporate wasd controls 
    std::cout << "FLAMES OF ICE\n";
     
}