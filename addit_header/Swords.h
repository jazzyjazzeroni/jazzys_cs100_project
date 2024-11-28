#ifndef SWORD_H
#define SWORD_H
#include <string>
#include "../Character_header/Character.h"
#include "Object.h"
using namespace std;

class Sword : public Object {
private:
    int sword_dam;
    string sword_name;

public:
    Sword();
    Sword(int pwr, const string& nm);

    int getPower() const;
    string getName() const;
    void setPower(int pwr);
    void setName(const string& nm);
    void dealDamage(Character &);
    void damage(int amount); // declare damage method
    void print() const override;
};

#endif