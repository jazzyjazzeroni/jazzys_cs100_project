#include <iostream>
#include "Character_header/Character.h"
#include "Character_header/Goblin.h"

using namespace std;

int main() {
    // Creating a Character (Main character) directly, using Character class
    Character mainCharacter(MAINCHAR, "Theodore", 100, 20, 15);  // Hero as a general Character
    
    // Creating a goblin
    Goblin goblin("Grumpy Goblin", 50, 10, "");  // No special power now
    
    // Displaying initial statuses
    cout << mainCharacter.getType() << " health: " << mainCharacter.getHealth() << endl;
    cout << goblin.getType() << " health: " << goblin.getHealth() << endl;

    // Main Character attacks Goblin
    mainCharacter.attack(goblin);
    cout << goblin.getType() << " health after attack: " << goblin.getHealth() << endl;

    // Goblin attacks Main Character
    goblin.attack(mainCharacter);
    cout << mainCharacter.getType() << " health after attack: " << mainCharacter.getHealth() << endl;

    // Checking if both are still alive
    if (mainCharacter.isalive()) {
        cout << mainCharacter.getType() << " is still alive!" << endl;
    } else {
        cout << mainCharacter.getType() << " is defeated!" << endl;
    }

    if (goblin.isalive()) {
        cout << goblin.getType() << " is still alive!" << endl;
    } else {
        cout << goblin.getType() << " is defeated!" << endl;
    }

    return 0;
};


