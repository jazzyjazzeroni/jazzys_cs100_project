#include <string>
#include <iostream>
using namespace std;
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum CharType{MAINCHAR, GOBLIN, DRAGON, NPC};
const double MAX_HEALTH = 200.0;

class Character{
protected:
double health;
double attackAmount;
double damage_amount;
string name;
CharType type;

public:
Character::Character();
double getHealth () const;
virtual void setHealth(double) =0;
virtual bool isalive() const =0;
Character(CharType, const string &, double, double);
virtual void damage(double dam) = 0;
virtual void takeDamage(double) = 0 ;
virtual void displayStats() =0 ;
virtual void attack(Character &) = 0;

};
#endif