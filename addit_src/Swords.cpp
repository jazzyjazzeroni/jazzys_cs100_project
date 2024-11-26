#include "../addit_header/Swords.h"
#include <iostream>
#include <string>
using namespace std;

Sword::Sword() : sword_dam(0), sword_name("") {}

Sword::Sword(int pwr, const string& nm) : sword_dam(pwr), sword_name(nm) {}

int Sword::getPower() const {
    return sword_dam;
}

string Sword::getName() const {
    return sword_name;
}

void Sword::setPower(int pwr) {
    sword_dam = pwr;
}

void Sword::setName(const string& nm) {
    sword_name = nm;
}

// This method will deal damage to the opponent
void Sword::dealDamage(Character &opponent) {
    if (this->sword_name == "Normal Sword") {
        damage(5);
        cout << "You used your " << sword_name << " dealing " << sword_dam << " damage!" << endl;
    }
    else if (this->sword_name == "Better Sword") {
        damage(10);
        cout << "You used your " << sword_name << " dealing " << sword_dam << " damage!" << endl;
    }
    else if (this->sword_name == "Greatest Sword") {
        damage(15);
        cout << "You used your " << sword_name << " dealing " << sword_dam << " damage!" << endl;
    }

    opponent.takeDamage(sword_dam); 
}

void Sword::damage(int amount) {
    sword_dam = amount;
}