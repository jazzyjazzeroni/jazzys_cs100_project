#ifndef SWORDS_H
#define SWORDS_H
#include <string>
#include "../Character_header/Character.h"
#include "Object.h"
using namespace std;

class Sword : public Object {
private:
int type;
    int sword_dam;
    string sword_name;

public:
    Sword(int pwr, const string& nm);
    string getType() const override ;
    int getPower() const;
    string getName() const;
    void setPower(int pwr);
    void setName(const string& nm);
    void dealDamage(Character &);
    void damage(int amount); // declare damage method
    // todo add print
    void print() const override;
};

#endif