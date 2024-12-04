#ifndef POTIONS_H
#define POTIONS_H

#include <string>
<<<<<<< HEAD
// #include "Inventory.h"
#include "Object.h"
// #include "../Character_header/MainCharacter.h"
=======
#include <iostream>
#include "Object.h"
#include "../Character_header/MainCharacter.h"

>>>>>>> master
using namespace std;

class Potion  : public Object {
private:
    int healingAmount{}; 
    string type{};  

public:
    Potion();
    Potion(int healAmount, const string& potionType);

    int getHealingAmount() const;
    void setHealingAmount(int amount);

    string getType() const override;
    void setType(const string& type);
    void print() const override;
<<<<<<< HEAD
    // void healCharacter(MainCharacter &character);
=======
    void healCharacter(MainCharacter &character);
>>>>>>> master
};

#endif