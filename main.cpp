#include <iostream>
#include "Character_header/MainCharacter.h"
#include "addit_header/GameMap.h"

using namespace std;

int main() {
    // Example map where 1 represents a Goblin, 6 is a Basic Sword, and 8 is a Small Potion
    vector<vector<int>> mapData = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 6, 0},
        {0, 0, 0, 0, 0},
        {0, 8, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Create a GameMap with the given data (5x5 grid)
    GameMap gameMap(mapData, 5, 5);

    // Create the MainCharacter
    MainCharacter mainChar("Hero", 100, 20, "Fire");

    // Print initial state of the game
    cout << "Initial state:" << endl;
    mainChar.print();
    cout << "GameMap Size: " << gameMap.getWidth() << "x" << gameMap.getHeight() << endl;

    // Get initial position of the character
    pair<int, int> charPosition = mainChar.getPosition();
    cout << "Character's initial position: (" << charPosition.first << ", " << charPosition.second << ")\n";

    // Interact with the map (attack a goblin and pick up a sword)
    cout << "\nAttacking a goblin at position (1, 1):" << endl;
    shared_ptr<Object> obj = gameMap.getObjectAt(1, 1);
    if (obj->getType() == "Goblin") {
        mainChar.attack(dynamic_cast<Character&>(*obj));  // Attack the goblin
        gameMap.killGoblin(1, 1);  // Remove goblin from the map
    }

    // Check for sword pick-up (position 3, 0)
    cout << "\nPicking up a sword at position (3, 0):" << endl;
    obj = gameMap.getObjectAt(3, 0);
    if (obj->getType() == "Sword") {
        Sword* sword = dynamic_cast<Sword*>(obj.get());
        if (sword) {
            mainChar.equipSword(*sword);  // Equip the sword
        }
    }

    // Check for potion pick-up (position 3, 1)
    cout << "\nPicking up a potion at position (3, 1):" << endl;
    obj = gameMap.getObjectAt(3, 1);
    if (obj->getType() == "Potion") {
        Potion* potion = dynamic_cast<Potion*>(obj.get());
        if (potion) {
            mainChar.usePotion(potion->getType());  // Use the potion
        }
    }

    // Print updated character stats
    mainChar.print();

    // Show number of goblins remaining on the map
    cout << "Remaining goblins on the map: " << gameMap.getNumGoblins() << endl;

    // Simulate movement (but we are not using `move()` since it's not working as per your instructions)
    // Example: simulate character movement manually by updating its position
    cout << "\nMoving the character manually to position (2, 3):" << endl;
    mainChar.setPosition(2, 3);
    charPosition = mainChar.getPosition();
    cout << "Character's new position: (" << charPosition.first << ", " << charPosition.second << ")\n";

    return 0;
}

