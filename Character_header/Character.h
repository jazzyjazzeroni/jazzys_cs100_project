
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
Character();
Character(CharType, const string &, int, int, int);

int getHealth () const;
CharType getType();
 void setHealth(int);
 bool isalive() const ;
 void damage(int dam) ;
 void takeDamage(int) ;
virtual void attack(Character &);

};
#endif