#include <string>
#include <iostream>
#include <vector>
using namespace std;
#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class Inventory{
protected:
string mushroom;
vector<string>  swords;
vector<string>  potions;

public:
string getMushroom () const;
void setMushroom(string);
vector<string> getSword() const;
void setSword(vector<string>);
vector<string> getPotion() const;
void setPotion(vector<string> );

};
#endif