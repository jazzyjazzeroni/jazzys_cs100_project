#include <string>
#include <iostream>
#include "../Character_header/MainCharacter.h"
using namespace std;
#ifndef __MENUPRINTER_H__
#define __MENUPRINTER_H__

class MenuPrinter{

public:
// string getChar()const;
// void setChar(string);
static void printMainMenu();
static void printGoblinStatus(int left, int killed);
static void printStatus(const MainCharacter& player);

};
#endif