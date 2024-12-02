#include <iostream>
#include "Character_header/MainCharacter.h"
#include "Character_header/Goblin.h"
#include "addit_header/Swords.h"
#include "addit_header/Potions.h"
#include "addit_header/GameMap.h"

using namespace std;

int main() {
    // Example initialization of a GameMap
    vector<vector<int>> initMatrix = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int mapWidth = 5;
    int mapHeight = 5;

    // Create the GameMap
    GameMap gameMap(initMatrix, mapWidth, mapHeight);

    // Initialize MainCharacter at (1, 1)
    MainCharacter mainChar("Hero", 100, 20, "Fire");
    mainChar.setPosition(1, 1);  // Start the character at position (1, 1)

    char input;
    bool running = true;

    cout << "Use WASD to move, q to quit." << endl;

    // Main game loop
    while (running) {
        // Display current position of the character
        auto [x, y] = mainChar.getPosition();
        cout << "Current position: (" << x << ", " << y << ")" << endl;

        // Get user input for movement
        cout << "Enter movement (WASD): ";
        cin >> input;

        // Quit if user enters 'q'
        if (input == 'q') {
            running = false;
            break;
        }

        // Move the character based on user input
        shared_ptr<Object> obj = mainChar.move(input, gameMap);

        // Check if there is an object at the new position and print message
        if (obj->getType() == "Goblin") {
            cout << "You encounter a Goblin!" << endl;
        } else if (obj->getType() == "Sword") {
            cout << "You found a sword!" << endl;
        } else if (obj->getType() == "Potion") {
            cout << "You found a potion!" << endl;
        } else {
            cout << "You moved to an empty space." << endl;
        }
    }

    cout << "Game over. Final position: (" << mainChar.getPosition().first << ", " 
         << mainChar.getPosition().second << ")" << endl;

    return 0;
}