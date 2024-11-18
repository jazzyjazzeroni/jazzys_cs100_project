#include <string>
#include <iostream>
#include "MainCharacter.h"
using namespace std;
#ifndef __INTERFACE_H__
#define __INTERFACE_H__



class Interface{
protected:
string selectChar;
MainChar mmc;

public:
string getChar()const;
void setChar(string);
void printMenu();
void buffer();
void update();
void displayMainMenu();
void displayBattleMenu();
void displayStatus();

};
#endif