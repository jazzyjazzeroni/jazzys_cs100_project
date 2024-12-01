#include "../addit_header/Tutorial.h"
#include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/Level.h"
#include "../addit_header/MenuPrinter.h"
#include "../addit_header/Object.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Powers.h"
#include "../addit_header/Swords.h"
#include "../Character_header/Character.h"
#include "../Character_header/Dragon.h"
#include "../Character_header/Goblin.h"
#include "../Character_header/MainCharacter.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

int main() {

    // prints out the main menu upon starting the game
    MenuPrinter::printMainMenu();
    // player should then choose between 1. start 2. settings 3. quit
    int playerChoice;
    cin >> playerChoice;
    
    // if the player chooses none of these, repeatedly get input
    while ((playerChoice != 1) && (playerChoice != 2) && (playerChoice != 3)) {
        cout << "Please enter '1,' '2,' or '3.'" << endl;
        cin.clear();
        cin >> playerChoice;
    }

    // atp, player should have chosen one of these options

    if (playerChoice == 3) {
        exit(0); // just end the program
    }

    //else if (playerChoice == 2) {
        // still not sure if we will have settings
    //}

    // if playerChoice is neither 2 or 3, then game will run

    cout << "Would you like to play the tutorial first?" << endl;
    cout << endl;
    cout << "       1. Yes              2. No          " << endl;
    cout << endl;

    // player should choose betwen 1. play tutorial or 2. don't
    cin >> playerChoice;

    // if the player chooses none of these, repeatedly get input
    while ((playerChoice != 1) && (playerChoice != 2)) {
        cout << "Please enter '1' or '2.'" << endl;
        cin.clear();
        cin >> playerChoice;
    }

    // atp, player should have chosen one of these options

    if (playerChoice == 1) {
        Tutorial tutorialLoader;
        tutorialLoader.tutorial(); // should play the tutorial
    }
    // now the actual game should run
    
    // this should build the levels and theo
    GameManager game;

    // assuming that this just loads and runs the first level
    game.gameStart();

    // loops for all 5 levels (including the boss i think)
    for (int i = 1; i <= 5; i++) {
        // assuming that nextLevel only loads the next level
        game.nextLevel();
        // assuming that update runs the new level
        game.update();
    }

    return 0;
}