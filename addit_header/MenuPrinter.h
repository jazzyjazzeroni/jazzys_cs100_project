#include <string>
#include <iostream>
#include "MainCharacter.h"
using namespace std;
#ifndef __MENUPRINTER_H__
#define __MENUPRINTER_H__

class Interface{
protected:
string selectChar;
MainChar mmc;

public:
string getChar()const;
void setChar(string);
void displayMainMenu();
void displayBattleMenu();
void displayStatus();

};
#endif