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

class Character : public virtual Object {
protected:
string name;
    int health;
    CharType type;
    int attackAmount;
    Powers powers;
    Powers currentElement;
// Level level;

public:
Character() {}
    Character(CharType type, const string &name, int health, int damage, const string &element);
virtual ~Character() = default;
    virtual void print() const = 0;
    int getHealth() const;
    string getType() const;
    // string getType() const ;
    void setHealth(int);
    bool isalive() const;
    void receiveDamage(int);
    Powers getCurrentElement() const;
    virtual void attack(Character &);
    Powers getPower() const;

    static string charTypeToString(CharType type);
        // void updateElementForLevel();  // If you have Level class
};
#endif

