#include <iostream>
#include "addit_header/GameMap.h"
#include "Character_header/MainCharacter.h"

using namespace std;


int main() {
    // Initialize game map with some sample data
    std::vector<std::vector<int>> mapData = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 6, 0},
        {0, 0, 0, 0}
    };

    GameMap gameMap(mapData, 4, 4); // 4x4 map

    // Initialize MainCharacter at position (0, 0)
    MainCharacter mainChar(0, 0);

    // Test movement: move right (to (1, 0))
    auto obj = mainChar.move('d', gameMap);
    std::cout << "Moved right: Object at new position type = " << obj->getType() << std::endl;

    // Move down (to (1, 1), where there is a Goblin)
    obj = mainChar.move('s', gameMap);
    std::cout << "Moved down: Object at new position type = " << obj->getType() << std::endl;

    return 0;
}
