#include "../addit_header/GameManager.h"
#include "../addit_header/MenuPrinter.h"

//    Level(int power, const vector<vector<int>>& mapLayout, int numGoblins);

GameManager::GameManager() : currLevel(0)
{
    
}

GameManager::~GameManager(){};

void GameManager::gameStart()
{
     while (currLevel < levels.size()) {
        cout << "\nStarting Level " << (currLevel + 1) << endl;
        levels[currLevel].start();

        // Main loop for the current level
        while (true) {
            levels[currLevel].takeAction();

            // Check if the level has ended
            if (levels[currLevel].isLevelComplete()) {
                cout << "Level " << (currLevel + 1) << " complete!" << endl;
                currLevel++;
                break;
            }

            // Optionally, allow pausing
            string choice;
            cout << "Enter 'p' to pause or any other key to continue: ";
            cin >> choice;
            if (choice == "p") {
                pause();
            }
        }
    }

    cout << "You have slain Ignus!\n";
}
     
void GameManager::pause()
{
    MenuPrinter::pauseMenu();
    char choice{};
    int quit_choice{};
    while (true)
    {
        std::cin >> choice;
        if (choice == 'r')
        {
            std::cout << "Resuming...\n";
            break;
        }
        else if (choice == 'q')
        {
            MenuPrinter::quitReassuranceMenu();
            if (quit_choice = 1)
                quit();
            else if (quit_choice=2) 
                break;
            else
                std::cout << "Invalid option: Select 1 or 2\n";         
        }
        else
            std::cout << "Invalid option. Select 'r' to resume or 'q' to quit\n";
    }

}

void GameManager::quit()
{
    std::cout << "You ended the journey. See you again\n";
    exit(0);
}