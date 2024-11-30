#include <iostream>
#include "addit_header/GameMap.h"
#include "addit_header/Swords.h"
#include "addit_header/Potions.h"
#include "Character_header/Goblin.h"
#include "addit_header/Inventory.h"
#include <vector>

using namespace std;

int main() {
    // Create a map matrix to initialize the game map
    vector<vector<int>> mapMatrix = {
        {0, 0, 1, 4},
        {5, 6, 0, 0},
        {0, 3, 2, 4}
    };
    // Initialize the game map
    GameMap gameMap(mapMatrix, 4, 3);
    cout << "Map initialized." << endl;
    // Test map dimensions
    cout << "Map Dimensions: " << gameMap.getWidth() << "x" << gameMap.getHeight() << endl;
    // Test retrieving and printing objects from the map
    try {
        cout << "Attempting to get object at (3, 0)" << endl;
        Object& obj = gameMap.getObjectAt(3, 0); // Goblin at (0, 3)
        cout << "Object at (3, 0): " << obj.getType() << " with value " << obj.getValue() << endl;
        cout << "Attempting to get object at (2, 2)" << endl;
        Object& sword = gameMap.getObjectAt(2, 2); // Sword at (2, 2)
        cout << "Object at (2, 2): " << sword.getType() << " with value " << sword.getValue() << endl;
        cout << "Attempting to get object at (1, 1)" << endl;
        Object& potion = gameMap.getObjectAt(1, 1); // Potion at (1, 1)
        cout << "Object at (1, 1): " << potion.getType() << " with value " << potion.getValue() << endl;
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    // Test goblin count and goblin kill logic
    cout << "Initial goblins: " << gameMap.getNumGoblins() << endl;
    cout << "Attempting to kill goblin at (3, 0)" << endl;
    gameMap.killGoblin(3, 0); // Kill the goblin at (0, 3)
    cout << "Goblins killed: " << gameMap.getGoblinsKilled() << endl;
    // Test adding objects to inventory
    Inventory inventory;
    inventory.addSword(Sword(15, "Greater Sword"));
    inventory.addPotion(Potion(10, "Large Potion"));
    cout << "Inventory contents:" << endl;
    // Print swords in inventory
    for (const auto& sword : inventory.getSwords()) {
        cout << "Sword: " << sword.getName() << ", Damage: " << sword.getPower() << endl;
    }
    // Print potions in inventory
    for (const auto& potion : inventory.getPotions()) {
        cout << "Potion: " << potion.getType() << ", Healing Amount: " << potion.getHealingAmount() << endl;
    }
    return 0;
}