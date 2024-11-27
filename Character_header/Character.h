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
Character::Character(CharType,const string &, int, int ,int);
int getHealth() const;
CharType getType();
void setHealth(int);
bool isalive() const;
Character(CharType, const string &, int, int);
virtual void dealtDamage(int) = 0;
virtual void recieveDamage(int) = 0;
virtual void attack(Character &) = 0;

};
#endif