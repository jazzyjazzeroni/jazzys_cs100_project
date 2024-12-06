#include <string>
#include <iostream>
#include "../addit_header/MenuPrinter.h"
#include "../Character_header/MainCharacter.h"
#include "../addit_header/Level.h"
using namespace std;

// prints the main/title screen
void MenuPrinter::printMainMenu() {
    cout << "              FLAMES OF               " << endl;
    cout << "                =ICE=                 " << endl;
    cout << endl;
    cout << "               1. Start                " << endl;
    cout << "               2. Exit                 " << endl;
    cout << endl;
}

// prints when the player is roaming in the levels
void MenuPrinter::movementMenu() {
    cout << "   What action do you want to take ? " << endl << endl;
    cout << endl;
    cout << "           UP: press 'w'                  " << endl << endl;
    cout << "           LEFT: press 'a'                " << endl << endl;
    cout << "           RIGHT: press 'd'               " << endl << endl;
    cout << "           DOWN: press 's'                " << endl << endl;
    cout << "           OPEN INVENTORY: press 'i'      " << endl << endl;
    cout << "           QUIT: press 'q'               " << endl << endl;
    cout << "           GOBLIN STATUS: press 'g'               " << endl << endl;
    cout << "           CHECK HEALTH: press 't'               " << endl << endl;
    cout << "           ACTION MENU: press 'm'               " << endl << endl;
    cout << endl;
}

// prints when a fire goblin is encountered
void MenuPrinter::GoblinEncounterMenu(const Goblin& goblin) {
    cout << "         A goblin has appeared!        " << endl << endl;
    cout << "              Element: " << goblin.getGoblinType() << endl << endl;
    cout << "         Do you choose to fight?         " << endl;
    cout << endl;
    cout << "       1. Yes              2. No         " << endl;
    cout << endl;
}


// prints when it's the player's turn during combat
void MenuPrinter::playerTurnMenu(const MainCharacter& player) {
    cout << "               YOUR TURN                  " << endl;
    cout << endl;
    cout << "       Health: " << player.getHealth()      << endl;
    cout << "          Choose your action:             " << endl;
    cout << "            k: Sword Attack               " << endl;
    cout << "            p: Power Attack               " << endl;
    cout << endl;
}

// prints after player opens inventory i think
void MenuPrinter::useItemsMenu() {
    cout << "               USE ITEMS:                 " << endl;
    cout << endl;
    cout << "         1. Open Potions List             " << endl;
    cout << endl;
}

// prints after player dies
void MenuPrinter::deathScreen() {
    cout << "               YOU DIED                   " << endl;
    cout << endl;
    cout << "       Returning to Title Screen.         " << endl;
    cout << endl;
}


// prints after player chooses to save and quit
void MenuPrinter::quitReassuranceMenu() {
    cout << "    Are you sure you want to quit?        " << endl;
    cout << endl;
    cout << "       1. Yes              2. No          " << endl;
    cout << endl;
}

// this function name might need to get changed
// prints after a goblin gets defeated i think
void MenuPrinter::printGoblinStatus(int left, int killed) {
    cout << "        GOBLIN HAS BEEN SLAIN!           " << endl;
    cout << "     Defeat " << left << " more!         " << endl;
}

// prints the player's current health
void MenuPrinter::printStatus(const MainCharacter& player) {
    cout << "   CURRENT HEALTH: " << player.getHealth() << endl;
    cout << endl;
}