#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
using namespace std;


enum CharType{MAINCHAR, GOBLIN, DRAGON};
const double MAX_HEALTH = 200.0;

class Character{
protected:
double health;
double attack_amount;
double damage_amount;
string name;
CharType type;

public:
Character::Character();
double getHealth () const;
CharType getType();
void setHealth(double);
bool isalive() const ;
Character(CharType, const string &, double, double);
void damage(double dam);
void takeDamage(double);
void attack(Character &);

};
#endif