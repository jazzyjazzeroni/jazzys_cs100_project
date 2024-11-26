
#ifndef POTIONS_H
#define POTIONS_H

#include <string>
#include "Inventory.h"
#include "Object.h"
using namespace std;

class Potion  : public Object {
private:
    int healingAmount = 0; 
    string type;  

public:
    Potion();
    Potion(int healAmount, const string& potionType);

    int getHealingAmount() const;
    void setHealingAmount(int amount);

    string getType() const;
    void setType(const string& type);
    void healCharacter();
    void heal(int amount);  // Declare heal method
};

#endif