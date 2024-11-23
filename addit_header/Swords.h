#include <string>
#include "Inventory.h"
#ifndef SWORD_H
#define SWORD_H

using namespace std;

class Sword : public Inventory {
private:
    int power;
    string name;
    string type; // "character" | "sword" | "potion" | "empty"
    int value; // 0 | 5 | 10 | 15

public:
    Sword();
        Sword(int pwr = 0, const string& nm = "Default Sword");
    Sword(int pwr, const string& nm);

    int getPower() const;
    string getName() const;
    void setPower(int pwr);
    void setName(const string& nm);

    Sword(const string& type, int value);
    string getType() const;
    void setType(const string& newType);
    int getValue() const;
    void setValue(int newValue);
    void print() const;
};

#endif