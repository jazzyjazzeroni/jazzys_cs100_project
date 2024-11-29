#include <iostream>
#include <vector>
#include "addit_header/GameMap.h"
#include "addit_header/Object.h"
#include "addit_header/Swords.h"
#include "addit_header/Potions.h"
#include "Character_header/Goblin.h"

using namespace std;

int main() {
    // Define a map with various objects using integers
    // 0: Empty, 1-3: Swords, 4: Goblin, 5-6: Potions
    vector<vector<int>> initMatrix = {
        {0, 1, 0, 4, 0},
        {2, 0, 3, 0, 5},
        {0, 4, 0, 6, 0},
        {0, 0, 0, 4, 0}
    };

    // Initialize the GameMap with the matrix dimensions
    GameMap gameMap(initMatrix, 5, 4);

    // Display the initial map state
    cout << "Initial Map State:\n";
    for (int y = 0; y < gameMap.getHeight(); y++) {
        for (int x = 0; x < gameMap.getWidth(); x++) {
            try {
                const Object& obj = gameMap.getObjectAt(x, y);
                cout << obj.getType() << " ";
            } catch (const std::out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        cout << endl;
    }

    // Number of goblins in the map
    cout << "\nNumber of Goblins on the map: " << gameMap.getNumGoblins() << endl;

    // Kill a goblin at position (3, 0)
    cout << "\nKilling Goblin at (3, 0)...\n";
    gameMap.killGoblin(3, 0);

    // Check if the goblin count updates
    cout << "Number of Goblins killed: " << gameMap.getGoblinsKilled() << endl;

    // Display the updated map state
    cout << "\nUpdated Map State:\n";
    for (int y = 0; y < gameMap.getHeight(); y++) {
        for (int x = 0; x < gameMap.getWidth(); x++) {
            try {
                const Object& obj = gameMap.getObjectAt(x, y);
                cout << obj.getType() << " ";
            } catch (const std::out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        cout << endl;
    }

    // Try to access an invalid position to test error handling
    cout << "\nAttempting to access an invalid position (5, 5)...\n";
    try {
        const Object& invalidObj = gameMap.getObjectAt(5, 5);
        cout << invalidObj.getType() << endl;
    } catch (const std::out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
