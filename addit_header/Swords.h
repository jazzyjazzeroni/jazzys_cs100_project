#ifndef SWORDS_H
#define SWORDS_H
#include <string>
<<<<<<< HEAD
#include "../Character_header/Character.h"
#include "Object.h"
=======
// #include "../Character_header/Character.h"
#include "Object.h"
// #include "../Character_header/Character.h"
#include <iostream>
#include <string>

>>>>>>> master
using namespace std;

class Sword : public Object {
private:
int type;
<<<<<<< HEAD
    int sword_dam;
    string sword_name;
=======
    int sword_dam{};
    string sword_name{};
>>>>>>> master

public:
Sword();
    Sword(int pwr, const string& nm);
    string getType() const override ;
    int getPower() const;
    string getName() const;
    void setPower(int pwr);
    void setName(const string& nm);
    // void dealDamage(Character &);
    void damage(int amount); // declare damage method
    // todo add print
    void print() const override;
};

#endif