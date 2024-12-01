#include "../addit_header/GameManager.h"
#include "../addit_header/MenuPrinter.h"
#include "../addit_header/Level.h"
#include "../Character_header/Character.h"
#include "../Character_header/MainCharacter.h"

// Constructor to initialize levels
GameManager::GameManager() : current_level(0), main_char("Theodore", 100, 5, "AIR")
{
    levels = initializeLevels(); // Initialize levels using provided function
}
// Start the game
void GameManager::gameStart()
{
    std::std::cout << "Your Journey Begins...\n";
    MenuPrinter::movementMenu(); // Will display keys and keys for attack
    while (current_level < levels.size())
    {
        std::cout << "Starting Level " << current_level + 1 << '\n';
        levels[current_level].start();

        if (levels[current_level].isCompleted())
        {
            std::cout << "Level " << current_level + 1 << " completed!" << '\n';
            current_level++;
            if (current_level < levels.size())
            {
                levels[current_level].prepareNextLevel(main_char);
            }
        }
        else
        {
            std::cout << "You have died..." << '\n';
            return;
        }
    }
}

// Progress to the next level
void GameManager::nextLevel()
{

    if (currLevel + 1 < levels.size())
    {
        currLevel++;
        levels[currLevel].setLevel(currLevel + 1);
        std::cout << "Proceeding to Level " << currLevel + 1 << "..." << '\n';
    }
    else
    {
        std::cout << "No more levels available." << '\n';
    }
}

// Handle user input for actions outside levels
void GameManager::handleInput()
{
    char input;
    std::cout << "Enter 'q' to quit or 'c' to continue: ";
    cin >> input;

    if (input == 'q')
    {
        std::cout << "Thanks for playing!" << '\n';
        exit(0);
    }
}

// Update the game state
void GameManager::update()
{
    if (currLevel < levels.size())
    {
        levels[currLevel].start();
    }
    else
    {
        std::cout << "Game Over!" << '\n';
    }
}

// EMMANS CODE
void GameManager::pause()
{
    // since the main_char chose to pause, output pause menu
    MenuPrinter::pauseMenu();
    char choice{};
    int quit_choice{};
    while (true)
    {

        // get input from main_char
        cin >> choice;

        // if the user input anything other than 'r' and 'q'
        while ((choice != 'r') && (choice != 'q'))
        {
            // keep getting input from them
            cin.clear();
            std::cout << "Please select 'r' to resume or 'q' to quit\n";
            cin >> choice;
        }

        // atp user should have input either 'r' or 'q'

        // if main_char input 'r' (to resume the game)
        if (choice == 'r')
        {
            // resume the game
            std::cout << "Resuming...\n";
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
            while ((quit_choice != 1) && (quit_choice != 2))
            {
                // keep getting input from them
                cin.clear();
                std::cout << "Please select 1 or 2.\n";
                cin >> quit_choice;
            }

            // atp user should have input either 1 or 2

            // if user chose '1' (Yes)
            if (quit_choice == 1)
            {
                quit();
            }

            // if user chose '2' (No)
            else if (quit_choice == 2)
            {
                break;
            }
        }
    }
}
void GameManager::quit()
{
    std::cout << "You ended the journey. See you again!\n"; // updated to an exclamation point....
    exit(0);
}
