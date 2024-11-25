#include <string>
#include <iostream>
using namespace std;
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum CharType{MAINCHAR, GOBLIN, DRAGON, NPC};
const int MAX_HEALTH = 200;

class Character{
protected:
int health;
int attackAmount;
int damage_amount;
string name;
CharType type;

public:
Character::Character();
virtual int getHealth () const =0;
virtual CharType getType() =0;
 virtual void setHealth(int);
virtual bool isalive() const =0;
Character(CharType, const string &, int, int);
virtual void damage(int dam) = 0;
virtual void takeDamage(int) = 0 ;
virtual void attack(Character &) = 0;

};
#endif