#ifndef POTIONS_H
#define POTIONS_H

#include <string>
#include "Inventory.h"
#include "Object.h"
#include "../Character_header/MainCharacter.h"
using namespace std;

class Potion  : public Object {
private:
    int healingAmount; 
    string type;  
    string type; // "character" | "sword" | "potion" | "empty"
    int value; // 0 | 5 | 10 | 15

public:
    Potion(){};
    Potion(int healAmount, const string& potionType);

    int getHealingAmount() const;
    void setHealingAmount(int amount);

    string getType() const;
    void setType(const string& type);
    void healCharacter(MainCharacter &character);
};

#endif