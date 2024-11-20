#include <string>
#include <iostream>
#include <vector>
using namespace std;
#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class Item {
public:
    string name;
    int value;

    Item(string name, int value) : name(name), value(value) {}
};

class Inventory {
private:
    vector<Item> swords;
    vector<Item> potions;

public:
    void addSword(const string &name, int damage);
    void addPotion(const string &name, int healAmount);

    void removeSword(const string &name);
    void removePotion(const string &name);

    Item* getSword(const string &name);
    Item* getPotion(const string &name);
};

#endif