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
    return type;
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

int main() {
    // Create a default potion
    Potion defaultPotion;
    cout << "Default Potion:" << endl;
    defaultPotion.print();

    // Create a healing potion with specific properties
    Potion healingPotion(50, "Healing Potion");
    cout << "\nCustom Potion:" << endl;
    healingPotion.print();

    // Modify the default potion
    defaultPotion.setHealingAmount(30);
    defaultPotion.setType("Small Healing Potion");
    cout << "\nModified Default Potion:" << endl;
    defaultPotion.print();

    return 0;
}