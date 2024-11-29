#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <string>
#include <iostream>
#include "../addit_header/Object.h"
#include "../addit_header/Powers.h"
// #include "../addit_header/Level.h"
using namespace std;

enum CharType{MAINCHAR, GOBLIN, DRAGON};
const int MAX_HEALTH = 200;

class Character : public Object {
protected:
int health;
int attackAmount;
int damage_amount;
string name;
CharType type;
Powers powers;
Power_type currentElement;
// Level level;

public:
Character(CharType, const string&, int, int ,int);
int getHealth() const;
string getType() const;
void setHealth(int);
bool isalive() const;
Character(CharType, const string &, int, int);
 void receiveDamage(int);
 void updateElementForLevel(); // Updates element based on current level
    Power_type getCurrentElement() const;
virtual void attack(Character &);
 static string charTypeToString(CharType type) ;
};
#endif