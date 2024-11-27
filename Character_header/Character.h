#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;


enum CharType{MAINCHAR, GOBLIN, DRAGON};
const int MAX_HEALTH = 200;

class Character{
protected:
int health;
int attack_amount;
int damage_amount;
string name;
CharType type;

public:
Character(){};
Character(CharType, const string &, int, int){};

int getHealth () const {return health;};
CharType getType() {return type;};
virtual void setHealth(int)= 0;
virtual bool isalive() const =0;
virtual void damage(int dam) = 0;
virtual void takeDamage(int) = 0 ;
virtual void attack(Character &) = 0;

};
#endif