#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"
using namespace std; 

class Dragon : public Character {
private:
    string allegiance;
    char move;

public:
    Dragon(const string &name, double health, double attackStrength, const string &allegiance);

    void attack(Character &opponent) override;
    void WitchInteraction();
    char getMovement();
   void setMovement(char);

};

#endif