#include <string>
#include <iostream>
#include "MainCharacter.h"
using namespace std;
#ifndef __MAP_H__
#define __MAP_H__

class Map{
protected:
int x_pos;
int y_pos;
int height;
int length;

public:
string getChar()const;
void setChar(string);
void displayMainMenu();
void displayBattleMenu();
void displayStatus();

};
#endif