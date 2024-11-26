
#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <string>
#include <iostream>
#include "../addit_header/Object.h"
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
Character::Character();
virtual int getHealth() const = 0;
virtual CharType getType() = 0;
virtual void setHealth(int) = 0;
virtual bool isalive() const = 0;
Character(CharType, const string &, int, int);
virtual void dealtDamage(int) = 0;
virtual void recieveDamage(int) = 0;
virtual void attack(Character &) = 0;

};
#endif