#include <iostream>
#include "addit_header/GameMap.h"
#include "addit_header/Swords.h"
#include "addit_header/Potions.h"
#include "Character_header/Goblin.h"
#include "addit_header/Inventory.h"
#include <vector>
  // Assuming the GameMap and related classes are in the same directory
int main() {
    vector<vector<int>> initMatrix = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {4, 0, 0, 3, 0},
        {0, 0, 0, 0, 0}
    };
    GameMap gameMap(initMatrix, 5, 5);

    cout << "Initial Game Map Objects:\n";
    for (int y = 0; y < gameMap.getHeight(); y++) {
        for (int x = 0; x < gameMap.getWidth(); x++) {
            shared_ptr<Object> obj = gameMap.getObjectAt(x, y);
            cout << "(" << x << ", " << y << ") -> " << obj->getType();


            if (obj->getType() == "Goblin") {
                shared_ptr<Goblin> goblin = dynamic_pointer_cast<Goblin>(obj);
                if (goblin) {
                    cout << " (Goblin Type: " << goblin->getGoblinType() << ")";
                }
            }
            cout << endl;
        }
    }

    cout << "\nAttempting to kill a Goblin at (1, 1)...\n";
    gameMap.killGoblin(1, 1);  // Goblin is at (1, 1)

    cout << "After killing Goblin, Game Map Objects:\n";
    for (int y = 0; y < gameMap.getHeight(); y++) {
        for (int x = 0; x < gameMap.getWidth(); x++) {
            shared_ptr<Object> obj = gameMap.getObjectAt(x, y);
            cout << "(" << x << ", " << y << ") -> " << obj->getType();
            if (obj->getType() == "Goblin") {
                shared_ptr<Goblin> goblin = dynamic_pointer_cast<Goblin>(obj);
                if (goblin) {
                    cout << " (Goblin Type: " << goblin->getGoblinType() << ")";
                }
            }
            cout << endl;
        }
    }

    return 0;
}