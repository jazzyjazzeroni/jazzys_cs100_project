#include <string>
#include <iostream>
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Goblin.h"
using namespace std;
#ifndef __MENUPRINTER_H__
#define __MENUPRINTER_H__

class MenuPrinter{

public:
static void printMainMenu();
static void printGoblinStatus(int left, int killed);
static void printStatus(const MainCharacter& player);
static void tutorialMenu();
static void movementMenu();
static void GoblinEncounterMenu(const Goblin& goblin);
static void playerTurnMenu(const MainCharacter& player);
static void useItemsMenu();
static void deathScreen();
static void quitReassuranceMenu();

};
#endif