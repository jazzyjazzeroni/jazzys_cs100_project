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

// void Sword::dealDamage(Character &opponent) {
//     if (this->sword_name == "Normal Sword") {
//         damage(5);
//         cout << "You used your " << sword_name << " dealing " << sword_dam << " damage!" << endl;
//     }
//     else if (this->sword_name == "Better Sword") {
//         damage(10);
//         cout << "You used your " << sword_name << " dealing " << sword_dam << " damage!" << endl;
//     }
//     else if (this->sword_name == "Greatest Sword") {
//         damage(15);
//         cout << "You used your " << sword_name << " dealing " << sword_dam << " damage!" << endl;
//     }

//     opponent.recieveDamage(sword_dam); 
// }

void Sword::damage(int amount) {
    sword_dam = amount;
}

void Sword::print() const {
    cout << "Name: " << sword_name << ", Value: " << sword_dam << endl;
}

int main() {
    Sword sword1(10, "Excalibur");
    cout << "Sword Name: " << sword1.getName() << endl;
    cout << "Sword Power: " << sword1.getPower() << endl;
    return 0;
}
