#include <string>
#include <iostream>
#include <vector>
using namespace std;
#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class Inventory{
protected:
string swords;
string potions;
int sword_dam;
int heal_num;
int num_sword;
int num_potions;

public:
string getSword() const;
void setSword(string);
string getPotion() const;
void setPotion(string);
void removePotion();
void removeSword();
int getswordDam() const;
void setswordDam(int);
int getHealAmount() const;
void setHealAmount(int);
void displayInventory();
};
#endif