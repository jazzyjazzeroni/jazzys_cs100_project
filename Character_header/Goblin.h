#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
using namespace std; 

class Goblin : public Character {
private:
    string allegiance;
    char move;

public:
    Goblin(const string &name, double health, double attackStrength, const string &allegiance);

    void attack(Character &opponent) override;
    void WitchInteraction();
    char getMovement();
   void setMovement(char);

};

#endif