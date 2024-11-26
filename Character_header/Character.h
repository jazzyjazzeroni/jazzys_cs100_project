
#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;

enum CharType{MAINCHAR, GOBLIN, DRAGON, NPC};
const double MAX_HEALTH = 200.0;

class Character : public Object {
protected:
double health;
double attackAmount;
double damage_amount;
string name;
CharType type;

public:
Character(){};
Character(CharType, const string &, double, double){};

double getHealth () const {return health;};
CharType getType() {return type;};
virtual void setHealth(double)= 0;
virtual bool isalive() const =0;
virtual void damage(double dam) = 0;
virtual void takeDamage(double) = 0 ;
virtual void attack(Character &) = 0;

};
#endif