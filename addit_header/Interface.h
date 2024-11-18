#include <string>
#include <iostream>
using namespace std;
#ifndef __INTERFACE_H__
#define __INTERFACE_H__



class Interface{
protected:
string selectChar;

public:
string getChar()const;
void setChar(string);
void printMenu();
void buffer();
void update();

};
#endif