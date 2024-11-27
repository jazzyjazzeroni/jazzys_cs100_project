#include <iostream>
#include "../addit_header/GameManager.h"
#include "../addit_header/MenuPrinter.h"
using namespace std;

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

        while (true) {
            levels[currLevel].takeAction();

            if (levels[currLevel])
                cout << "Level " << (currLevel + 1) << " complete!" << endl;
                currLevel++;
                break;
            }

            char choice;
            cout << "Press p to pause\n";
            cin >> choice;
            if (choice == 'p') {
                pause();
            }
        }
    }

     
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
    std::cout << "You ended the journey. See you again!\n";
    exit(0);
}