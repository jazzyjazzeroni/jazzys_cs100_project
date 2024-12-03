#ifndef __MENUPRINTER_H__
#define __MENUPRINTER_H__

#include <string>
#include <iostream>
#include "../Character_header/MainCharacter.h"

using namespace std;

class MenuPrinter {

public:
// string getChar()const;
// void setChar(string);
static void printMainMenu();
static void printGoblinStatus(int left, int killed);
static void printStatus(const MainCharacter& player);
static void tutorialMenu();
static void movementMenu();
static void fireGoblinEncounterMenu();
static void waterGoblinEncounterMenu();
static void earthGoblinEncounterMenu();
static void windGoblinEncounterMenu();
static void playerTurnMenu(const MainCharacter& playerTurnMenu);
static void useItemsMenu();
static void deathScreen();
static void pauseMenu();
static void quitReassuranceMenu();

};
#endif