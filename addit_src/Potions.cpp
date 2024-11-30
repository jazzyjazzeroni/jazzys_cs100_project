#include "../addit_header/Potions.h"
#include <iostream>
#include <string>
using namespace std;


Potion::Potion() : healingAmount(0), type("") {}

Potion::Potion(int healAmount, const string &potionType)
    : healingAmount(healAmount), type(potionType) {}

int Potion::getHealingAmount() const {
    return healingAmount;
}

void Potion::setHealingAmount(int amount) {
    healingAmount = amount;
}

string Potion::getType() const {
    return "Potion";
}

void Potion::setType(const string &potionType) {
    type = potionType;
}

void Potion::print() const {
    cout << "Name: " << type << ", Value: " << healingAmount << endl;
}

// void Potion::healCharacter(MainCharacter &character) {
//     if (type == "Small Potion") {
//         character.heal(50); 
//     } else if (type == "Large Potion") {
//         character.heal(100); 
//     } else {
//         character.heal(healingAmount); 
//     }
// }
