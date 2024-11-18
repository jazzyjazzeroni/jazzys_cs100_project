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
double sword_dam;
double heal_num;

public:
string getMushroom () const;
void setMushroom(string);
vector<string> getSword() const;
void setSword(vector<string>);
vector<string> getPotion() const;
void setPotion(vector<string>);
void removePotion();
void removeSword();
double getswordDam() const;
void setswordDam(double);
double getHealAmount() const;
void setHealAmount(double);
};
#endif