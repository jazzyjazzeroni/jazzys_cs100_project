#ifndef SWORD_H
#define SWORD_H
#include <string>
#include "Inventory.h"


using namespace std;

class Sword : public Object {
private:
    int power;
    string name;

public:
    Sword(){};
    // Sword(int pwr = 0, const string& nm = "Default Sword");
    Sword(int pwr, const string& nm){};

    int getPower() const{};
    string getName() const{};
    void setPower(int pwr){};
    void setName(const string& nm){};
};

#endif