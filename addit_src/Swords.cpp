#include "../addit_header/Swords.h"
#include <iostream>
#include <string>
using namespace std;


//int sword_dam;
//string name;

   Sword::Sword() {
    sword_dam = 0;
    sword_name = "";
   }

    Sword::Sword(int pwr, const string& nm) {
        sword_dam = pwr;
        sword_name = nm;
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

    // void Sword::damage(int amount) { needs to be implemented

    void Sword::dealDamage() {
        if (this->sword_name == "Normal Sword") {
            damage(sword_dam);
            cout << "You used your " << sword_name << "!" << endl;
        }
        else if (this->sword_name == "Better Sword") {
            damage(sword_dam);
            cout << "You used your " << sword_name << "!" << endl;
        }
        else if (this->sword_name == "Greatest Sword") {
            damage(sword_dam);
            cout << "You used your " << sword_name << "!" << endl;
        }
    }