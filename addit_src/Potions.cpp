#include "../addit_header/Potions.h"
#include <iostream>
#include <string>
using namespace std;

    Potion::Potion () {
        healingAmount = 0;
        type = "";
    }

    Potion::Potion(int healAmount, const string& potionType) {
        healingAmount = healAmount;
        type = potionType;
    }

    int Potion::getHealingAmount() const {
        return healingAmount;
    }
    void Potion::setHealingAmount(int amount) {
        healingAmount = amount;
    }

    string Potion::getType() const {
        return type;
    }

    void Potion::setType(const string& type) {
        this->type = type;
    }

    // void Potion::heal(int amount) needs to be implemented


    void Potion::healCharacter() {
        if (this->type == "Small Potion") {
            heal(50);
        }
        else if (this->type == "Large Potion") {
            heal(100);
        }
    }