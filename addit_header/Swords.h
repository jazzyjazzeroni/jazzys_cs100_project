#ifndef SWORDS_H
#define SWORDS_H
#include <string>
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class Sword : public Object {
private:
int type;
    int sword_dam{};
    string sword_name{};

public:
Sword();
    Sword(int pwr, const string& nm);
    string getType() const override ;
    int getPower() const;
    string getName() const;
    void setPower(int pwr);
    void setName(const string& nm);
    void damage(int amount);
    void print() const override;
};

#endif