#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
using namespace std; 

class Goblin : public Character {
private:
    int specialPower;
    string type; // "character" | "sword" | "potion" | "empty"
    int value; // 0 | 5 | 10 | 15
    

public:
    Goblin(const string &name, double health, double attackStrength, int specialPower, const string &allegiance);

    void attack(Character &opponent) override;
    void SpecialAttack(int);

    Goblin();
    Goblin(const string& type, int value);

    string getType() const;
    void setType(const string& newType);
    int getValue() const;
    void setValue(int newValue);
    void print() const;
    
};

#endif