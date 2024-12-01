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

    MenuPrinter::tutorialMenu();
    
    // player should choose betwen 1. play tutorial or 2. don't
    cin >> playerChoice;

    // if the player chooses none of these, repeatedly get input
    while ((playerChoice != 1) && (playerChoice != 2)) {
        cout << "Please enter '1' or '3.'" << endl;
        cin.clear();
        cin >> playerChoice;
    }

    // atp, player should have chosen one of these options

    if (playerChoice == 1) {
        // actually not sure how i would integrate the tutorial in here
    }
    // now the actual game should run
    
    // building theo (aka the player)
    // note: theo starts level 1 with the Wind ability
    MainCharacter theo("Theodore", 100, 5, "Wind");
    GameManager game;
    game.gameStart();

    

    return 0;
}