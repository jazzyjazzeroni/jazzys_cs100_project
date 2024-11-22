#include <string>
#include <iostream>
#include "MenuPrinter.h"
using namespace std;

// prints the main/title screen
void MenuPrinter::printMainMenu() {
    cout << "                 FLAMES  OF               " << endl;
    cout << "                    =ICE=                 " << endl;
    cout << endl;
    cout << "                  1. Start                " << endl;
    cout << "                  2. Settings             " << endl;
    cout << "                  3. Exit                 " << endl;
    cout << endl;
}

// prints when the player chooses to go to settings
void MenuPrinter::printSettingsMenu() {
    cout << "                  SETTINGS                " << endl;
    cout << endl;
    cout << "             1. Change language           " << endl;
    cout << "             2. Return                    " << endl;
    cout << endl;
}

// prints when the player chooses to change languages
void MenuPrinter::printLanguageMenu() {
    cout << "              CHANGE LANGUAGE             " << endl;
    cout << endl;
    cout << "                1. English                " << endl;
    cout << "                2. Spanish                " << endl;
    cout << "                3. Mandarin               " << endl;
    cout << endl;
}

// prints when the player is roaming in the levels
void MenuPrinter::movementMenu() {
    cout << "   What direction do you want to move in? " << endl;
    cout << endl;
    cout << "           UP: press 'w'                  " << endl;
    cout << "           LEFT: press 'a'                " << endl;
    cout << "           RIGHT: press 'd'               " << endl;
    cout << "           DOWN: press 's'                " << endl;
    cout << "           OPEN INVENTORY: press 'i'      " << endl;
    cout << "           PAUSE: press 'p'               " << endl;
    cout << endl;
}

// prints when a fire goblin is encountered
void MenuPrinter::fireGoblinEncounterMenu() {
    cout << "      A fire goblin has appeared!        " << endl;
    cout << "         Do you choose to fight?         " << endl;
    cout << endl;
    cout << "       1. Yes              2. No         " << endl;
    cout << endl;
}

// prints when a water goblin is encountered
void MenuPrinter::waterGoblinEncounterMenu() {
    cout << "      A water goblin has appeared!        " << endl;
    cout << "         Do you choose to fight?         " << endl;
    cout << endl;
    cout << "       1. Yes              2. No         " << endl;
    cout << endl;
}

// prints when a earth goblin is encountered
void MenuPrinter::earthGoblinEncounterMenu() {
    cout << "      A earth goblin has appeared!        " << endl;
    cout << "         Do you choose to fight?         " << endl;
    cout << endl;
    cout << "       1. Yes              2. No         " << endl;
    cout << endl;
}

// prints when a wind goblin is encountered
void MenuPrinter::windGoblinEncounterMenu() {
    cout << "       A wind goblin has appeared!       " << endl;
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

// prints after player chooses to pause
void MenuPrinter::pauseMenu() {
    cout << "                PAUSED                    " << endl;
    cout << endl;
    cout << "           1. Resume                      " << endl;
    cout << "           2. Settings                    " << endl;
    cout << "           3. Save and quit               " << endl;
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
void MenuPrinter::printGoblinMenu(int left, int killed) {
    cout << "        GOBLIN HAS BEEN SLAIN!           " << endl;
    cout << "     Defeat " << left << " more!         " << endl;
}

// prints the player's current health
void MenuPrinter::printStatus(const MainCharacter& player) {
    cout << "   CURRENT HEALTH: " << player.getHealth() << endl;
    cout << endl;
}