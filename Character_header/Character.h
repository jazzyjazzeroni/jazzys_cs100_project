
#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <string>
#include <iostream>
#include "../addit_headers/Object.h"
using namespace std;

enum CharType{MAINCHAR, GOBLIN, DRAGON, NPC};
const int MAX_HEALTH = 200;

class Character : public Object {
protected:
int health;
int attackAmount;
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