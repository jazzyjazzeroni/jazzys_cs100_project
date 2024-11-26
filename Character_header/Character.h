#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
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
Character::Character();
int getHealth () const;
CharType getType();
void setHealth(int);
bool isalive() const ;
Character(CharType, const string &, int, int, int);
void damage(int dam);
void takeDamage(int);
void attack(Character &);

};
#endif