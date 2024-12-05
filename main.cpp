#include <iostream>
#include "Character_header/MainCharacter.h"
#include "Character_header/Goblin.h"
#include "addit_header/Swords.h"
#include "addit_header/Potions.h"
#include "addit_header/GameMap.h"
#include "addit_header/Level.h"

using namespace std;

int main() {
    bool isOver = false;

    // Example initialization of a GameMap
       MenuPrinter::printMainMenu();
        MenuPrinter::movementMenu();
    vector<vector<int>> initMatrix = {
        {0, 4, 6, 6, 6},
        {7, 4, 5, 6, 6},
        {4, 0, 8, 0, 0},
        {0, 0, 4, 10, 0},
        {0, 0, 0, 0, 0}
    };
    vector<vector<int>> initMatrix2 = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0}
    };

    vector<vector<int>> initMatrix3 = {
        {0, 1, 0, 5, 4, 0},  
        {1, 0, 2, 0, 6, 4},  
        {4, 0, 0, 0, 2, 3},  
        {0, 5, 3, 4, 0, 0},  
        {0, 4, 0, 0, 0, 5},
        {6, 4, 0, 4, 0, 4},
        {6, 4, 0, 4, 0, 4},
        {1, 0, 2, 4, 6, 1},  
        {4, 0, 4, 0, 2, 2},
        {1, 0, 2, 0, 6, 0},  
        {4, 0, 0, 0, 2, 3}
    };

    vector<vector<int>> initMatrix4 = {
        {0, 1, 0, 5, 4, 0},  
        {1, 0, 2, 0, 6, 4},  
        {4, 0, 0, 0, 2, 3},  
        {0, 5, 3, 4, 0, 0},  
        {0, 4, 0, 0, 0, 5},
        {6, 4, 0, 4, 0, 4},
        {6, 4, 0, 4, 0, 4},
        {1, 0, 2, 4, 6, 1},  
        {4, 0, 4, 0, 2, 2},
        {1, 0, 2, 0, 6, 0},  
        {4, 0, 0, 0, 2, 3},
        {1, 0, 2, 0, 6, 0},  
        {4, 0, 0, 0, 2, 3}
    };


    Level level(1, initMatrix, 2, isOver);
    Level level2(1, initMatrix2, 3, isOver);
    Level level3(1, initMatrix3, 4, isOver);
    Level level4(1, initMatrix4, 5, isOver);
    

    level.start();
    level2.start();
    level3.start();
    level4.start();


    // cout << "Use WASD to move, q to quit." << endl;


    return 0;
}