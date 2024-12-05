#include "../addit_header/Swords.h"

using namespace std;
Sword::Sword() : Object("sword", 0), sword_dam(0), sword_name("Unnamed Sword") {}

    Sword::Sword(int pwr, const string& nm) : Object("sword", pwr), sword_dam(pwr), sword_name(nm) {};
    string Sword::getType() const {
        return "Sword";
    }

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

void Sword::damage(int amount) {
    sword_dam = amount;
}

void Sword::print() const {
    cout << "Name: " << sword_name << ", Value: " << sword_dam << endl;
}
