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
double getHealth () const;
void setHealth(double);
bool isalive() const;
Character(CharType, const string &, double, double);
void damage(double dam);
void takeDamage(double);
virtual void displayStats();
virtual void attack(Character &) = 0;

};
#endif