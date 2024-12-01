#include "../addit_header/GameManager.h"
#include "../addit_header/MenuPrinter.h"
#include "../addit_header/Level.h"
#include "../Character_header/Character.h"
#include "../Character_header/MainCharacter.h"


// Constructor to initialize levels
GameManager::GameManager() : currentLevelIndex(0), player("Theodore", 100, 5, "AIR") {
        levels = initializeLevels(); // Initialize levels using provided function
    }
// Start the game
void GameManager::gameStart() {
    std::cout << "Your Journey Begins...\n";
    MenuPrinter::movementMenu(); // Will display keys and keys for attack
     while (currentLevelIndex < levels.size()) {
            cout << "Starting Level " << currentLevelIndex + 1 << endl;
            levels[currentLevelIndex].start();

            if (levels[currentLevelIndex].isCompleted()) {
                cout << "Level " << currentLevelIndex + 1 << " completed!" << endl;
                currentLevelIndex++;
                if (currentLevelIndex < levels.size()) {
                    levels[currentLevelIndex].prepareNextLevel(player);
                }
            } else {
                cout << "You have been defeated! Game over." << endl;
                return;
            }
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

// Update the game state
void GameManager::update() {
    if (currLevel < levels.size()) {
        levels[currLevel].start();
    } else {
        cout << "Game Over!" << endl;
    }
}

// EMMANS CODE
void GameManager::pause()
{
    // since the player chose to pause, output pause menu
    MenuPrinter::pauseMenu();
    char choice{};
    int quit_choice{};
    while (true)
    {

        // get input from player
        cin >> choice;

        // if the user input anything other than 'r' and 'q'
        while ((choice != 'r') && (choice != 'q')) {
            // keep getting input from them
            cin.clear();
            cout << "Please select 'r' to resume or 'q' to quit\n";
            cin >> choice;
        }
        
        // atp user should have input either 'r' or 'q'

        // if player input 'r' (to resume the game)
        if (choice == 'r')
        {
            // resume the game
            cout << "Resuming...\n";
            break;
        }
        
        // if the user input 'q' (to quit the game)
        else if (choice == 'q')
        {
            // output quit reassurance prompt
            MenuPrinter::quitReassuranceMenu();
            
            // get quit choice from user
            cin >> quit_choice;

            // while the user inputs something other than 1 and 2
            while ((quit_choice != 1) && (quit_choice != 2)) {
                // keep getting input from them
                cin.clear();
                cout << "Please select 1 or 2.\n";
                cin >> quit_choice;
            }

            // atp user should have input either 1 or 2
            
            // if user chose '1' (Yes)
            if (quit_choice == 1) { quit(); }

            // if user chose '2' (No)
            else if (quit_choice == 2) { break; }
        }
    }
}
void GameManager::quit()
{
    std::cout << "You ended the journey. See you again!\n"; // updated to an exclamation point....
    exit(0);
}


