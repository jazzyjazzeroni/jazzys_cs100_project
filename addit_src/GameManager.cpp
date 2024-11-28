#include "../addit_header/GameManager.h"
#include <iostream>

using namespace std;

// Constructor to initialize levels
GameManager::GameManager() : currLevel(0), level(initializeLevels()) {}

// Start the game
void GameManager::gameStart() {
    cout << "Welcome to the Flames & Ice!" << endl;
    while (currLevel < levels.size()) {
        cout << "Starting Level " << currLevel + 1 << endl;
        levels[currLevel].start();

        if (levels[currLevel].getCurrentLevel() == levels.size()) {
            cout << "Congratulations! You've completed all levels!" << endl;
            return;
        }

        nextLevel();
    }
}

// Progress to the next level
void GameManager::nextLevel() {
    
    if (currLevel + 1 < levels.size()) {
        currLevel++;
        levels[currLevel].setLevel(currLevel + 1);
        cout << "Proceeding to Level " << currLevel + 1 << "..." << endl;
    } else {
        cout << "No more levels available." << endl;
    }
}

// Handle user input for global actions outside levels
void GameManager::handleInput() {
    char input;
    cout << "Enter 'q' to quit or 'c' to continue: ";
    cin >> input;

    if (input == 'q') {
        cout << "Thanks for playing!" << endl;
        exit(0);
    }
}
